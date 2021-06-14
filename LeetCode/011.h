#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		//残暴的解法必然是O(n2),显然这么做是不行的，使得面积最大，最好的方法还是双指针法。
		int i = 0, j = height.size() - 1;
		long long ans = 0, minlen;

		while (i < j)
		{
			minlen = min(height[i], height[j]);
			ans = max(ans, minlen *(j - i));
			if (height[i] < height[j]) i++;
			else j--;

		}

		return ans;

	}
};