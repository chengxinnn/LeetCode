#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class solution
{
public:
	/*
	给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。
	*/
	int smallsetDistancePair(vector<int>&nums, int k)
	{
		int size = nums.size();
		sort(nums.begin(), nums.end());
		int start = 0, end = nums[size - 1] - nums[0];
		while (start < end) {
			int mid = start + ((end - start) >> 1);
			int l = 0, cnt = 0;
			for (int r = 1; r < size; r++)
			{
				while (nums[r] - nums[l] > mid) l++;
				cnt += r - l;
			} 
			if (cnt >= k) end = mid;
			else start = mid + 1;
		}
		return start;
	}

};

void ini()
{
	solution s;
	cout << s.smallsetDistancePair( vector<int>({ 1, 3, 1 }) , 3);
}