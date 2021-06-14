#pragma once
#include <iostream>

using namespace std;

class Solution
{
public:
	string convertToTitle(int n)
	{
		if (n < 1) return "";
		string ans = "";
		while (n)
		{
			n--;
			ans.push_back(n % 26 + 'A');
			n /= 26;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}

	string convertToTitlee(int n, int time)
	{
		if (n < 1) return "0";
		string ans = "";
		while (n)
		{
			n--;
			ans.push_back(n%time + '0');
			n /= time;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};