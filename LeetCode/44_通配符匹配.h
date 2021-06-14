#pragma once
#include <array>
#include <string>
#include <iostream>

using namespace std;


/* =======================超时=========================*/
// 多个***时递归层次过深
class Solution1 {
public:
	bool isMatch(string s, string p) {
		int ssize = s.size(), psize = p.size();
		return match(s, p, 0, 0);
	}

	bool match(string & s, string & p, int si, int pi)
	{
		if (si == s.size())
		{
			while (pi < p.size() && p[pi] == '*') pi++;
			return pi == p.size();
		}
		if (p[pi] == '*')
		{
			for (int i = si; i <= s.size(); i++)
				if (match(s, p, i, pi + 1))
					return true;
		}
		else if (p[pi] == '?')
		{
			return  match(s, p, si + 1, pi + 1);
		}
		else
		{
			if (p[pi] == s[si])
				return match(s, p, si + 1, pi + 1);
		}
		return false;
	}
};


class Solution {
public:
	bool isMatch(string s, string p) {
		int ssize = s.size(), psize = p.size();
		bool ** dp = new bool*[ssize + 1]();
		for (int i = 0; i < ssize + 1; i++) dp[i] = new bool[psize + 1]();
		//vector<vector<int>>dp(ssize + 1, vector<int>(psize + 1, 0));
		dp[0][0] = 1;
		for (int pi = 0; pi < psize && p[pi] == '*'; pi++)
			dp[0][pi + 1] = 1;

		for (int i = 0; i < ssize; i++)
		{
			for (int j = 0; j < psize; j++)
			{
				if (p[j] == '*')
					dp[i + 1][j + 1] = dp[i][j + 1] | dp[i + 1][j];
				else if (p[j] == '?' || p[j] == s[i])
					dp[i + 1][j + 1] = dp[i][j];
			}
		}

		return dp[ssize][psize];
	}
};

void ini()
{
	Solution s;
	cout << s.isMatch(string("abcabczzzde"), string("*abc???de*")) << endl;
	cout <<s.isMatch(string("aa"), string("a")) << endl;
}