#pragma once
#include <iostream>

#include <string>
using namespace std;

class Solution
{
public:
	bool isNumber(string  s) {
		bool num = 0;
		int i = 0, size = s.size();
		while (i < size && s[i] == ' ') i++;

		//整数部分
		if (i < size && (s[i] == '+' || s[i] == '-')) i++;
		while (i < size && isdigit(s[i])) { i++; num = 1;}
		//小数部分
		if (i < size && s[i] == '.')
		{
			//判断前后至少有一侧要有数字。
			if ((i > 0 && isdigit(s[i - 1])) || (i < size - 1 && isdigit(s[i + 1])))
			{
				i++;
				while (i < size && isdigit(s[i])) i++;
				num = 1;
			}
			else
				return false;
		}
		//e部分
		if (i < size && (s[i] == 'e' || s[i] == 'E'))
		{
			//整数部分
			++i;
			if (i < size && (s[i] == '+' || s[i] == '-')) i++;
			if (i < size && isdigit(s[i])) {
				while (i < size && isdigit(s[i])) i++;
			}
			else
				return 0;
		}

		while (i < size && s[i] == ' ') i++;

		return i == size && num;

	}
};


void ini()
{
	Solution s;
	cout << s.isNumber("2e0") << endl;
}