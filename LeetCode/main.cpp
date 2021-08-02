#pragma once
#include <crtdbg.h>
#include "util.h"


#include <iostream>

#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		int size = nums.size(), midpos = (k - 1) >> 1, id = -1;
		if (!size)  return{};
		bool odd = k & 1;
		vector<double> ans(size - k + 1, 0);
		auto getmidnum = [&]()->double {
			auto it = win.begin();
			for (int i = 0; i < midpos; ++i) ++it;
			return odd ? *it : (*it) *0.5 + *(++it) * 0.5;
		};
		for (int i = 0; i < k; ++i)
			win.insert(nums[i]);
		ans[++id] = getmidnum();
		for (int left = 0, right = k; right < size; ++right)
		{
			win.erase(nums[left++]);
			win.insert(nums[right]);
			ans[++id] = getmidnum();
		}
		return ans;
	}

private:
	multiset<int>win;
};

int main()
{
	vector<int>ans{ 5,5,8,1,4,7,1,3,8,4 };
	Solution s;
	s.medianSlidingWindow(ans, 8);


	int x; cin >> x;
	return 0;
}