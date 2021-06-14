#pragma once
#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

	vector<string>ans;
	vector<string>printNumbers(int n)
	{
		string nums(n, '0');
		ans.clear();
		back(0, n, nums);
		return ans;
	}

	void back(int id,const int& n, string&nums)
	{
		if (id == n)
		{
			//cout << nums << " ";

			int i = 0;
			while (i < n && nums[i] == '0') i++;
			ans.emplace_back(string(nums.substr(i)));
			return;
		}
		else
		{
			for (char i = '0'; i <= '9'; i++)
			{
				nums[id] = i;
				back(id + 1, n, nums);
			}
		}
		
	}
};