#pragma once

#include <iostream>

using namespace std;

class base
{
public:
	int x;
	int y;
	virtual int foob1() { cout << "base1" << endl; return 0; };
	virtual int foob2() { cout << "base2" << endl; return 0; };
	base() {};
};

class derive :public base
{
public:
	int z;
	virtual int foob1() { cout << " derive" << endl; return 0; };
	derive() {};
};

void ini()
{
	base b = base();
	derive d = derive();

	base* t = new base();
	t->foob1();
	t = new derive();
	t->foob1();
}