#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

class a{
public:

	int x;
	shared_ptr<int>ptr{ new int{ 3 } };
	a() { x = 0; };
	a(int xx) :x(xx) {};
	~a() { cout <<"\t" <<  x << "�Ѿ��ݻ� " << endl; }
	vector<int>mvec() { return vector<int>{0, 1}; };
};

void ini()
{
	//============shared_ptrָ���������==============//
	cout << "�����������ڵ�sharedָ���������� �� " << endl;
	if(1)
		shared_ptr<a> p2a(new a[10](), [](a * p) {delete[] p; });


	cout << endl << endl << "����ָ��������Ԫ��: " << endl;
	shared_ptr<int>ip(new int[6](), [](int * p) {delete p; });
	int* nums = ip.get();
	for (int i = 0; i < 6; i++)
		cout << nums[i] << " ";
	cout << endl;

	//=============weak_ptrֻ���ʣ�lock����shared�����Ӽ���=============
	cout << endl << endl << "weakָ��ָlock��ļ������: " << endl;
	shared_ptr<string> p(new string("12314"));
	weak_ptr<string> w(p);
	cout << w.use_count() << endl;
	if (shared_ptr<string >x = w.lock())
	{
		cout << w.use_count() << "   " << x.use_count() << endl;

	}
	cout << w.use_count()  << endl;

	//========================unique_ptr��̬����=======================//
	cout << endl;
	vector<int>vec({ 23,34,234,2,42,4,23,4,2,4 });
	int n = vec.size();
	unique_ptr<int[]>sum(new int[n]());
	for_each(sum.get(), sum.get() + n, [](int x) {cout << x << "  "; });


	//========================�б��ʼ��=======================//
	unique_ptr<int> pppp(new int{ 20 });
	cout << endl << endl << endl;
}