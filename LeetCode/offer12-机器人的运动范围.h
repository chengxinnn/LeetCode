#pragma once
#include <iostream>

using namespace std;

/*

剑指 Offer 13. 机器人的运动范围
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外）
也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
请问该机器人能够到达多少个格子？

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