#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		while (l < r)
		{
			int mid = l + ((r - l) >> 1);
			if (nums[mid] >= nums[l])
			{
				if (nums[l] > nums[r]) l = mid + 1;
				else r = mid - 1;
			}
			else
				r = mid;
		}
		return nums[l];
	}

	int findMin1(vector<int>& nums) {
		int size = nums.size();
		int left = 0, right = size - 1, mid = 0;
		while (left < right)
		{
			mid = (left + right) >> 1;
			if (nums[mid] < nums[right]) right = mid;
			else  left = mid + 1;
		}
		return nums[left];

	}
};

int ini()
{
	Solution s;
	vector<int>ss = { 1, 2,3,4,5 };
	cout << s.findMin1(ss);
	return 0;
}