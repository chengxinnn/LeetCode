#pragma once
#include <iostream>
#include <exception>
#include <mutex>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <thread>
#include <chrono>

std::mutex outputMutex;

class Chopsticks
{
	int _i;
	std::mutex _mutex;

public:
	explicit Chopsticks() : _i(0) {}
	void seti(int i) { _i = i; }

	friend std::ostream& operator <<(std::ostream& out, const Chopsticks& chopsticks);

	// 使用筷子就是上锁
	bool use() throw(std::system_error)
	{
		try {
			return _mutex.try_lock();
		}
		catch (std::system_error& e) {
			throw e;
		}
	}
	// 放下筷子就是解锁
	void push_down() throw(std::system_error)
	{
		try {
			return _mutex.unlock();
		}
		catch (std::system_error& e) {
			throw e;
		}
	}
};

std::ostream& operator <<(std::ostream& out, const Chopsticks& chopsticks)
{
	out << " 筷子: " << chopsticks._i << " ";
	return out;
}

class Philosopher
{
	int _i;
	// 拿某个筷子
	bool _take(Chopsticks& chopsticks)
	{
		if (chopsticks.use()) {
			std::lock_guard<std::mutex> lock(outputMutex);
			std::cout << "哲学家: " << _i << "拿到" << chopsticks << std::endl;
			fflush(stdout);
			return true;
		}
		else {
			std::lock_guard<std::mutex> lock(outputMutex);
			std::cout << "抢夺失败, 哲学家: " << _i << chopsticks << std::endl;
			fflush(stdout);
			return false;
		}
	}
	// 抢夺
	void _seizure(Chopsticks& lc, Chopsticks& rc)
	{
		while (true)
		{
			{
				std::lock_guard<std::mutex> lock(outputMutex);
				std::cout << "哲学家: " << _i << " 开始抢筷子..." << std::endl;
				fflush(stdout);
			}
			// 先拿左边，在那右边
			if (_take(lc)) {
				if (_take(rc)) {
					std::lock_guard<std::mutex> lock(outputMutex);
					std::cout << "哲学家: " << _i << "吃饭" << std::endl;
					std::cout << "哲学家: " << _i << "放下" << rc << std::endl;
					fflush(stdout);
					rc.push_down();
				}

				std::lock_guard<std::mutex> lock(outputMutex);
				std::cout << "哲学家: " << _i << "放下" << lc << std::endl;
				fflush(stdout);
				lc.push_down();
			}
			// 休息1s
			int time = rand() % 5;
			std::this_thread::sleep_for(std::chrono::duration<int>(time));
		}
	}

public:
	explicit Philosopher() : _i(0) {}
	void seti(int i) { _i = i; }
	// 可调用的	
	void operator() (Chopsticks& lc, Chopsticks& rc)
	{
		_seizure(lc, rc);
	}
};

void ini()
{
	// 5个哲学家，5个筷子	
	std::vector<Philosopher> philosophers(5);
	std::vector<Chopsticks> chopsticks(5);
	std::vector<std::thread> threads;

	// 设置序号	
	for (int i = 0; i < 5; ++i) {
		philosophers.at(i).seti(i + 1);
		chopsticks.at(i).seti(i + 1);
	}
	// 开启线程	
	for (int i = 0; i < 4; ++i) {
		std::thread thread(philosophers.at(i), std::ref(chopsticks.at(i)), std::ref(chopsticks.at(i + 1)));
		threads.push_back(std::move(thread));
	}
	std::thread thread(philosophers.at(4), std::ref(chopsticks.at(4)), std::ref(chopsticks.at(0)));
	threads.push_back(std::move(thread));

	std::for_each(threads.begin(), threads.end(), [](std::thread& t) {
		t.join();
	});

}
