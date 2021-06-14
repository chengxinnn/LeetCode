#pragma once
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


class Solution
{
public:
	/*
	丑数
	给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
	丑数 就是只包含质因数?2、3 和/或?5?的正整数。

	题解：
	如果正整数n是丑数的话，那么n可以写为 pow(2,a) * pow(3, b) * pow(5, c)的形式，其中abc都是非负数。
	由此可以得知，反复对n除以2，3，5，若剩下的数为1，则是丑数，否则不是。
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
	丑数2
	返回第n个丑数

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
	丑数3：

	给你四个整数：n 、a 、b 、c ，请你设计一个算法来找出第 n 个丑数。
    丑数是可以被 a 或 b 或 c 整除的 正整数 。
	*/
};



void ini()
{
	Solution s;
	cout << "丑数1 ：" << 17;
	if(s.isUgly(17)) cout <<"是丑数";
	else cout << "不是丑数";
	cout << endl;

	cout << "丑数2 ：" << 10;
	cout << "第十个丑数是 :" << s.nthUglyNumber(10) << endl;

}