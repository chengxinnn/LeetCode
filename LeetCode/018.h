#pragma once

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>>ans;
		vector<int>temp(4, 0), pre;
		int nsize = nums.size();
		if (nsize < 4) return ans;
		int i = 0, j = nsize - 1, k, l, isum, ksum;
		sort(nums.begin(), nums.end());

		while (i <= j - 3)
		{
			if (i != 0 && nums[i] == nums[i - 1]) { i++; continue; }
			if (j != nsize - 1 && nums[j] == nums[j + 1]) { j--; continue; }
			isum = nums[i] + nums[j];
			k = i + 1;  l = j - 1;
			while (k < l)
			{
				ksum = nums[k] + nums[l] + isum;
				if (ksum == target)
				{
					temp = { nums[i], nums[j], nums[k], nums[l] };
					if (pre != temp)
						ans.emplace_back(temp);
					pre = temp;
					k++;
				}
				else if (ksum > target)
					l--;
				else
					k++;
			}
			if (isum >= target)
				j--;
			else
				i++;

		}
		return ans;
	}
};
