#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	int rob(vector<int>&nums)
	{
		int n = nums.size();
		if (n == 0)
			return 0;
		else if (n < 4)
			return *max_element(nums.begin(), nums.end());

		int **dp = new int*[n];
		for (int i = 0; i < n; i++)
			dp[i] = new int[2];
		dp[0][0] = 0;
		dp[0][1] = nums[0];
		dp[1][0] = nums[1];
		dp[1][1] = nums[0];

		for (int i = 2; i < n; i++)
		{
			if (i != n - 1)
			{
				dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i]);
				dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + nums[i]);

			}
			else
			{
				dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i]);
				dp[i][1] = dp[i - 1][1];
			}
		}

		return max(dp[n - 1][0], dp[n - 1][1]);
	}


	int rob1(vector<int> &nums)
	{

		int n = nums.size();
		if (n == 0) return 0;
		else if (n < 4) return *max_element(nums.begin(), nums.end());

		vector<vector<int>> dp(3, vector<int>(2));
		dp[0][0] = 0;
		dp[0][1] = nums[0];
		dp[1][0] = nums[1];
		dp[1][1] = nums[0];

		for (int i = 2; i < n; i++)
		{
			if (i != n - 1)
			{
				dp[2][0] = max(dp[1][0], dp[0][0] + nums[i]);
				dp[2][1] = max(dp[1][1], dp[0][1] + nums[i]);
				dp[0] = dp[1];
				dp[1] = dp[2];
			}
			else
			{
				dp[2][0] = max(dp[1][0], dp[0][0] + nums[i]);
				dp[2][1] = dp[1][1];
			}
		}

		return max(dp[2][0], dp[2][1]);
	}
};