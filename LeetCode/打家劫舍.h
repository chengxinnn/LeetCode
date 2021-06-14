#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
	/*
	打家劫舍 1
	你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
	影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
	给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
	*/
public:
	/*
	经典的dp问题
	思考思路
	1.划分阶段，依据问题的是空间特征根将其划分为不同的阶段
	2.状态转移方程。有上一个阶段的状态推到本阶段的状态。
	3.寻找边界条件。
	*/
	int rob1(vector<int>&nums)
	{
		int size = nums.size();
		if (size == 0) return 0;
		if (size == 1) return nums[0];
		vector<int>dp(size);
		dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < size; ++i)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[size - 1];
	}
	int rob11(vector<int>&nums)
	{
		int size = nums.size();
	    vector<	vector<int>>dp(size + 1, vector<int>(2, 0));
		for (int i = 1; i <= size; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = dp[i - 1][0] + nums[i - 1];
		}
		return max(dp[size][0], dp[size][1]);
	}
};

class Solution2
{
	/*
	打家劫舍2
	首位的住户相邻
	*/
public:
	/*
	第一种思路
	每隔两件的循环检查限制我们不能直接处理
	但是当我们忽略最后一个nums[size - 1]的时候，就破坏了循环条件，只需要考虑【0- size-2]。
	要偷最后一个元素，就不能偷取第一个元素，可以从第二个元素开始【1 - size-1】，计算最后一个元素的最佳值。
	然后取极大值。
	*/
	int rob2(vector<int>&nums)
	{
		int size = nums.size();
		if (size == 0) return 0;
		if (size <= 2) return *max_element(nums.begin(), nums.end());
		vector<int>dp1(size, 0), dp2(size, 0);
		dp1[1] = nums[0]; 
		for (int i = 2; i < size; ++i)
			dp1[i] = max(dp1[i - 2] + nums[i - 1], dp1[i - 1]);

		dp2[0] = nums[1];
		for (int i = 2; i < size; ++i)
			dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
		return max(dp1[size - 1], dp2[size - 1]);
	}
	int rob22(vector<int>&nums)
	{
		/*
		常量空间，但是在LeetCode上几乎么有反映
		还是空间换时间的好。
		*/
		int size = nums.size();
		if (size == 0) return 0;
		if (size <= 2) return *max_element(nums.begin(), nums.end());

		int dp10 = 0, dp11 = nums[0], dp12;
		for (int i = 2; i < size; ++i)
		{
			dp12 = max(dp10 + nums[i], dp11);
			dp10 = dp11;
			dp11 = dp12;
		}

		int dp20 = 0, dp21 = nums[1], dp22;
		for (int i = 2; i < size; ++i)
		{
			dp22 = max(dp20 + nums[i], dp21);
			dp20 = dp21;
			dp21 = dp22;
		}

		return max(dp12, dp22);
	}
	int rob22(vector<int>&nums)
	{
		int size = nums.size();
		if (size == 0) return 0;
		if (size <= 2) return *max_element(nums.begin(), nums.end());
		vector<vector<int>> dp(size, vector<int>(2, 0));
		//遍历一次 dp数组记录第一户是否被偷 dp[i][0]代表第一户未被偷时到第i户能偷到的最大金额 dp[i][1]代表第一户被偷时到第i户能偷到的最大金额
		dp[0][0] = 0;       dp[0][1] = nums[0];
		dp[1][0] = nums[1]; dp[1][1] = nums[0];
		for (int i = 2; i < size - 1; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + nums[i]);
		}
		dp[size - 1][0] = max(dp[size - 2][0], dp[size - 3][0] + nums[size - 1]);
		dp[size - 1][1] = dp[size - 2][1];
		return max(dp[size -1 ][0], dp[size -1][1]);
	}
};
void ini()
{
	Solution1 s1;
	
}