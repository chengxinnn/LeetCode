#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef enum INFO 
{
	STORAGE,
	TAKE,
	OTHER
};

class Message
{
public:
	Message() = delete;
	Message(INFO infoo, int n) : count(n), info(infoo){  }
	int getCount() { return count; }
	int getInfo() { return info; }
	static void addCount(int x) { total += x; }
	static void subCount(int x) { total -= x; }
	static int getTotal() { return total; };


private:
	int count;
	INFO info;
	static int total;
};
int Message::total = 100;

class Handler
{
public:
	Handler() = delete;
	Handler(int a,string n, Handler* ne = nullptr) :  ability(a),  name(n), next(ne){}
	virtual void handleRequest(Message * msg) = 0;
	string getName() { return name; }
	int getAb() { return ability; }
	void setNext(Handler * n) { next = n; };


private:
	int ability;
	string name;
protected:
	Handler * next;



};

class Handler1 : public Handler
{
public:
	Handler1() = delete;
	Handler1(string n, int a) : Handler(a, n) {};
	void handleRequest(Message * msg)
	{
		if (msg->getCount() <= getAb())
		{
			switch (msg->getInfo())
			{
			case STORAGE:
				msg->addCount(msg->getCount());
				cout << getName() << " has handle this msg. the latest num is " << msg->getTotal() << endl ;
				break;
			case TAKE:
				msg->subCount(msg->getCount());
				cout << getName() << " has handle this msg. the latest num is " << msg->getTotal() << endl;
				break;
			default:
				break;
			}
		}
		else
		{
			cout << getName() << " can not handle this msg and pass it to the next"  <<endl;
			if(next != nullptr)
				next->handleRequest(msg);
		}

	}
	
};

void ini()
{
	Message *msg = new Message(STORAGE, 101);
	Handler * h1 = new Handler1("handler1", 50);
	Handler * h2 = new Handler1("handler2", 60);
	Handler * h3 = new Handler1("handler3", 80);
	Handler * h4 = new Handler1("handler4", 100);

	h1->setNext(h2);
	h2->setNext(h3);
	h3->setNext(h4);

	h1->handleRequest(msg);




}