#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
	int minCut(string s) {
		int size = s.size();
		if (size <= 1) return 0;
		//int *dp = new int[size + 1];
		vector<int>dp(size + 1, size); dp[0] = -1;
		for (int i = 1; i< size + 1; i++)dp[i] = size;

		for (int i = 0; i < size; i++)
		{
			finds(s, i, i + 1, dp);
			finds(s, i, i, dp);
		}
		return dp[size];

	}
	void finds(string &s, int left, int right, vector<int>&dp)
	{
		int size = s.size();
		while (left >= 0 && right <size &&s[left] == s[right])
		{
			dp[right + 1] = min(dp[left] + 1, dp[right + 1]);
			left--; right++;
		}

	}
};