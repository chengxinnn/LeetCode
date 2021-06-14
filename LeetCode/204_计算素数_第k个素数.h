#pragma once
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

/*
统计所有小于非负整数 n 的质数的数量
*/
int countPrime(int n)
{
	if (n < 2) return 0;
	vector<char>nums(n,  1);
	long long i, j;
	int ans = 0;
	for (i = 2; i < n; i++)
	{
		if (nums[i])
		{
			ans++;
			for (j = i * i; j < n; j += i)
				nums[j] = 0;
		}
	}
	return ans;

}

/*
寻找第k个素数
*/
int getKPrime(int k)
{
	if (k < 1) return 0;
	if (k == 1) return 2;
	int ans = 1;
	for (int i = 3; ; i+=2)
	{
		bool sign = 1;
		for (long long  j = 3; j * j  <= i; j += 2)
		{
			if (i % j == 0)
			{
				sign = 0;
				break;
			}
		}
		if (sign) ans++;
		if (ans == k) return i;
	}
}



void ini()
{
	int n = 10;
	cout << "小于 " << n << " 的素数有 " << countPrime(n) << " 个" << endl;
	n = 10;
	cout << "第 " << n << " 个素数是 " << getKPrime(n) << endl;

}