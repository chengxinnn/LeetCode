#pragma once
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


class Solution
{
public:
	/*
	����
	����һ������ n �������ж� n �Ƿ�Ϊ ���� ������ǣ����� true �����򣬷��� false ��
	���� ����ֻ����������?2��3 ��/��?5?����������

	��⣺
	���������n�ǳ����Ļ�����ôn����дΪ pow(2,a) * pow(3, b) * pow(5, c)����ʽ������abc���ǷǸ�����
	�ɴ˿��Ե�֪��������n����2��3��5����ʣ�µ���Ϊ1�����ǳ����������ǡ�
	*/
	bool isUgly(int num)
	{
		if (num < 1) return false;
		while (num % 2) num >>= 1;
		while (num % 3) num /= 3;
		while (num % 5) num /= 5;
		return num == 1;
	}

	/*
	����2
	���ص�n������

	*/
	int nthUglyNumber(int n)
	{
		int num = 0;
		int time[3] = { 0 };
		int *nums = new int[n](); nums[0] = 1;
		for (int i = 1; i < n; i++)
		{
			num = min(nums[time[0]] * 2,min( nums[time[1]] * 3, nums[time[2]] * 5) );
			nums[i] = num;
			if (num == nums[time[0]] * 2) time[0]++;
			if (num == nums[time[1]] * 3) time[1]++;
			if (num == nums[time[2]] * 5) time[2]++;
		}
		return nums[n - 1];
		
	}

	/*
	����3��

	�����ĸ�������n ��a ��b ��c ���������һ���㷨���ҳ��� n ��������
    �����ǿ��Ա� a �� b �� c ������ ������ ��
	*/
};



void ini()
{
	Solution s;
	cout << "����1 ��" << 17;
	if(s.isUgly(17)) cout <<"�ǳ���";
	else cout << "���ǳ���";
	cout << endl;

	cout << "����2 ��" << 10;
	cout << "��ʮ�������� :" << s.nthUglyNumber(10) << endl;

}