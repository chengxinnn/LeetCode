#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int reversePairs(vector<int>& nums) {
		ans = 0;
		vector<int>temp(nums.size());
		sortt(nums, temp,0, nums.size() - 1);
		return ans;
	}

	void sortt(vector<int>&nums, vector<int>&temp,int l, int r)
	{
		if (l < r)
		{
			int mid = l + ((r - l) >> 1);
			sortt(nums, temp,  l, mid);
			sortt(nums, temp, mid + 1, r);
			
			int left = mid, right = r, id = r;
			while (left >= l && right >= mid+1)
			{
				if (nums[left] > nums[right]) {
					temp[id--] = nums[left--];
					ans += right - mid;
				}
				else temp[id--] = nums[right--];
			}
			while(left >= l)temp[id--] = nums[left--];
			while(right >= mid+ 1) temp[id--] = nums[right--];

			for (int i = l; i <= r; i++)
				nums[i] = temp[i];
		}
	}
private:
	int ans;
};

void ini()
{
	Solution s;
	cout << s.reversePairs(vector<int>{7, 5, 6, 4});
}