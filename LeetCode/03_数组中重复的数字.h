#pragma once
#include <iostream>
#include <set>
#include <vector>
using namespace std;;


/*
一个解法是时间优先的话可以用set
*/
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int size = nums.size();
		set<int>s;
		for (const auto & x : nums)
		{
			if (s.count(x))
				return x;
			else
				s.insert(x);
		}
		return 0;

	}

	/*如果是空间要求O(1)的话可以使用一种原地hash 的
	因为题目中给的元素是0 - n-1的，我们可以想到将元素i放到数组的位置i，
	将他放到正确的位置，但是如果这两个地方的元素相等时，说明发生了重复。
	*/
	int findRepeatNumber(vector<int>& nums) {
		int size = nums.size();
		for (int i = 0; i < size; i++)
			while (nums[i] != i)
			{
				if (nums[i] == nums[nums[i]]) return nums[i];
				swap(nums[i], nums[nums[i]]);
			}
		return 0;
	}

};


