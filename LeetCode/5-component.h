#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;


/*  ================透明组合模式===================*/
class Component
{
public:
	Component() { name = "none"; }
	Component(string n) { name = n; }
	~Component(){}
	void setName(string n) { name = n; }
	string getName() { return name; }
private:
	string name;
};

class Container:public Component
{
public:
	Container() = delete;
	Container(string n ) : Component(n){}
	~Container() {}
	virtual void add(Component * com) {};
	virtual void remove(Component * com) {};
	virtual void display() { cout << getName() << endl; }
};

class Container1: public Container
{
public:
	Container1(string n ):Container(n){}
	void add(Component * com)
	{
		childs.push_back(com);
		cout << getName() << " has insert " << com->getName() << endl;
	}
	void remove(Component * com)
	{
		childs.remove(com);
		cout << getName() << " has remove " << com->getName() << endl;
	}
	void display()
	{
		cout << "Component in " << this->getName() << " are :" << endl;
		for each(Component * com in childs)
			cout << com->getName() << "   ";
		cout << endl;
	}

private:
	list<Component*>childs;
};

class Leaf : public Component
{
public:
	Leaf(string n) : Component(n) {}
	~Leaf() {}

	void display()
	{
		cout << "Component name is " << this->getName() << endl;
	}
};

void ini()
{
	Container * root = new Container1("root");
	Component * leaf1 = new Leaf("leaf1");
	Component * leaf2 = new Leaf("leaf2");
	Component * leaf3 = new Leaf("leaf3");

	Container* con1 = new Container1("con1");
	Container * con2 = new Container1("con2");
	Container * con3 = new Container1("con3");

	root->add(con1);
	root->add(leaf1);
	con1->add(con2);
	con1->add(leaf2);
	con2->add(con3);
	con2->add(leaf3);

	root->display();
	con1->display();
	con2->display();
	con1->remove(con2);
	con1->display();


}