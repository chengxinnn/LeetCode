#pragma once




#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

		//����k����תվ����nվ��cost,��ʼ��Ϊmaxint
		vector<vector<int>> dp(n, vector<int>(K + 1, INT_MAX));
		int max;

		//ֱ��վ
		for (const auto & x : flights)
			if (x[0] == src)
				dp[x[1]][0] = x[2];


		for (int i = 0; i <= K; ++i)
			dp[src][i] = 0;

		for (int j = 1; j <= K; j++)
			for (const auto &x : flights)
				if (dp[x[0]][j - 1] != INT_MAX)
					dp[x[1]][j] = min(dp[x[1]][j], dp[x[0]][j - 1] + x[2]);

		return dp[dst][K] == INT_MAX ? -1 : dp[dst][K];
	}
};