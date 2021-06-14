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

	// ʹ�ÿ��Ӿ�������
	bool use() throw(std::system_error)
	{
		try {
			return _mutex.try_lock();
		}
		catch (std::system_error& e) {
			throw e;
		}
	}
	// ���¿��Ӿ��ǽ���
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
	out << " ����: " << chopsticks._i << " ";
	return out;
}

class Philosopher
{
	int _i;
	// ��ĳ������
	bool _take(Chopsticks& chopsticks)
	{
		if (chopsticks.use()) {
			std::lock_guard<std::mutex> lock(outputMutex);
			std::cout << "��ѧ��: " << _i << "�õ�" << chopsticks << std::endl;
			fflush(stdout);
			return true;
		}
		else {
			std::lock_guard<std::mutex> lock(outputMutex);
			std::cout << "����ʧ��, ��ѧ��: " << _i << chopsticks << std::endl;
			fflush(stdout);
			return false;
		}
	}
	// ����
	void _seizure(Chopsticks& lc, Chopsticks& rc)
	{
		while (true)
		{
			{
				std::lock_guard<std::mutex> lock(outputMutex);
				std::cout << "��ѧ��: " << _i << " ��ʼ������..." << std::endl;
				fflush(stdout);
			}
			// ������ߣ������ұ�
			if (_take(lc)) {
				if (_take(rc)) {
					std::lock_guard<std::mutex> lock(outputMutex);
					std::cout << "��ѧ��: " << _i << "�Է�" << std::endl;
					std::cout << "��ѧ��: " << _i << "����" << rc << std::endl;
					fflush(stdout);
					rc.push_down();
				}

				std::lock_guard<std::mutex> lock(outputMutex);
				std::cout << "��ѧ��: " << _i << "����" << lc << std::endl;
				fflush(stdout);
				lc.push_down();
			}
			// ��Ϣ1s
			int time = rand() % 5;
			std::this_thread::sleep_for(std::chrono::duration<int>(time));
		}
	}

public:
	explicit Philosopher() : _i(0) {}
	void seti(int i) { _i = i; }
	// �ɵ��õ�	
	void operator() (Chopsticks& lc, Chopsticks& rc)
	{
		_seizure(lc, rc);
	}
};

void ini()
{
	// 5����ѧ�ң�5������	
	std::vector<Philosopher> philosophers(5);
	std::vector<Chopsticks> chopsticks(5);
	std::vector<std::thread> threads;

	// �������	
	for (int i = 0; i < 5; ++i) {
		philosophers.at(i).seti(i + 1);
		chopsticks.at(i).seti(i + 1);
	}
	// �����߳�	
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
