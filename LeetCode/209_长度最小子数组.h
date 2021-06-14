#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/*
给定一个含有?n?个正整数的数组和一个正整数 target 。
找出该数组中满足其和 ≥ target 的长度最小的 连续子数组?[numsl, numsl+1, ..., numsr-1, numsr] ，
并返回其长度。如果不存在符合条件的子数组，返回 0 。
*/

/************************************************************************
解决连续子数组问题由几个普遍方法。一个是暴力解法，一个是滑动窗，一个是前缀和。
*/

int lowerbound(vector<int>&nums,  int target)
{
	int size = nums.size();
	int l = 0, r = size - 1, mid = 0;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (nums[mid] < target) l = mid + 1;
		else r = mid;
	}
	return nums[l] >= target ? l : -1;
}


int minlen1(vector<int>nums, int target)
{
	int size = nums.size();
	int ans = INT_MAX;
	vector<int>sums(size + 1, 0);
	for (int i = 0; i < size; i++)
		sums[i + 1] = sums[i] + nums[i];
	for (int i = 0; i <= size; i++)
	{
		int s = target + sums[i];
		int pos = lowerbound(sums, s);
		if (pos != -1)
		{
			ans = min(ans, pos - i);
		}
	}
	return ans == INT_MAX ? -1 : ans;

}

//滑动窗
int minlen(vector<int>nums, int target)
{
	int size = nums.size();
	int ans = size + 1;
	int l = 0, r = 0, sum = 0;
	for (; r < size; r++)
	{
		sum += nums[r];
		if (sum >= target)
		{
			while (sum - nums[l] >= target)
				sum -= nums[l++];
			ans = min(ans, r - l + 1);
		}
	}
	return ans == size + 1 ? 0 : ans;
}

//暴力解法
int force(vector<int>nums, int target)
{
	int n = nums.size();
	int ans = INT_MAX;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += nums[j];
			if (sum >= target)
			{
				ans = min(ans, j - i + 1);
				break;
			}
		}

	}
	return ans == INT_MAX ? 0: ans;
}


void ini()
{

	vector<int>nums = { 2,3,1,4,3,5,6,3,2 };
	int target = 7;
	cout << "滑动窗  :" << minlen(nums, target) <<endl;
	cout << "暴力法  :" << force(nums, target) << endl;
	cout << "前缀二分:" << minlen1(nums, target) << endl;


}