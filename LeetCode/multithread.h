#pragma once
#include <thread>
#include <atomic>
#include <iostream>
#include <Windows.h>
using namespace std;


void ini()
{
	thread t1([]()
	{
		for (int i = 0; i < 3; i++)
			cout << "thread 1 print" << i << endl;
	});

	Sleep(1000);
	thread t2([]()
	{
		for (int i = 0; i < 3; i++)
			cout << "thread 2 print" << i << endl;
	});
	
	cout << "t1 还没有执行" << endl;
	cout << "t2 还没有执行" << endl;
	
	t1.join();
	t2.join();

	cout << "t1 start" << endl;
	cout << "t2 start" << endl;

	int i;
	cin >> i;

}