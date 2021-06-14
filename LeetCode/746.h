#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		if (n == 1) return cost[0];
		if (n == 0) return 0;
		int*dp = new int[n + 1]();
		dp[1] = cost[0];
		for (int i = 1; i<n; i++)
		{
			dp[i + 1] = min(dp[i - 1], dp[i]) + cost[i];
			printf("%d    ", dp[i + 1]);
		}
		
		return min(dp[n - 1], dp[n]);

	}
};