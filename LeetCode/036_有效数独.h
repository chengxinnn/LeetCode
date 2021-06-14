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

	//״̬ѹ��λ�����㡣���п��һ����Ԫ�����飬�ֱ𱣴�ÿһ��ÿһ��ÿһ�飬ÿһ���0-9�Ƿ�ռ������λ��ʾ
	// 0 1 0 0 0 0 0 0 0 ��ʾ��8���Ѿ������ڸ����п顣���ٴγ��֡�8������Ԫ�ض�Ӧ��־λ������Ϊ�㣬�ж�ʧ��
	// �������п� �� �������ʾ�ý��վλ��
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
	
	// ������ʽ���еĹ����У����Ƿ�����ʵ������һ����ԭ�������������������飬��Ϊһ��int����32λ�����ǿ����Ե;�λ��ʾ�У��о�λ��ʾ�У����λ��ʾ��
	// �����Ϳ�����һ��int�洢���ݡ�
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

	//��һ��״̬ѹ��
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
