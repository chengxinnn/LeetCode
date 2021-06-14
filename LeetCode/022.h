#pragma once
#include<vector>
using namespace std;
class Solution {
public:
	vector<string> ans;
	string temp;
	int time = 0;
	vector<string> generateParenthesis(int n) {
		ans.clear();
		time = n * 2;
		temp = string(time, '(');
		backtracking(0, 0);
		return ans;
	}

	void backtracking(int id, int left)
	{
		if (id == time)
		{
			ans.emplace_back(temp);
			return;
		}
		if (left <= 3)
		{
			temp[id] = '('; backtracking(id + 1, left + 1);
		}
		if (id + 1 - left < left)
		{
			temp[id] = ')'; backtracking(id + 1, left);
		}
		

		return;
	}
};