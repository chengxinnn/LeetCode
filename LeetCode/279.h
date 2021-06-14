#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
	int numSquares(int n) {

		vector<int> dp(n + 1, 0);

		int i, j, minum;

		for (i = 1; i <= n; i++)
		{
			minum = 100000;

			for (j = 1; i- j*j >= 0; j++)
				minum = min(dp[i - j*j] + 1, minum);

			dp[i] = minum;
		}
		return dp[n];


	}
};
