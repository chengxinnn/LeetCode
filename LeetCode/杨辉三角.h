#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans(numRows);
		ans[0] = { 1 };
		for (int i = 1; i < numRows; i++)
		{
			ans[i] = vector<int>(i + 1, 1);
			for (int j = 1; j < i; j++)
			{
				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
		}
		return ans;
	}


	vector<int> getRow(int rowIndex) {
		vector<int>ans(rowIndex + 1, 0);
		ans[0] = 1;
		for (int i = 1; i <= rowIndex; i++)
		{
			for (int j = i; j >= 0; j--)
				if (j >= 1 && j < i)
					ans[j] += ans[j - 1];
				else
					ans[j] = 1;
		}
		return ans;
	}

	string reverseWords(string s) {
		int size = s.size();
		int start = 0, end = 0, piv;
		while (start < size)
		{
			end = start;
			while (end < size && s[end] != ' ')
				end++;
			piv = end--;
			while (start < end)
				swap(s[start++], s[end--]);
			start = piv;
			while (start < size && s[start] == ' ')
				start++;
		}
		return s;
	}
};



void ini()
{
	Solution s;
	vector<vector<int>> ans = s.generate(5);
	for (auto &x : ans)
	{
		for (auto & y : x)
			cout << y << " ";
		cout << endl;
	}

	vector<int>az = s.getRow(3);
	for (auto & y : az)
		cout << y << " ";

	cout << s.reverseWords("Let's take LeetCode contest");
}