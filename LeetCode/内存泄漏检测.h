#pragma once

#include <iostream>

using namespace std;

//�Ӻ�����Ϊ�����߷����ڴ�
//1.ͨ���༶ָ��
bool getp1(char ** p1)
{
	*p1 = (char *)malloc(10 * sizeof(char));
	
	if (nullptr == *p1) return 0;
	memset(*p1, 'c', 10);
	return 1;
}

//ͨ������ֵ
char* getp2()
{
	char * p = (char *)malloc(10 * sizeof(char));
	memset(p, 'c', 10);
	
	return p;
}

//ʧ�ܵ����ӣ� �ڴ�й©��
void getp(char * p)
{
	p = (char *)malloc(8 * sizeof(char));
	p[9] = 'c';
}
void ini()
{
	char * p1 = nullptr;
	getp1(&p1);
	cout << p1[9] << endl;


	char * p2 = nullptr;
	p2 = getp2();
	cout << p2[9] << endl;

	char * p3 = nullptr;
	getp(p3);
	cout <<( p3 == nullptr )<< endl;



	return;
}