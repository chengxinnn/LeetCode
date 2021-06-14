#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	int numSubmat(vector<vector<int>>& mat) {

		int height = mat.size();
		int width = mat[0].size();
		int i = 0, j = 0;
		int **dp = new int*[height + 1];
		for (; i < height; i++) dp[i] = new int[width + 1]();

		int count = 0;
		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
			
			}
		}

	}
};