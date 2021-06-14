#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int n = nums.size();
		int i = 0;
		vector<int> id = {};
		for (int i = 0; i < n; i++)
		{
			if (nums[i] == 0)
			{
				id.emplace_back(i);
				nums.emplace_back(0);
			}
		}
		for (int x = id.size() - 1; x >= 0; x--)
			nums.erase(nums.begin() + id[x]);

	}
};