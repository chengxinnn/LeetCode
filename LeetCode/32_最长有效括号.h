#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution1 {
public:
	/*
	我的lowb代码， 时空间都很大， 超时
	*/
	int longestValidParentheses(string s) {
		using pii = pair<int, int>;
		stack<char>st;
		int size = s.size();
		vector<pii>ans;
		for (int i = 0; i < size; i++)
		{
			if (s[i] == '(') st.push(i);
			else if (!st.empty())
			{
				ans.push_back({ st.top(), i });
				st.pop();
			}
		}
		if (ans.empty()) return 0;
		sort(ans.begin(), ans.end());
		return get(ans, 0, ans.size() - 1);


	}
	int get(vector<pair<int, int>> & nums, int l, int r)
	{
		if (l == r) return 2;
		int maxm = (*max_element(nums.begin() + l, nums.begin() + r + 1, [](auto & x, auto & y) {return x.second < y.second; })).second;
		if (maxm - nums[l].first + 1 == ((r - l + 1) << 1))
			return maxm - nums[l].first + 1;
		else return max(get(nums, l + 1, r), get(nums, l, r - 1));
	}
};

class Solution
{
public:
	int longestValidParentheses(string & s) {
		int size = s.size();
		stack<int >st;
		for (int i = 0; i < size; i++)
		{
			if (s[i] == '(')
				st.push(i);
			else if (!st.empty())
			{
				s[st.top()] = '0';
				s[i] = '0';
				st.pop();
			}
		}
		int ans = 0;
		for (int i = 0; i < size; i++)
		{
			int j = i;
			while (s[j] == '0') j++;
			if (j - i > ans) ans = j - i;
			i = j;
		}
		return ans;
	}

};

void ini()
{
	Solution s;
	cout << s.longestValidParentheses(string("()(())")) << endl;;
}