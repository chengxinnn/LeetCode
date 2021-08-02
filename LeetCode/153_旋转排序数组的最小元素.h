#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/*
	153 旋转排序数组的最小值 不重复
	这个题目的主要思路是用二分法，不断地逼近最小值。

	一般而言可以分为两种情况，原数组较大一部分在旋转后的左侧，另一种是在数组右侧。
	由此我们可以以数组的中间值进行判断，
	当中间值小于数组右侧的值时，说明在当前部分，数组是递增的，最小值应该在包括中间值的左侧
	当中间值大于数组右侧的值时，说明右侧发生了旋转，最小值应该在不包括中间值的右侧。
	*/
	int findMin153(vector<int>& nums) {
		int size = nums.size();
		int left = 0, right = size - 1, mid = 0;
		while (left < right)
		{
			mid = (left + right) >> 1;
			if (nums[mid] < nums[right]) right = mid;
			else  left = mid + 1;
		}
		return nums[left];
	}
   	/*
	154, 有重复元素 
	一种方式是 排除重复元素的干扰。让数组相对有序
	*/
	int findMin154(vector<int>& nums)
	{ 
		int size = nums.size();
		int l = 0, r = size - 1;
		while (l < r)
		{
			while (l < r && nums[l] == nums[l + 1]) l++;
			while (r > l && nums[r] == nums[r - 1]) r--;
			int mid = l + ((r - l) >> 1);
			if (nums[mid] > nums[r])
				l = mid + 1;
			else
				r = mid;
		}
		return nums[l];
	}
	/*
	154, 有重复元素
	另外一种思考是， 当中间值小于大于右侧值的时候，处理方式和原来的一样。
	当中间值等于右侧的时候，最小值可能在中间值的左侧，叶可能中间值的右侧。但是既然和中间值相等，必然不会是右边界。缩小右边界。
	*/
	int findMin1542(vector<int>& nums)
	{
		int size = nums.size();
		int l = 0, r = size - 1;
		while (l < r)
		{
			int mid = l + ((r - l) >> 1);
			if (nums[mid] > nums[r])
				l = mid + 1;
			else if (nums[mid] < nums[r])
				r = mid;
			else
				r--;

		}
	}

};

int ini()
{
	Solution s;
	vector<int>ss = { 1, 2,3,4,5 };
	cout << s.findMin(ss);
	return 0;
}