#pragma once

#include <iostream>
#include <vector>
using namespace  std;

class Solution {
public:


	vector<int> singleNumbers(vector<int>& nums) {
		int sum = 0;
		for (const auto & x : nums)
			sum ^= x;
		int i = 0;
		for (; i < 32; i++)
			if ((sum >> i) & 1)
				break;
		int l = 0, r = 0;
		for (const auto & x : nums)
			if ((x >> i) & 1)
				l ^= x;
			else
				r ^= x;
		return{ l, r };

	}
};

void ini()
{

	Solution s;
	s.singleNumbers(vector<int>({ 1,2,5,2 }));
}