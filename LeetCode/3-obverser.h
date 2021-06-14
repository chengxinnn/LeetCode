#pragma once
#include <iostream>
#include <list>
#include <string>

//#include "31-observer.h"

typedef enum
{
	HELP,
	GO,
	OTHER
}INFO;


class Observer;

class Subject
{
public:
	~Subject() {};
	virtual void notify(Observer*ob , INFO info) = 0;
	virtual void attach(Observer * ob) = 0;
	virtual void detach(Observer * ob) = 0;
};

class Observer
{
public:
	Observer() {}
	~Observer() {}
	virtual string  getName() { return name; };
	virtual void setName(string n) { name = n; };
	virtual void help() = 0;
	virtual void go() = 0;
	virtual void call(Subject * sb, INFO info) = 0;

private:
	string name;
};

class Player : public Observer
{
public:
	Player(string n) : Observer() {
		setName(n);
	}
	~Player(){ }
	void call(Subject * sb, INFO info)
	{
		switch (info)
		{
		case HELP:
			cout << getName() << ":\tHELP ME --" << endl;
			break;
		case GO:
			cout << getName() << ":\tFOLLOW ME --" << endl;
			break;
		default:
			break;
		}
		sb->notify(this, info);
	}
private:
	void help()
	{
		cout << getName() << ":\tis coming to help" << endl;
	}
	void go()
	{
		cout << getName() << ":\tis following" << endl;
	}
};

class Gamecenter : public Subject
{
public:
	Gamecenter() :max_Player_Num(10), player_Num(0) {};
	~Gamecenter() {};
	void notify(Observer * ob, INFO info)
	{
		switch (info)
		{
		case HELP:
			for each(Observer*name in players)
				if (name != ob)
					name->help();
			break;
		case GO:
			for each(Observer * name in players)
				if (name != ob)
					name->go();
		default:
			break;
		}

	}
	void attach(Observer * ob)
	{
		if (player_Num < max_Player_Num)
			players.push_back(ob);
		else cout << "满员" << endl;
	}

	void detach(Observer * ob)
	{
		players.remove(ob);
	}

private:
	list<Observer*>players;
	const int max_Player_Num;
	int player_Num;

};

void ini()
{
	Subject * center;
	center = new Gamecenter();
	Observer * p1 = new Player("asdf");
	Observer * p2 = new Player("程鑫");
	Observer * p3 = new Player("西门吹雪");
	Observer * p4 = new Player("耿直的秋天");
	Observer * p5 = new Player("string");
	center->attach(p1);
	center->attach(p2);
	center->attach(p3);
	center->attach(p4);
	center->attach(p5);
	center->detach(p5);

	p2->call(center, GO);
	cout << endl;
	p3->call(center, HELP);
	cout << endl;
	p4->call(center, HELP);
	cout << endl;
	p2->call(center, GO);
	cout << endl;


}