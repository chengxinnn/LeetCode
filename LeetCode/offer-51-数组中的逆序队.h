#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int reversePairs(vector<int>& nums) {
		ans = 0;
		int size = nums.size();
		vector<int>temp(size, 0);
		sort(nums, temp, 0, size - 1);
		return ans;
	}
private:
	void sort(vector<int>& nums, vector<int>& temp, int l, int r)
	{
		if (l < r)
		{
			int mid = l + ((r - l) >> 1);
			sort(nums, temp, l, mid);
			sort(nums, temp, mid + 1, r);
			int left = mid, right = r, id = r;
			while (left >= l && right >= mid + 1)
			{
				if (nums[left] > nums[right])
				{
					temp[id--] = nums[left--];
					ans += right - mid;
				}
				else
					temp[id--] = nums[right--];
			}
			while (left >= l) temp[id--] = nums[left--];
			while (right >= mid + 1) temp[id--] = nums[right--];
			for (id = l; id <= r; id++)
				nums[id] = temp[id];
		}
	}

private:
	int ans;
};

void ini()
{
	Solution s;
	cout << s.reversePairs(vector<int>({ 7,5,6,4 }));

}