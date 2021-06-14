#pragma once
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (!n) return{};
		vector<vector<int>>ans(n, vector<int>(n, 0));

		bool bound;
		int count = 1;
		int row = 0, col = 0, nums = n * n;
		int dx = 1, dy = 0, d;
		int left = 0, right = n - 1, top = 0, down = n - 1;
		while (count <= nums)
		{
			ans[row][col] = count;
			count++;
			col += dx; row += dy;
			if (col > right) {top++; bound = true;}
			else if (row > down) { right--; bound = true; }
			else if (col < left) { down--; bound = true; }
			else if (row < top) { left++; bound = true; }
			else bound = false;
			if (bound)
			{
				col -= dx; row -= dy;
				d = dy; dy = dx; dx = -d;
				col += dx; row += dy;
			}
		}
		return ans;
	}
};