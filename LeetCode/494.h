#pragma once
#include <vector>

using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int> & nums, int S) {
		int sum = 0;
		for (int num : nums) {
			sum += num;
		}
		// 背包容量为整数，sum + S为奇数的话不满足要求
		if (((sum + S) & 1) == 1) {
			return 0;
		}
		// 目标和不可能大于总和
		if (S > sum) {
			return 0;
		}
		sum = (sum + S) >> 1;
		int len = nums.size();
		vector < vector<int>> dp(len + 1, vector<int>(sum + 1, 0));

		dp[0][0] = 1;

		// 如果迭代部分 j 的初值赋 1 的话，就要先初始化 j = 0 的情况
		/* int count = 1;
		for (int i = 1; i <= len; i++) {
		// ±0 均可
		if (nums[i - 1] == 0) {
		count *= 2;
		}
		dp[i][0] = count;
		} */

		// 01背包 
		// i(1 ~ len)表示遍历（不一定选）了 i 个元素，j(0 ~ sum) 表示它们的和
		for (int i = 1; i <= len; i++) {
			for (int j = 0; j <= sum; j++) {
				// 装不下（不选当前元素）
				if (j - nums[i - 1] < 0) {
					dp[i][j] = dp[i - 1][j];
					// 可装可不装（当前元素可选可不选）
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
				}
			}
		}

		return dp[len][sum];
	}



	int findTargetSumWays1(vector<int> & nums, int S) {

		long long sum = 0;
		for (int num : nums)
			sum += num;

		if ((sum + S) % 2 == 1)
			return 0;

		if (S > sum)
			return 0;

		sum = (sum + S) / 2;
		vector<int> dp(sum + 1);
		dp[0] = 1;

		for (int num : nums)
			for (int i = sum; i >= num; --i)
				dp[i] += dp[i - num];//满足剩余i的方法数等于装入num和不装入num

		return dp[sum];
	}

};
