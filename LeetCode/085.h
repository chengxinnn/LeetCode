#pragma once
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	//��һ��˼·�Ƚ��ձ飬��ÿһ��ÿһ��Ԫ�ؼ�¼�����θ߶�(��������Ϊ1�ĵĳ���)
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		int row = matrix.size(), col = matrix[0].size();
		//int *dp = new int[col + 1]();
		vector<int>dp(col + 1, 0);
		int i, j, k, curlen, area = 0;
		for (i = 1; i <= row; i++) {
			for (j = 1; j <= col; j++) {
				if (matrix[i - 1][j - 1] == '0') {
					dp[j] = 0;
					continue;
				}
				else {
					dp[j] = dp[j] + 1;
					curlen = dp[j];
					k = j;
					while (k > 0 && matrix[i - 1][k - 1] == '1')
					{
						curlen = min(curlen, dp[k]);
						area = max(area, (j - k + 1)*curlen);
						k--;
					}
				}
			}
		}
		return area;
	}
};
