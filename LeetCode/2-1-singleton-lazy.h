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
		cout << "创建一个新的实例";
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
	线程不安全
	*/
	thread threads[5];
	for (int i = 0; i < 5; i++)
		threads[i] = thread(&callsingleton);
	for (int i = 0; i < 5; i++)
		threads[i].join();


}