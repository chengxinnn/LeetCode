#pragma once

#include <iostream>

using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		string ans = "";

		int cnt = 0;
		int i = a.size() - 1;
		int j = b.size() - 1;
		while (i >= 0 || j >= 0 || cnt)
		{
			if (i >= 0) cnt += a[i--] - '0';
			if (j >= 0) cnt += b[j--] - '0';
			ans.push_back(cnt % 2 + '0');
			cnt /= 2;
		}
		reverse(ans.begin(), ans.end());
		return ans;

	}
};