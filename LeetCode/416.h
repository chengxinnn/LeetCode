#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {

		int n = nums.size();
		if (n < 2) return false;

		int maxnum = *max_element(nums.begin(), nums.end());

		int sum = accumulate(nums.begin(), nums.end(), int(0));

		if (sum % 2 == 1)
			return false;

		int tar = sum / 2;
		if (tar < maxnum)
			return false;

		bool *dp = new bool[tar + 1];
		memset(dp, false, tar + 1);
		dp[0] = true;

		int i, j;
		for (i = 0; i < n; i++)
			for (j = tar; j >= nums[i]; j--)
				dp[j] |= dp[j - nums[i]];


		return dp[tar];

	}
};