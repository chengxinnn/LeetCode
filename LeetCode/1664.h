#pragma once
#include <vector>
using namespace std;
class Solution {
public:

	bool right(vector<int>&nums, int &size, int off)
	{
		int id;
		int sum = 0;
		bool offset = false;
		for (int i = 0; i < size; i++)
		{
			if (i == off) { offset = true; continue; }
			sum = offset ? (i % 2 == 1 ? sum - nums[i] : sum + nums[i]) : (i % 2 == 1 ? sum + nums[i] : sum - nums[i]);
		}
		return sum == 0;
	}
	int waysToMakeFair(vector<int>& nums) {
		int num = 0;
		int size = nums.size();
		for (int i = 0; i < size; i++)
			if (right(nums, size, i))
				num++;
		return num;
	}
};