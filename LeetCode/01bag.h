#pragma once
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
public:


	/************************************************************
	*问题描述     ： 01背包问题，n件物品，每一件物品有自己的价值和重量，求在容量一定的背包中能装下的最大的价值
	*状态转移方程 ： dp[i][j] =max( dp[i-1][ j - k*w[i]] + k*val[i] ); 0 <= k <= j/w[i]
	*************************************************************/
	int traditionalBag(vector<int>& val, vector<int>& w, int W)
	{
		int size = val.size();

		vector<vector<int>> dp(size + 1, vector<int>(W + 1, 0));

		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				if (j - w[i - 1] >= 0)
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + val[i - 1]);
				else
					dp[i][j] = dp[i - 1][j];

			}
		}

		return dp[size][W];


	}

	int traditionalBag1d(vector<int>& val, vector<int>& w, int W)
	{
		int size = val.size();

		vector<int> dp(W + 1, 0);

		for (int i = 0; i < size; i++)
		{
			for (int j = W; j >= w[i - 1]; j--)
			{
				dp[j] = max(dp[j], dp[j - w[i]] + val[i]);

			}
		}
		return dp[W];

	}



	/************************************************************
	*问题描述     ： 完全背包问题，每一件物品都有自己的质量价值，每一件物品无限可用，求在背包容量一定时能装下的最大价值
	*状态转移方程 ： dp[i][j] = max( dp[i-1][j - k*w[i]] + k*val[i] ); 0 <= k <= j/w[i]
	*************************************************************/
	int unlimitedBag(vector<int>& val, vector<int>& w, int W)
	{
		int size = val.size();
		int maxval = 0;
		int i, j, k = 0;

		vector<vector<int>> dp(size + 1, vector<int>(W + 1, 0));

		for ( i = 1; i <= size; i++)
		{
			for (j = 1; j <= W; j++)
			{			
				for ( k = 0; k <= j / w[i - 1]; k++)
				{
					maxval = max(dp[i - 1][j - k * w[i - 1]] + k * val[i - 1], maxval);
				}
				dp[i][j] = maxval;
			}
			maxval = 0;
		}

		return dp[size][W];
	}

	//上述的算法三重循环，大大增加了时间消耗，在此使用技巧避免三重循环

	/************************************************************
	*问题描述     ： 上述方法使用三重循环，大大增加了时间的消耗
	*状态转移方程 ： dp[i][j] = max( dp[i-1][j - k*w[i]] + k*val[i] ); 0 <= k <= j/w[i]
	*************************************************************/
	int unlimitedBag_simp(vector<int>& val, vector<int>& w, int W)
	{
		int size = val.size();

		vector<vector<int>> dp(size + 1, vector<int>(W + 1, 0));

		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				if (j >= w[i - 1])
					dp[i][j] = max(dp[i][j - w[i - 1]] + val[i - 1], dp[i - 1][j]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		return dp[size][W];
	}



	int unlimitedBag_1d(vector<int>& val, vector<int>& w, int W)
	{
		int size = val.size();

		vector<int> dp(W + 1, 0);

		for (int i = 0; i < size; i++)
			for (int j = w[i]; j <= W; j++)
				dp[j] = max(dp[j - w[i]] + val[i], dp[j]);


		return dp[W];
	}

};