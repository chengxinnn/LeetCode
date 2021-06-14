#pragma once
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class student {
public:
	int age;
	string name;
	student() {
		age = 0;
		name = "  ";
	}
	student(int agee, string namee) {
		age = agee; name = namee;
	}

	friend bool operator<(const student & a, const student &b) {
		return a.age > b.age;
	}
};

bool funtioncmp(const student&a, const student&b)
{
	return a.age < b.age;
}

auto acmp = [](const student&a, const student &b) {return a.age > b.age; };
auto acmpp = [](const int&a, const int&b) {return a > b; };


int ini()
{
	//���ڻ������� Ĭ���Ǵ󶥶�
	priority_queue<int> a;
	//��ͬ�� priority_queue<int, vector<int>, less<int> > a;

	//             ����һ��Ҫ�пո񣬲�Ȼ���������������
	priority_queue<int, vector<int>, greater<int> > c;  //��������С����
	priority_queue<string> b;



	//Ĭ���Ƕ���
	priority_queue<int> pqq;
	pqq.emplace(1);
	pqq.emplace(3);
	pqq.emplace(5);
	pqq.emplace(2);
	cout << " pqq.top().age   " << pqq.top() << endl;
	pqq.pop();
	cout << " pqq.top().age   " << pqq.top() << endl;;

	priority_queue<int, vector<int>, decltype(acmpp) > pqqq(acmpp);
	pqqq.emplace(10);
	pqqq.emplace(232);

	//ʹ���Դ���operator <  �Ƚ�
	priority_queue<student> first;
	first.emplace(student(10, "ewrwdasfasd"));
	first.emplace(student(0, "zdsfdasfasd"));
	first.emplace(student(230, "mkuhdasfasd"));
	first.emplace(student(42330, "dasdas4234fasd"));
	cout << " first.top().age   " << first.top().age << endl ;

	//ʹ�ú���ָ�����Ƚ�
	priority_queue<student, vector<student>, function< bool(const student&, const student&)>>second(funtioncmp);
	second.emplace(student(510, "ewrwdasfasd"));
	second.emplace(student(0, "zdsfdasfasd"));
	second.emplace(student(1230, "mkuhdasfasd"));
	second.emplace(student(71420, "sdfzcvdasfasd"));
	second.emplace(student(242330, "dasdas4234fasd"));
	cout << " second.top().age   " << second.top().age << endl;

	priority_queue<student, vector<student>, function< bool(const student&a, const student&b)> >third(acmp);
	third.emplace(student(510, "ewrwdasfasd"));
	third.emplace(student(0, "zdsfdasfasd"));
	third.emplace(student(1230, "mkuhdasfasd"));
	third.emplace(student(71420, "sdfzcvdasfasd"));
	third.emplace(student(242330, "dasdas4234fasd"));
	cout << " third.top().age   " << third.top().age << endl;
	third.pop();
	cout << endl;
	cout << " third.top().age   " << third.top().age << endl;


	//ʹ��lambda�������Ƚ�
	/*
	��Ҫ��lambda���ʽ��Ϊ���ȶ��в������г�ʼ��
	�����ƶ�priority_queue��ģ��ʵ�Σ�decltype(cmp)
	������Ϊ��ȷ���ĺ���������
	*/
	priority_queue<student, vector<student>, decltype(acmp)> fourth(acmp);
	fourth.emplace(student(510, "ewrwdasfasd"));
	fourth.emplace(student(0, "zdsfdasfasd"));
	fourth.emplace(student(1230, "mkuhdasfasd"));
	fourth.emplace(student(71420, "sdfzcvdasfasd"));
	fourth.emplace(student(242330, "dasdas4234fasd"));
	cout << " fourth.top().age   " << fourth.top().age << endl;


	//��������
	function<bool(const student&, const student&)>func(funtioncmp);
	priority_queue<student, vector<student>, function<bool(const student&, const student&)>>fifth(func);
	fifth.emplace(student(510, "ewrwdasfasd"));
	fifth.emplace(student(0, "zdsfdasfasd"));
	fifth.emplace(student(1230, "mkuhdasfasd"));
	fifth.emplace(student(71420, "sdfzcvdasfasd"));
	fifth.emplace(student(242330, "dasdas4234fasd"));
	cout << " fifth.top().age   " << fifth.top().age << endl;

	vector<int> vec = { 1,34,2,58,66,9,70 };
	sort(vec.begin(), vec.end(), less<int>());
	for_each(vec.begin(), vec.end(), [](const int&a) {cout << a << " "; }); cout << endl;
	sort(vec.begin(), vec.end(), [](const int&a, const int&b) { return a > b; });
	for_each(vec.begin(), vec.end(), [](const int&a) {cout << a << " "; }); cout << endl;




	return 0;





}