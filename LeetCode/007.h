#pragma once
#include <exception>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		bool neg = x >= 0 ? false : true;

		int ans = 0;

		while (x != 0)
		{
			if (ans >= INT_MAX / 10)
				return 0;
			ans = ans * 10 + abs(x) % 10;
			x = x / 10;
		}
		return neg ? -ans : ans;

	}
};