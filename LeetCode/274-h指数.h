#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hIndex(vector<int>& nums)
{
	int size = nums.size();
	sort(nums.begin(), nums.end());
	int l = 0, r = size, mid, cit;
	while (l < r)
	{
		mid = ((r - l) >> 1) + l, cit = size - mid;
		if (nums[mid] > cit)
			r = mid;
		else if (nums[mid] < cit)
			l = mid + 1;
		else return cit;
	}
	return size - l;
}

int ini()
{
	return hIndex(vector<int>({ 1,3,1,2 }));
}

