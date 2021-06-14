#pragma once
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
		int height = mat.size(), width = mat[0].size();

		int i, j, pos, minx, maxx, miny, maxy;
		//int**dp = new int*[height + 1];
		//for (i = 0; i < height; i++)
		//{
		//	dp[i] = new int[width + 1];
		//	memset(dp[i], 0, width + 1);
		//}

		int * dp = (int*)malloc((height + 1)  * (width + 1)*sizeof(int));
		memset(dp, 0, (height + 1)  * (width + 1)*sizeof(int));


		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
				pos = i * width + j;
				printf("%d \t", dp[pos]);
			}
			printf("\n");

		}

		for (i = 0; i < height; i++)
			for (j = 0; j < width; j++)
			{
				pos = i *width + j;
				dp[(i + 1) *width + j + 1] = dp[i *width + j+1] + dp[(i+1) *width + j] - dp[i *width + j] + mat[i][j];
			}
				

		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
				minx = max(0, i - K);
				maxx = min(i + K, height - 1);
				miny = max(0, j - K);
				maxy = min(j + K, width - 1);
				mat[i][j] = dp[(maxx + 1)* width + (maxy + 1)] - dp[minx* width + maxy + 1] - dp[(maxx + 1)* width + miny] + dp[minx* width + miny];
			}
		}
		return mat;

	}
};