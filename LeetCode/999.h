#pragma once
#include <string>
#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	string reversestring(string str)
	{
		int size = str.size();
		string temp;
		size_t it = 0;

		for (int i = 0; i < size; i++)
		{
			if (str[i] != ')')
				temp.push_back(str[i]);
			else
			{

				it = temp.rfind('(', it );
				reverse(temp.begin() + it + 1, temp.end());
				temp.push_back(str[i]);
			}
		}
		string ans;
		for (int i = 0; i < size; i++)
		{
			if (temp[i] != '(' && temp[i] != ')')
				ans += temp[i];
		}
		return ans;
	}
};



int getMinTran(vector<int>&data, int num)
{
	sort(data.begin(), data.end(), [](int&a, int&b) {return a > b; });
	int ans = 0, len = 0;
	for (int i = 0; i < data.size(); i++)
	{
		ans += 1;
		len += data[i];
		if (len >= num)
			return ans;
	}
	return -1;
}



int ini()
{
	int num = 0;
	cin >> num;
	vector<int>data(num);
	for (int i = 0; i < num; ++i)
		cin >> data[i];
	int ans = getMinTran(data, num);
	cout << ans;
	return 0;
}