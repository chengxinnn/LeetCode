#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef enum FIGHTER_TYPE
{
	F_J11,
	F_J20,
	others
};

class Fighter
{
public:
	virtual void gettype() = 0;
};

class J11 : public Fighter
{
public:
	J11() :Fighter(), mytype("J11") {}
	void gettype()
	{
		cout << mytype << " is comming " << endl;
	}
private:
	string mytype;
};
class J20 :public Fighter
{
public:
	J20() : Fighter(), mytype("J20") {}
	void gettype()
	{
		cout << mytype << " is comming " << endl;
	}

private:
	string mytype;
};

class FighterFactory
{
public:
	virtual Fighter * createFighter() = 0;
};

class FighterJ11Factory : public FighterFactory
{
public:
	FighterJ11Factory() :FighterFactory() {}
	Fighter * createFighter()
	{
		return new J11();
	}
};
class FighterJ20Factory: public FighterFactory
{
public:
	FighterJ20Factory() : FighterFactory() {}
	Fighter * createFighter()
	{
		return new J20();
	}
};

void ini()
{
	FighterFactory * f1 = new FighterJ11Factory();
	Fighter * aj11 = f1->createFighter();

	FighterFactory * f2 = new FighterJ20Factory();
	Fighter * aj20 = f2->createFighter();
	aj11->gettype();
	aj20->gettype();
}