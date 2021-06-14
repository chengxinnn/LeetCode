#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) return size;

		int len = 1, pre = nums[0];
		for (int i = 1; i < size; i++)
		{
			if (pre != nums[i])
			{
				pre = nums[i];
				nums[len++] = pre;
			}
		}
		return len;
	}
};