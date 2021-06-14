#pragma once
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;
class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		int size = nums.size();
		int* presum = new int[size]();
		partial_sum(nums.begin(), nums.end(), presum);
		int start = presum[0], end = presum[size - 1];
		while (start < end)
		{
			int mid = start + ((end - start) >> 1);
			int pre = 0, count = 1;
			for (int i = 0; i < size; i++)
			{
				if (presum[i] - pre > mid)
				{
					count++;
					pre = presum[i - 1];
				}
			}
			if (count > m) start = mid + 1;
			else end = mid;
		}
		return start;
	}
};

void ini()
{
	Solution s;
	vector<int>nums({ 7,2,5,10,8 });
	std::cout << s.splitArray(nums, 2);

}