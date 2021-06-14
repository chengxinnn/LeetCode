#pragma once
#include <vector>
#include <algorithm>
using namespace std;

/*
给你一个整数数组 nums ，其中可不包含复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
*/
class Solution {
public:
	vector<vector<int>>ans = { {} };
	vector<int>temp;

	vector<vector<int>> subsets(vector<int>& nums) {
		back(nums, 0);
		return ans;
	}
	void back(vector<int>&nums, int start)
	{
		if (start == nums.size())return;
		for (int i = start; i < nums.size(); i++)
		{
			temp.push_back(nums[i]);
			ans.push_back(temp);
			back(nums, i + 1);
			temp.pop_back();
		}
	}


	vector<vector<int>> subsets1(vector<int>& nums) {
		vector<vector<int>>ans = { {} };
		vector<int>temp;
		int len;
		for (int i = 0; i < nums.size(); i++)
		{
			len = ans.size();
			for (int j = 0; j < len; j++)
			{
				temp = ans[j];
				temp.push_back(nums[i]);
				ans.push_back(temp);
			}
		}
		return ans;
	}
};


/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
*/
class Solution {
private:
	vector<vector<int>> res;
	vector<int> temp;
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		back(nums, 0);
		return res;
	}
	void back(vector<int>& nums, int start) {
		res.push_back(temp);
		for (int i = start; i<nums.size(); i++) {
			if (i != start&&nums[i] == nums[i - 1])//去重
				continue;
			temp.push_back(nums[i]);
			back(nums, i + 1);
			temp.pop_back();//回溯
		}
		return;
	}
};