#pragma once

#include <vector>
using namespace std;
class Solution {
public:

	string str[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	string temp;
	vector<string> ans;
	int dsize;

	vector<string> letterCombinations(string digits) {
		ans.clear();
		dsize = digits.size();
		temp.assign(dsize, '0');

		backtracking(digits, 0);
		return ans;

	}

	void backtracking(string& digits, int digitsid)
	{
		if (digitsid == dsize)
		{
			ans.emplace_back(temp);
			return;
		}
		string now = str[digits[digitsid] - '2'];
		for (const char & ch : now)
		{
			temp[digitsid] = ch;
			backtracking(digits, digitsid + 1);
		}
	}
};