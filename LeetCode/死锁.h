#pragma once
#include <mutex>
#include <thread>
#include <iostream>

using namespace std;

int a = 1;
int b = 2;

mutex ma, mb;

void funca()
{
	mb.lock();
	b++;
	this_thread::sleep_for(chrono::duration<int, milli>(1));
	ma.lock();
	a += b;
	cout << "a " << a << endl;
	ma.unlock();
	mb.unlock();
}

void funcb()
{
	ma.lock();
	a++;
	this_thread::sleep_for(chrono::duration<int, milli>(1));
	mb.lock();
	b += a;
	cout << "b " << b << endl;
	mb.unlock();
	ma.unlock();
}


void ini()
{
	thread t1 = thread(funca);
	thread t2 = thread(funcb);
	t1.join();
	t2.join();

}

