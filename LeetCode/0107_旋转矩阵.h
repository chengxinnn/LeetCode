#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*
旋转矩阵，不将思路放在整体，而是部分
因为要对整个矩阵旋转九十度，
考虑到转换的关系后，
将矩阵分为四个part
需要比较的就是不同part之间的转换关系。
i j 的中心轴对称点坐标 n-1-i n -1-j

*/

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (!matrix.size() || !matrix[0].size()) return;
		int rows = matrix.size(), cols = matrix[0].size();
		if (rows != cols)return;
		int r = (rows - 1) >> 1, b = (rows >> 1) - 1;
		for (int i = b; i >= 0; i--)
			for (int j = r; j >= 0; j--)
			{
				swap(matrix[i][j], matrix[j][rows - 1 - i]);
				swap(matrix[rows - 1 - i][rows - 1 - j], matrix[rows - 1 - j][i]);
				swap(matrix[i][j], matrix[rows - 1 - i][rows - 1 - j]);
				//swap(matrix[i][j], matrix[rows - 1 - j][i]);
			}


	}
};

void ini()
{
	Solution s;
	vector<vector<int>>ans({ { 1,2,3 },{ 4,5,6 },{ 7,8,9 } });
	s.rotate(ans);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}

}