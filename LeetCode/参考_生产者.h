#pragma once
#include <iostream>
#include <mutex>
#include <thread>

#ifdef _MSC_VER
#include <windows.h>	// windows
#else
#include <unistd.h>		// linux
#endif

// ��ƽ̨����ʱ����:����
void mySleep(int milliseconds) {
#ifdef _MSC_VER
	Sleep(milliseconds);
#else
	sleep(milliseconds);
#endif
}


const int kProduceItems = 20;	// �ƻ������Ĳ�Ʒ����
const int kRepositorySize = 5;	// �ֿ��С

								// �ֿ���
template<class T>
class Repository {
public:
	T items_buff[kRepositorySize];			// ����ʵ�ֻ��ζ���

	std::mutex mtx;							// �����������߻�����
	std::mutex produce_mutex;				// ��������������
	std::mutex consume_mutex;				// ���Ѽ���������
	std::condition_variable repo_not_full;	// �ֿⲻ����������
	std::condition_variable repo_not_empty;	// �ֿⲻ����������

	size_t produce_item_count;				// ������������
	size_t consume_item_count;				// ������������
	size_t produce_position;				// ��һ��������λ��
	size_t consume_position;				// ��һ�����ѵ�λ��

	Repository() {
		produce_item_count = 0;
		consume_item_count = 0;
		produce_position = 0;
		consume_position = 0;
	};
};

// ������
template<class T>
class Factory {
private:
	Repository<T> repo;

	// �������õĲ�Ʒ����ֿ�
	void ProduceItem(Repository<T> &repo, T item) {
		std::unique_lock<std::mutex> lock(repo.mtx);
		// +1 ���жϣ���Ϊ�ڳ�ʼʱ������λ��ͬһλ�ã���˲ֿ��������� kRepositorySize-1 ����Ʒ��
		while ((repo.produce_position + 1) % kRepositorySize == repo.consume_position) {
			std::cout << "Repository is full, waiting..." << std::endl;
			repo.repo_not_full.wait(lock);			// ����ʱ�ͷ�����������ʱ�����
		}
		repo.items_buff[repo.produce_position++] = item;
		if (repo.produce_position == kRepositorySize)
			repo.produce_position = 0;
		repo.repo_not_empty.notify_all();			// ����������������Ľ���
		lock.unlock();
	}

	// �Ӳֿ�����ȡһ����Ʒ
	T ConsumeItem(Repository<T> &repo) {
		std::unique_lock<std::mutex> lock(repo.mtx);
		while (repo.consume_position == repo.produce_position) {
			std::cout << "Repository is empty, waiting ..." << std::endl;
			repo.repo_not_empty.wait(lock);			// ����ʱ�ͷ�����������ʱ�����
		}
		T data = repo.items_buff[repo.consume_position++];
		if (repo.consume_position == kRepositorySize)
			repo.consume_position = 0;
		repo.repo_not_full.notify_all();			// �����������������Ľ���
		lock.unlock();
		return data;
	}

public:
	void ProduceTask() {
		bool ready_to_exit = false;
		while (true) {

			std::unique_lock<std::mutex> lock(repo.produce_mutex);

			if (repo.produce_item_count < kProduceItems) {		// �����߳�����
				repo.produce_item_count++;

				// ������Ʒ�����
				//----------------------------------------------------
				mySleep(100);		// ģ�����Ѳ�Ʒ��Ҫ��ʱ�䣬ʵ�������в���Ҫ
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

			if (repo.consume_item_count < kProduceItems) {		// �����߳�����
				T item = ConsumeItem(repo);

				// ���Ѳ�Ʒ�����
				//----------------------------------------------------
				mySleep(100);		// ģ�����Ѳ�Ʒ��Ҫ��ʱ�䣬ʵ�������в���Ҫ
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

