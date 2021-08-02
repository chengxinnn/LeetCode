#pragma once


#include <vector>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (!matrix.size() || !matrix[0].size()) return{};
		int l = 0, r = matrix[0].size() - 1, //���ұ߽�
			t = 0, b = matrix.size() - 1,    //���±߽�
			id = 0, i = 0;
		vector<int>ans(matrix.size() * matrix[0].size());
		while (id < ans.size())
		{
			for (i = l; i <= r; i++)
				ans[id++] = matrix[t][i];
			if (++t > b) break;  //�����ұ����ϱ߽磬�ϱ߽�+1�����ܳ����±߽硣
			for (i = t; i <= b; i++)
				ans[id++] = matrix[i][r];
			if (--r < l) break;  //���ϵ��±����ұ߽磬�ұ߽�-1�����ܳ�����߽硣
			for (i = r; i >= l; i--)
				ans[id++] = matrix[b][i];
			if (--b < t) break;
			for (i = b; i >= t; i--)
				ans[id++] = matrix[i][l];
			if (++l > r) break;
		}
		return ans;
	}
};

void ini()
{
	Solution s;
	s.spiralOrder(vector<vector<int>>({ { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13,14,15,16 } }));


}