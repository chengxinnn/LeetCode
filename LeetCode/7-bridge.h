#pragma once
#include <iostream>
#include <string>
using namespace std;

class Implemention
{
public:
	virtual void run() = 0;
	virtual string  getName() = 0;
};

class Abstraction
{
public:
	Abstraction() { app = nullptr; }
	virtual void runapp() = 0;
	virtual void setapp(Implemention * a) = 0;
	
protected:
	Implemention * app;
};


class App : public Implemention
{
public:
	App() = delete;
	App(string n) : Implemention() { name = n; }
	void run()
	{
		cout << name << " is runing " << endl;
	}
	string getName()
	{
		return name;
	}
private:
	string name;
};


class Phone : public Abstraction
{
public:
	Phone() = delete;
	Phone(string n) :Abstraction(){name = n;}
	void runapp()
	{
		if (app != nullptr)
			app->run();
	}

	void setapp(Implemention * a)
	{
		app = a;
	}

	
private:
	string name;
};

void ini()
{
	Implemention * app1 = new App("store");
	Implemention * app2 = new App("game");
	Abstraction * hua = new Phone("huawei");
	hua->setapp(app1);
	hua->runapp();
	hua->setapp(app2);
	hua->runapp();

	delete app1;
	delete app2;
	delete hua;
	app1 = nullptr;
	app2 = nullptr;
	hua = nullptr;

}