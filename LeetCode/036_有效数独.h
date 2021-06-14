#pragma once
#include <vector>
using namespace std;
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool row[9][9] = { 0 }, col[9][9] = { 0 }, block[9][9] = { 0 };
		int i = 0, j = 0, blockid, tmp;
		for (; i < 9; i++)
		{
			for (; j < 9; j++)
			{
				if (board[i][j] != '.')
				{
					tmp = board[i][j] - '1';
					blockid = i / 3 * 3 + j / 3;
					if (row[i][tmp] || col[j][tmp] || block[blockid][tmp]) return false;
					row[i][tmp] = true; col[j][tmp] = true; block[blockid][tmp] = true;
				}
			}
		}
		return true;
	}

	//状态压缩位移运算。行列块各一个九元素数组，分别保存每一行每一列每一块，每一块的0-9是否占用用移位表示
	// 0 1 0 0 0 0 0 0 0 表示‘8’已经出现在该行列块。若再次出现‘8’，改元素对应标志位相与则不为零，判定失败
	// 否则按行列块 或 结果，表示该结果站位。
	bool isValidSudoku_bit(vector<vector<char>>& board) {
		int rowmap[9] = {};
		int colmap[9] = { 0 };
		int blkmap[9] = { 0 };
		int bias, id;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (board[i][j] != '.')
				{
					id = board[i][j] - '1';
					bias = 0x01 << id;
					if (bias & (rowmap[i] | colmap[j] | blkmap[i / 3 * 3 + j / 3]))return false;
					rowmap[i] |= bias;
					colmap[j] |= bias;
					blkmap[i / 3 * 3 + j / 3] |= bias;
				}
		return true;
	}
	
	// 上述方式运行的过程中，我们发现其实可以以一个九原数组替代上面的三个数组，因为一个int至少32位，我们可以以低九位表示行，中九位表示列，后九位表示块
	// 这样就可以以一个int存储数据。
	bool isValidSudoku_bit1(vector<vector<char>>& board) {
		int bitmap[9] = { 0 };
		int id;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (board[i][j] != '.')
				{
					id = 1 << (board[i][j] - '1');
					if (id & (bitmap[i] | bitmap[j] >> 9 | bitmap[i / 3 * 3 + j / 3] >> 18)) 
						return false;
					bitmap[i] |=  id;
					bitmap[j] |= id << 9;
					bitmap[i / 3 * 3 + j / 3] |= id << 18;
				}
		return true;
		
	}

	//进一步状态压缩
	bool isValidSudoku2(vector<vector<char>>& board) {
		int sets[9] = { 0 };
		for (int ri = 0; ri < 9; ++ri) {
			for (int ci = 0; ci < 9; ++ci) {
				if (board[ri][ci] != '.') {
					int bi = ri / 3 * 3 + ci / 3;
					int uvb = 1 << (board[ri][ci] - '0');
					if ((uvb & (sets[ri] | sets[ci] >> 9 | sets[bi] >> 18)) != 0)
						return false;
					sets[ri] |= uvb;
					sets[ci] |= uvb << 9;
					sets[bi] |= uvb << 18;
				}
			}
		}
		return true;
	}

};
