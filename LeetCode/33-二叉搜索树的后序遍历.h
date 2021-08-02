#pragma once
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		return helper(postorder, 0, postorder.size() - 1);
	}

	bool helper(vector<int>&nums, int l, int r)
	{
		if (r <= l) return 1;

		int i = l, tar = nums[r];
		while (i < r)
		{
			if (nums[i] > tar)
				break;
			i++;
		}
		for (int j = i; j < r; j++)
			if (nums[j] <= tar)
				return 0;

		return helper(nums, l, i - 1) && helper(nums, i, r - 1);
	}

};

void ini()
{
	Solution s;
	cout << s.verifyPostorder(vector<int>({ 1,2,5,10,6,9,4,3}));
}