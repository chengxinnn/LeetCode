#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m;

class singleton
{
public:
	static singleton*getInstance();
	~singleton();
private:
	singleton() {}
	singleton(const singleton & obj) = delete;
	singleton operator = (const singleton & obj) = delete;

	static singleton * ins;
};
singleton * singleton::ins = nullptr;

singleton * singleton::getInstance()
{
	if (ins == nullptr)
	{
		m.lock();
		if (ins == nullptr)
		{
			ins = new singleton();
			cout << "创建一个新的实例" << endl;
		}
		m.unlock();

	}
	return ins;
}

singleton::~singleton()
{
	delete ins;
	ins = nullptr;
}

void callsingleton()
{
	singleton * a = singleton::getInstance();
	cout << this_thread::get_id() << endl;
	return;
}

void ini()
{
	thread threads[5];
	for (int i = 0; i < 5; i++)
		threads[i] = thread(&callsingleton);
	for (int i = 0; i < 5; i++)
		threads[i].join();

}
