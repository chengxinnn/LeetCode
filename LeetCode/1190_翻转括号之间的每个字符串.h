#pragma once
#include<iostream>
#include<vector>
#include <string>

using namespace std;

class Solution {
public:
	string reverseParentheses(string & s) {
		vector<int>st;
		string ans;
		int size = s.size();
		for (int i = 0; i < size; i++)
		{
			if (s[i] == '(')
				st.push_back(i);
			else if (s[i] == ')')
			{
				reverse(s.begin() + st.back() + 1, s.begin() + i);
				st.pop_back();
			}
		}
		for (const auto & ch : s)
			if (ch != '(' && ch != ')')
				ans += ch;
		return ans;
	}
};

void ini()
{
	Solution s;
	string ans = s.reverseParentheses(string("(a(icu)b)"));
	cout << ans << endl;



}