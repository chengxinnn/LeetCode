
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {

		int i, j;
		int h = grid.size();
		int w = grid[0].size();
		int **dp = new int*[h + 1];
		for (i = 0; i < h + 1; i++)
		{
			dp[i] = new int[w + 1];
			memset(dp[i], 0, sizeof(int)*(w + 1));
		}
			

		for (i = 1; i <= h; i++)
			for (j = 1; j <= w; j++)
			{

				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i - 1][j - 1];
				cout << dp[i][j] << endl;
			}

		return dp[h][w];

	}
};