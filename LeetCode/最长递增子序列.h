#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution
{
public:

	/*
	给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
	*/
	int lengthOfLIS(vector<int>nums)
	{
		int size = nums.size();
		if (size == 0) return 0;
		vector<int>dp(size, 1);
		for (int i = 1; i < size; i++)
			for (int j = 0; j < i; j++)
				dp[i] = max(dp[i], dp[j] + 1);
		return *max_element(dp.begin(), dp.end());

	}

 	/*
	俄罗斯套娃问题。
	给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。
当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
注意：不允许旋转信封
	*/
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		int size = envelopes.size();
		sort(envelopes.begin(), envelopes.end());
		vector<int>dp(size, 1);
		for (int i = 1; i < size; i++)
			for (int j = 0; j < i; j++)
				if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
					dp[i] = max(dp[i], dp[j] + 1);

		return *max_element(dp.begin(), dp.end());
	}

};