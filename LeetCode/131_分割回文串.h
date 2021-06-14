#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<string>temp;
	vector<vector<string>> ans;
	vector<vector<int>>dp;
	vector<vector<string>> partition(string s) {
		temp.clear(); ans.clear(); dp.clear();
		int size = s.size();
		dp = getDp(s);
		back(s, 0);
		return ans;
	}

	void back(string & s, int start)
	{
		if (start >= s.size()) ans.push_back(temp);
		for (int i = start; i < s.size(); i++)
		{
			if (dp[start][i])
			{
				temp.emplace_back(s.substr(start, i - start + 1));
				back(s, i + 1);
				temp.pop_back();
			}
		}
	}

	vector<vector<int>> getDp(string &s)
	{
		int size = s.size();
		vector<vector<int>>dp(size + 1, vector<int>(size + 1, 1));
		for (int i = size - 1; i >= 0; i--)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (s[i] != s[j]) dp[i][j] = 0;
				else dp[i][j] = dp[i + 1][j - 1];
			}
		}
		return dp;
	}



};




void ini()
{
	Solution s;
	vector<vector<string>>ans = s.partition("aabbac");
	for (auto & x : ans)
	{
		for (auto & y : x)
		{
			cout << y << " ";
		}
		cout << endl;
	}

}