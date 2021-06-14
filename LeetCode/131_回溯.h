#pragma once
#include <vector>

using namespace std;

class solution
{
public:
	vector<vector<string>> res;
	vector<string>path;
	string temp;
	bool*dp;
	void backtracking(string s, int start)
	{
		int size = s.size();
		if (start >= s.size())
		{
			res.emplace_back(path);
			return;
		}

		for (int i = start; i < size; i++)
		{
			if (dp[start*size + i])
			{
				temp = s.substr(start, i - start + 1);
				path.emplace_back(temp);
			}
			else
				continue;
			backtracking(s, i + 1);
			path.pop_back();

		}

	}

	vector<vector<string>> partition(string s)
	{
		int size = s.size(), i, j;
		dp = (bool*)malloc(size*size*sizeof(bool));
		memset(dp, false, size*size*sizeof(bool));
		for (i = 0; i < size; i++)
			dp[i*size + i] = true;
		for (j = 1; j < size; j++)
			for (i = 0; i < j; i++)
				dp[i*size + j] = (s[i] == s[j] && (j - i <= 2 || dp[(i + 1) * size + j - 1]));

		res.clear();
		path.clear();
		backtracking(s, 0);
		return res;

	}
};