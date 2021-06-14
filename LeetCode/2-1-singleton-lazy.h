#pragma once
#include <iostream>
#include <thread>

using namespace std;

class singleton
{
public:
	static singleton * getInstance();
	~singleton();
private:
	singleton() { };
	singleton(const singleton & obj) = delete;
	singleton operator = (const singleton & obj) = delete;

	static singleton * ins;
};

singleton * singleton::ins = nullptr;

singleton * singleton::getInstance()
{
	if (ins == nullptr)
	{
		cout << "����һ���µ�ʵ��";
		ins = new singleton();
	}
	return ins;
}


void callsingleton()
{
	singleton *s = singleton::getInstance();
	cout << this_thread::get_id() << endl;

}

void ini()
{

	/*
	�̲߳���ȫ
	*/
	thread threads[5];
	for (int i = 0; i < 5; i++)
		threads[i] = thread(&callsingleton);
	for (int i = 0; i < 5; i++)
		threads[i].join();


}