#pragma once
#include <iostream>

using namespace std;

/*
��ӡ����ַ
˼·��ȡ��b1��d1�����ͷ4bytes����������ָ�룬���麯��������һ�����麯��ָ���ָ�����飬���������������һ��nullptr��
? ? ?1.��ȡb1�ĵ�ַ��ǿת��һ��int*��ָ�룻
	 2.�ٽ�����ȡֵ����ȡ����b1����ͷ4bytes��ֵ�����ֵ����ָ������ָ�룻
     3.��ǿת��pVtable*����Ϊ������һ�����麯��ָ�����͵����飻
	 4.���ָ�봫�ݸ�PrintVTable���д�ӡ���
	 5.��Ҫ˵�����������ӡ���Ĵ��뾭�����������Ϊ��������ʱ�����Ĵ����ɾ�����������û�з�nullptr������Խ�磬���Ǳ����������⡣����ֻ��Ҫ��Ŀ¼����-����-�������������ٱ���ͺ��ˡ�

*/
typedef void(*pVtable)(void);

void PrintVTable(pVtable vTable[])
{
	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
	cout << " ����ַ>" << vTable << " " << sizeof(vTable) << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x   0X%x,->", i, &vTable[i], vTable[i]);
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
���̳���д
*/
class driv1 : public base1
{
public:
	driv1() {}
	virtual void base1A() { cout << "Deri1::A" << endl; }
	virtual void driv1C() { cout << "Deri1::C" << endl; }
};

/*
���̳�δ��д
*/
class driv2 : public base1
{
public:
	driv2() {}
	virtual void driv2C() { cout << "Deri2::C" << endl; }
	virtual void driv2D() { cout << "Deri2::D" << endl; }
};

/*
��̳���д
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

	cout << " ���̳���д " << endl;
	pVtable* vTabled1 = (pVtable*)(*(int*)&d1);
	PrintVTable(vTabled1);

	cout << " ���̳в���д " << endl;
	pVtable* vTabled2 = (pVtable*)(*(int*)&d2);
	PrintVTable(vTabled2);

	cout << " ��̳���д " << endl;
	pVtable* vTabled3 = (pVtable*)(*(int*)&d3);
	PrintVTable(vTabled3);
	vTabled3 = (pVtable*)(*(int*)((char*)&d3 + sizeof(base1)));
	PrintVTable(vTabled3);
	cout << sizeof(base1);

}