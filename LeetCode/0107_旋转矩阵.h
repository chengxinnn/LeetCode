#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*
��ת���󣬲���˼·�������壬���ǲ���
��ΪҪ������������ת��ʮ�ȣ�
���ǵ�ת���Ĺ�ϵ��
�������Ϊ�ĸ�part
��Ҫ�Ƚϵľ��ǲ�ͬpart֮���ת����ϵ��
i j ��������ԳƵ����� n-1-i n -1-j

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