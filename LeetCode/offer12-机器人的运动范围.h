#pragma once
#include <iostream>

using namespace std;

/*

��ָ Offer 13. �����˵��˶���Χ
������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩
Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18���������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19��
���ʸû������ܹ�������ٸ����ӣ�

*/
class Solution
{
public:
	int movingCouunt(int m, int n, int k)
	{
		bool * visit = new bool[m * n]();
		return helper(visit, 0, 0, m, n, k);

	}
	int helper(bool * visited, int r, int c, const int & rows, const int & cols, const int & k)
	{
		if (r < 0 || c < 0 || r >= rows || c >= cols || visited[r * cols + j] || r / 10 + r % 10 + c / 10 + c % 10 > k) return 0;
		visited[r * cols + c] = 1;
		return helper(visited, r + 1, c, rows, cols, k) + helper(visited, r, c + 1, rows, cols, k);
	}
};