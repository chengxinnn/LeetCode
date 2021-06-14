#pragma once
#include <vector>
using namespace std;
class Solution {
public:


	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return{};
		int rows = matrix.size(), cols = matrix[0].size();

		vector<vector<int>> vis(rows + 2, vector<int>(cols + 2, 0));
		for (int i = 0; i < rows + 2; i++) { vis[i][0] = 1; vis[i][cols + 1] = 1; }
		for (int i = 0; i < cols + 2; i++) { vis[0][i] = 1; vis[rows + 1][i] = 1; }

		vector<int>ans(cols * rows, 0);
		int col = 0, row = 0;
		vector<int>lr = { 1, 0, -1, 0 }, ud = { 0, -1, 0 ,1 };
		int dir = 0, count = 0, nums = rows*cols;

		while (count < nums)
		{
			if (!vis[row + 1][col + 1])
			{
				vis[row + 1][col + 1] = 1;
				ans[count] = matrix[row][col];
				col += lr[dir]; row += ud[dir];
				count++;
			}
			else
			{
				col -= lr[dir]; row -= ud[dir];
				dir = (dir + 1) % 4;
				col += lr[dir]; row += ud[dir];
			}
		}
		return ans;

	}
};