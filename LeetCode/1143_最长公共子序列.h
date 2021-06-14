#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 *
 *给定两个字符串?text1 和?text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的?子序列?是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
 **/

class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int s1 = text1.size(), s2 = text2.size();
		vector<vector<int>>dp(2, vector<int>(s2 + 1, 0));
		int now = 0, pre = 1;
		for (int i = 0; i < s1; i++)
		{
			for (int j = 0; j < s2; j++)
				dp[now][j + 1] = text1[i] == text2[j] ? dp[pre][j] + 1 : max(dp[now][j], dp[pre][j + 1]);
			swap(now, pre);
		}
		return dp[pre][s2];
	}
};

void ini(int j = 0)
{
	Solution s;
	cout << s.longestCommonSubsequence("3142", "124");

	
}

