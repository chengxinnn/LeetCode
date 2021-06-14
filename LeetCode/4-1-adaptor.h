#pragma once
#include <iostream>

using namespace  std;

class Deque
{
public:
	void push_back(int x)
	{
		cout << "Deque push_back:" << x << endl;
	}
	void push_front(int x)
	{
		cout << "Deque push_front:" << x << endl;
	}
	void pop_back()
	{
		cout << "Deque pop_back" << endl;
	}
	void pop_front()
	{
		cout << "Deque pop_front" << endl;
	}
};
class Sequence
{
public:
	virtual void push(int x) = 0;
	virtual void pop() = 0;
};

class Stack :public Sequence, private Deque
{
public:
	void push(int x)
	{
		push_front(x);
	}
	void pop()
	{
		pop_front();
	}
};
class Queue :public Sequence, private Deque
{
public:
	void push(int x)
	{
		push_back(x);
	}
	void pop()
	{
		pop_front();
	}
};
void ini()
{
	Queue q;
	q.push(1);
}