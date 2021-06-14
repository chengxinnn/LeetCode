#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution
{
public:
	/*
	给你一个字符串?s?和一个字符规律?p，请你来实现一个支持 '.'?和?'*'?的正则表达式匹配。
	'.' 匹配任意单个字符
	'*' 匹配零个或多个前面的那一个元素
	*/
	bool isMatch(string s, string p)
	{
		int ssize = s.size(), psize = p.size();
		bool ** dp = new bool *[ssize + 1];
		for (int i = 0; i < ssize + 1; i++) dp[i] = new bool[psize + 1]();
		dp[0][0] = 1;
		for (int i = 1; i < ssize ; i++) 
			if(p[i] == '*')
				dp[0][i + 1] = dp[0][i - 1];
		for (int i = 0; i < ssize; i++)
		{
			for (int j = 0; j < psize; j++)
			{
				if (p[j] == '*')
				{
					if ( (s[i] != p[j - 1]) && (p[j - 1] != '.'))
						dp[i + 1][j + 1] = dp[i + 1][j - 1];
					else
						dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i + 1][j - 1] || dp[i][j + 1]);
				}
				else if (p[j] == '.' || s[i] == p[j])
				{
					dp[i + 1][j + 1] = dp[i][j];
				}
			}
		}
		return dp[ssize][psize];
	}

};
void ini()
{
	Solution s;
	cout << s.isMatch(string("aaa"), string("ab*a*c*a")) << endl;
	cout << s.isMatch(string("mississippi"), string("mis*is*p*.")) << endl;
}