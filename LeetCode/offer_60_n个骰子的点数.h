#pragma once
#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<double> dicesProbability(int n) {
		int*dp = new int[6 * n + 1]();
		for (int i = 1; i <= 6; i++) dp[i] = 1;
		//第n个骰子
		for (int i = 2; i <= n; i++)
		{
			//两个骰子点数和范围
			for (int j = 6 * i; j >= i; j--)
			{
				dp[j] = 0;
				for (int k = j - 1; k >= max(i-1, j - 6); k--)
					dp[j] += dp[k];
			}				
		}
		vector<double>ans(5 * n + 1);
		double count = pow(6, n);
		for (int i = n; i < 6 * n + 1; i++)
			ans[i - n] = dp[i] / count;
		delete [] dp;
		return ans;
	}
};

void ini()
{
	Solution s;
	auto it = s.dicesProbability(3);
	for (const auto & x : it)
		cout << x << " ";
	cout << endl;
}
