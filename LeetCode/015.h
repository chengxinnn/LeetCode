#pragma once

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	//1... 超时了
	vector<vector<int>> threeSum(vector<int>& nums) {
		int nsize = nums.size(), i, j, k;
		vector<vector<int>>ans;
		if (nsize < 3)  return ans;

		vector<int> temp;
		//不管了 first sort 左边负数右边正数
		sort(nums.begin(), nums.end());
		for (i = 0; i < nsize - 2 && nums[i] <= 0; i++)
		{
			if (i != 0 && nums[i] == nums[i - 1]) continue;
			for (j = nsize - 1; j >= 2 && nums[j] >= 0; j--)
			{
				if (j != nsize - 1 || nums[j] == nums[j + 1]) continue;
				for (k = i + 1; k < j; k++)
					if (nums[i] + nums[j] + nums[k] == 0)
					{
						temp = { nums[i], nums[j], nums[k] };
						ans.emplace_back(temp);
						continue;
					}
			}
		}
		return ans;
	}

	vector<vector<int>> threeSum1(vector<int>& nums) {
		int nsize = nums.size(), i, j, k;
		vector<vector<int>>ans;
		vector<int> pre, temp;

		if (nsize < 3)  return ans;

		sort(nums.begin(), nums.end());

		for (i = 0; i < nsize - 2 && nums[i] <= 0; i++)
		{
			if (i != 0 && nums[i] == nums[i - 1]) continue;
			j = i + 1; k = nsize - 1;
			while (j < k)
			{
				if (nums[i] + nums[j] + nums[k] == 0)
				{
					temp = { nums[i], nums[j], nums[k] };
					if (temp != pre)
						ans.emplace_back(temp);
					pre = temp;
					k--; j++;
					continue;
				}
				else if (nums[k] + nums[j] > -nums[i])
					k--;
				else
					j++;
			}
		}
		return ans;
	}
};