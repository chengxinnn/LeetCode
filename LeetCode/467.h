#pragma once
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
	int findSubstringInWraproundString(string p) {
		p = '.' + p;
		int n = p.size();
		map<char, int> smap;

		int dp = 1;
		for (int i = 1; i < n; i++)
		{
			//与上一个字符相比是否连续
			if (p[i] - p[i - 1] == 1 || (p[i] - p[i - 1] == -25))
				dp = dp + 1;
			else
				dp = 1;

			/*if (smap.count(p[i]) != 0)
				smap[p[i]] = max(smap[p[i]], dp);
			else
				smap[p[i]] = dp;*/
			smap[p[i]] = max(smap[p[i]], dp);

		}

		int ans = 0;
		map<char, int>::iterator it = smap.begin();
		while (it != smap.end())
		{
			ans += it->second;
			it++;
		}


		return ans;

	}
};
