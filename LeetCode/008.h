#pragma once

#include <iostream>
#include <vector>
#include <string>
class Solution {
public:
	int myAtoi(std::string s) {


		bool neg = false;
		long long ans = 0;
		int i = 0,  size = s.size();

		while (i < size)
		{
			if (s[i] == ' ') i++;
			else break;
		}

		if (s[i] == '+' || s[i] == '-')
		{
			neg = s[i] == '-';
			i++;
		}

		while (i < size && ans <= INT_MAX)
		{
			if ('0' <= s[i] && s[i] <= '9')
				ans = ans * 10 + s[i++] - '0';
			else
				break;
		}

		return  neg ? ((-ans < INT_MIN) ? INT_MIN : -ans) : ((ans > INT_MAX) ? INT_MAX : ans);



	}
};