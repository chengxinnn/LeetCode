#pragma once
#include <iostream>

using namespace std;

#define LIMIT 0x80000000

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		if (dividend == INT_MAX && divisor == -1) return INT_MAX;
		bool neg = (dividend ^ divisor) < 0;
		int64_t t = (dividend == INT_MIN) ? INT_MAX : abs(dividend);
		int64_t d = (divisor == INT_MIN) ? INT_MAX : abs(divisor);
		int res = 0;
		for (int i = 31; i >= 0; i--)
		{
			if ((t >> i) >= d)
			{
				res += 1 << i;
				t -= d << i;
			}
		}
		return neg ? -res : res;

	}
};