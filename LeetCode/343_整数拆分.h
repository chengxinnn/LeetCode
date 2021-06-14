#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int  IntegerBreak(int n)
	{
		int *dp = new int[n + 1];
		for (int i = 0; i < n + 1; i++)
			dp[i] = 1;
		for (int i = 3; i < n + 1; i++)
			for (int j = 1; j < i; j++)
				dp[i] = max(dp[i], max(dp[i - j] * j, (i - j)*j));

		return dp[n];
		
	}
};