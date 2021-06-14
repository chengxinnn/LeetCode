#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef enum
{
	fj11,
	fj20,
	fjnum

}fightertype;

//战斗机类
class fighter
{
public:
	virtual string  ftype() = 0;
};

class J11 : public fighter
{
public:
	J11() :fighter(), mytype("J11") {}
	string ftype()
	{
		cout << mytype << " is coming " << endl;
		return mytype;
	}
private:
	string mytype;
};

class J20 : public fighter
{
public:
	J20() : fighter(), mytype("J20") {}
	string ftype()
	{
		cout << mytype << " is coming" << endl;
		return mytype;
	}
private:
	string mytype;
};

class FighterFactory
{
public:
	fighter * creatFighter(fightertype type)
	{
		switch (type)
		{
		case fj11: return new J11();
		case fj20: return new J20();
		default:
			return nullptr;
		}
	}
};

void ini()
{
	FighterFactory * f = new FighterFactory();
	fighter * aj11 = f->creatFighter(fj11);
	aj11->ftype();
	fighter * aj20 = f->creatFighter(fj20);
	aj20->ftype();

	/**************************/
	// 面试过程中尤其要注意防止内存泄漏。
	delete f;
	f = nullptr;
	delete aj11;
	aj11 = nullptr;
	delete aj20;
	aj20 = nullptr;
}