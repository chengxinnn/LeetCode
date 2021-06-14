#pragma once
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> largeGroupPositions(string s) {
		int size = s.size(), len = 0;
		if (size < 3) return{};
		vector<int>temp(2, 0);
		vector<vector<int>> res;
		for (int i = 1; i <= size; i++)
		{
			if (i == size && len > 2)
			{
				temp = { i - len, i - 1 };
				res.emplace_back(temp);
				return res;
			}
			if (s[i] == s[i - 1])
				len = len ? ++len : 2;
			else
			{
				if (len >= 3)
				{
					temp = { i - len, i - 1 };
					res.emplace_back(temp);
				}
				len = 0;
			}
		}
		return res;
	}
};
