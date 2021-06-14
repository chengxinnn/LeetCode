#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define M 1000000007
class Solution
{
public:
	//m * n µÄ DP
	int numWays(int steps, int arrLen) {
		vector<vector<int>>dp(steps + 1, vector<int>(arrLen + 2, 0));
		dp[0][1] = 1;
		for (int i = 1; i < steps + 1; i++)
			for (int j = 1; j < min(i + 2, arrLen + 1); j++)
				dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % M + dp[i - 1][j + 1]) % M;
		return dp[steps][1];
	}
	//2 * n µÄdp
	int numWays1(int steps, int arrLen) {
		int len = min(steps / 2 + 1, arrLen) + 2;
		vector<vector<int>> dp(2, vector<int>(len, 0));
		dp[0][1] = 1;
		int now = 0, pre = 1;
		for (int step = 1; step <= steps; step++)
		{
			swap(now, pre);
			for (int pos = 1; pos < min(step + 2, len - 1); pos++)
				dp[now][pos] = ((dp[pre][pos - 1] + dp[pre][pos + 1]) % M + dp[pre][pos]) % M;
		}
		return dp[now][1];
	}

};