#pragma once
#include <iostream>
#include <mutex>
#include <thread>

#ifdef _MSC_VER
#include <windows.h>	// windows
#else
#include <unistd.h>		// linux
#endif

// 跨平台的延时函数:毫秒
void mySleep(int milliseconds) {
#ifdef _MSC_VER
	Sleep(milliseconds);
#else
	sleep(milliseconds);
#endif
}


const int kProduceItems = 20;	// 计划生产的产品个数
const int kRepositorySize = 5;	// 仓库大小

								// 仓库类
template<class T>
class Repository {
public:
	T items_buff[kRepositorySize];			// 数组实现环形队列

	std::mutex mtx;							// 生产者消费者互斥量
	std::mutex produce_mutex;				// 生产计数互斥量
	std::mutex consume_mutex;				// 消费计数互斥量
	std::condition_variable repo_not_full;	// 仓库不满条件变量
	std::condition_variable repo_not_empty;	// 仓库不空条件变量

	size_t produce_item_count;				// 生产数量计数
	size_t consume_item_count;				// 消费数量计数
	size_t produce_position;				// 下一个生产的位置
	size_t consume_position;				// 下一个消费的位置

	Repository() {
		produce_item_count = 0;
		consume_item_count = 0;
		produce_position = 0;
		consume_position = 0;
	};
};

// 工厂类
template<class T>
class Factory {
private:
	Repository<T> repo;

	// 将生产好的产品放入仓库
	void ProduceItem(Repository<T> &repo, T item) {
		std::unique_lock<std::mutex> lock(repo.mtx);
		// +1 后判断，因为在初始时，两者位于同一位置（因此仓库中最大存在 kRepositorySize-1 个产品）
		while ((repo.produce_position + 1) % kRepositorySize == repo.consume_position) {
			std::cout << "Repository is full, waiting..." << std::endl;
			repo.repo_not_full.wait(lock);			// 阻塞时释放锁，被唤醒时获得锁
		}
		repo.items_buff[repo.produce_position++] = item;
		if (repo.produce_position == kRepositorySize)
			repo.produce_position = 0;
		repo.repo_not_empty.notify_all();			// 唤醒所有因空阻塞的进程
		lock.unlock();
	}

	// 从仓库中拿取一个产品
	T ConsumeItem(Repository<T> &repo) {
		std::unique_lock<std::mutex> lock(repo.mtx);
		while (repo.consume_position == repo.produce_position) {
			std::cout << "Repository is empty, waiting ..." << std::endl;
			repo.repo_not_empty.wait(lock);			// 阻塞时释放锁，被唤醒时获得锁
		}
		T data = repo.items_buff[repo.consume_position++];
		if (repo.consume_position == kRepositorySize)
			repo.consume_position = 0;
		repo.repo_not_full.notify_all();			// 唤醒所有因满阻塞的进程
		lock.unlock();
		return data;
	}

public:
	void ProduceTask() {
		bool ready_to_exit = false;
		while (true) {

			std::unique_lock<std::mutex> lock(repo.produce_mutex);

			if (repo.produce_item_count < kProduceItems) {		// 结束线程条件
				repo.produce_item_count++;

				// 生产产品代码块
				//----------------------------------------------------
				mySleep(100);		// 模仿消费产品需要的时间，实际运用中不需要
				T item = repo.produce_item_count;
				std::cout << "producer id: " << std::this_thread::get_id()
					<< " is producing item:\t[" << item << "]" << std::endl;
				//----------------------------------------------------

				ProduceItem(repo, item);
			}
			else {
				ready_to_exit = true;
			}

			lock.unlock();
			if (ready_to_exit)
				break;
		}
	}

	void ConsumeTask() {
		bool ready_to_exit = false;
		while (true) {
			std::unique_lock<std::mutex> lock(repo.consume_mutex);

			if (repo.consume_item_count < kProduceItems) {		// 结束线程条件
				T item = ConsumeItem(repo);

				// 消费产品代码块
				//----------------------------------------------------
				mySleep(100);		// 模仿消费产品需要的时间，实际运用中不需要
				std::cout << "consumer id: " << std::this_thread::get_id()
					<< " is consuming item:\t[" << item << "]" << std::endl;
				//----------------------------------------------------

				repo.consume_item_count++;
			}
			else {
				ready_to_exit = true;
			}

			lock.unlock();
			if (ready_to_exit)
				break;
		}
	}
};

void ini() {
	std::cout << "Main thread id :" << std::this_thread::get_id() << std::endl;
	class Factory<int> myfactory;
	std::thread producer1(&Factory<int>::ProduceTask, &myfactory);
	std::thread producer2(&Factory<int>::ProduceTask, &myfactory);

	std::thread consumer1(&Factory<int>::ConsumeTask, &myfactory);
	std::thread consumer2(&Factory<int>::ConsumeTask, &myfactory);
	std::thread consumer3(&Factory<int>::ConsumeTask, &myfactory);
	cout << producer1.get_id() << endl;
	cout << producer2.get_id() << endl;
	cout << consumer1.get_id() << endl;
	cout << consumer2.get_id() << endl;
	cout << consumer3.get_id() << endl;


	producer1.join();
	producer2.join();
	consumer1.join();
	consumer2.join();
	consumer3.join();
}

