#pragma once
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;


auto acmp = [](const int & a, const int &b) {return a > b; };

bool funccmp(const int&a, const int&b)
{
	return a > b;
}

class Solution {
public:
	int nums[1690] = { 1 };
	int times[3] = { 2,3,5 };
	int nthUglyNumber1(int n) {
		return  nums[n -1 ];
	}


	int nthUglyNumber(int n) {
		vector<int>nums(n, 1), idx(3, 0);
		for (int i = 1; i < n; i++)
		{
			int a = 2 * nums[idx[0]], b = 3 * nums[idx[1]], c = 5 * nums[idx[2]];
			int next = min(a, min(b, c));
			if (next == a) ++idx[0];
			if (next == b) ++idx[1];
			if (next == c) ++idx[2];
			nums[i] = next;
		}
		return nums.back();
	}


	Solution()
	{
		priority_queue<int, vector<int>, decltype(acmp) > pq(acmp);
		unordered_map<int, int> um;
		pq.emplace(1);
		for (int i = 0; i < 1690; i++)
		{
			int curnum = pq.top();
			pq.pop();
			nums[i] = curnum;
			for (int j = 0; j < 3; j++)
			{
				int newnum = times[j] * curnum;
				if (!um.count(newnum))
				{
					um[newnum] = 1;
					pq.emplace(newnum);
				}
			}
		}
	}
};