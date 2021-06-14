#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
public:
	string largestNumber(vector<int>&nums)
	{
		auto cmp = [](int a, int b) {string as = to_string(a); string bs = to_string(b); return as + bs > bs + as; };
		sort(nums.begin(), nums.end(), cmp);
		string ans;
		cout << ans[0];
		for (const int& num : nums)
			if (num != 0 || ans[0] != '0')
				ans += to_string(num);
		return ans;
	}
};

void ini()
{
	Solution s;
	vector<int>nums = {0,0,0,0 };
	cout << s.largestNumber(nums);
}