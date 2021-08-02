#pragma once
#include <iostream>

using namespace std;

/*
打印虚表地址
思路：取出b1、d1对象的头4bytes，就是虚表的指针，而虚函数表本质是一个存虚函数指针的指针数组，这个数组最后面放了一个nullptr。
? ? ?1.先取b1的地址，强转成一个int*的指针；
	 2.再解引用取值，就取到了b1对象头4bytes的值，这个值就是指向虚表的指针；
     3.再强转成pVtable*，因为虚表就是一个存虚函数指针类型的数组；
	 4.虚表指针传递给PrintVTable进行打印虚表；
	 5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最后面没有放nullptr，导致越界，这是编译器的问题。我们只需要点目录栏的-生成-清理解决方案，再编译就好了。

*/
typedef void(*pVtable)(void);

void PrintVTable(pVtable vTable[])
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << " " << sizeof(vTable) << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x   0X%x,->", i, &vTable[i], vTable[i]);
		pVtable f = vTable[i];
		f();
	}
	cout << endl;
}


class base1
{
public:
	base1() {}
	virtual void base1A() { cout << "base1::A" << endl; }
	virtual void base1B() { cout << "base1::B" << endl; }
};

class base2
{
public:
	base2() {}
	virtual void base2G() { cout << "base2::G" << endl; }
	virtual void base2H() { cout << "base2::H" << endl; }
};

/*
单继承重写
*/
class driv1 : public base1
{
public:
	driv1() {}
	virtual void base1A() { cout << "Deri1::A" << endl; }
	virtual void driv1C() { cout << "Deri1::C" << endl; }
};

/*
单继承未重写
*/
class driv2 : public base1
{
public:
	driv2() {}
	virtual void driv2C() { cout << "Deri2::C" << endl; }
	virtual void driv2D() { cout << "Deri2::D" << endl; }
};

/*
多继承重写
*/
class driv3 : public base1,public base2
{
public:
	driv3() {}
	virtual void base1A() { cout << "Deri3::A" << endl; }
	virtual void base2G() { cout << "Deri3::G" << endl; }
	virtual void driv3E() { cout << "Deri3::E" << endl; }
};


void ini()
{
	base1 b1;
	base2 b2;
	driv1 d1;
	driv2 d2;
	driv3 d3;

	pVtable* vTableb = (pVtable*)(*(int*)&b1);
	PrintVTable(vTableb);
	pVtable* vTableb1 = (pVtable*)(*(int*)&b2);
	PrintVTable(vTableb1);

	cout << " 单继承重写 " << endl;
	pVtable* vTabled1 = (pVtable*)(*(int*)&d1);
	PrintVTable(vTabled1);

	cout << " 单继承不重写 " << endl;
	pVtable* vTabled2 = (pVtable*)(*(int*)&d2);
	PrintVTable(vTabled2);

	cout << " 多继承重写 " << endl;
	pVtable* vTabled3 = (pVtable*)(*(int*)&d3);
	PrintVTable(vTabled3);
	vTabled3 = (pVtable*)(*(int*)((char*)&d3 + sizeof(base1)));
	PrintVTable(vTabled3);
	cout << sizeof(base1);

}