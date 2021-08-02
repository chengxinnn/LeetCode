#pragma once
#include <vector>

#include <iostream>

using namespace std;


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int size = nums.size(), dp[32] = { 0 };
		for (const auto & x : nums)
			for (int i = 0; i < 32; i++)
				if ((x >> i) & 1)
					dp[i]++;
		int ans = 0;
		for (int i = 31; i >= 0; i--)
			if (dp[i] % 3)
				ans  += (i << i) ;
		return ans;
	}
};


void ini()
{

	Solution s;
	s.singleNumber(vector<int>({ 9,1,7,9,7,9,7 }));
}