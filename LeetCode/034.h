#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int size = nums.size(), left = 0, right = size, mid, ok = 0;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] == target) { ok = 1; break; }
			if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}

		if (size == 0 || !ok) return{ -1, -1 };
		vector<int> ans;
		while (nums[mid] == target) mid--;
		ans.emplace_back(mid + 1);
		while (nums[++mid] == target) mid++;
		ans.emplace_back(mid - 1);
		return ans;


	}
};