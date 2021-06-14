#pragma once
#include  <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();

		if (n < 2)return s;

		bool**dp = new bool*[n];
		for (int i = 0; i < n; i++)
			dp[i] = new bool[n];


		int maxlen = 1;
		int begin = 0;
		int i, j;
		for (j = 1; j < n; j++)
		{
			for (i = 0; i < j; i++)
			{
				if (s[i] != s[j])
					dp[i][j] = false;
				else
				{
					if ((j - i) < 3)
						dp[i][j] = true;
					else
						dp[i][j] = dp[i + 1][j - 1];
				}
				if (dp[i][j] && ((j - i + 1) > maxlen))
				{
					maxlen = j - i + 1;
					begin = i;
				}
			}

		}

		return s.substr(begin, maxlen);


	}
};