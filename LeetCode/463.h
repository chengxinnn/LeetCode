#pragma once

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		
		const static int dx[4] = { 0, 1, 0 ,-1 };
		const static int dy[4] = { 1, 0, -1, 0 };

		int h = grid.size();
		int w = grid[0].size();
		int count = 0;
		int adj;
		int i, j, k, x, y;

		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				if (grid[i][j] == 1)
				{
					adj = 0;
					for (k = 0; k < 4; k++)
					{
						x = i + dx[i];
						y = j + dy[j];
						if (x < 0 || x + 1 >= h || j - 1 < 0 || j + 1 >= w || grid[x][y] == 0)
							adj++;
					}
					count += adj;

				}

			}
		}
		return count;

	}
};