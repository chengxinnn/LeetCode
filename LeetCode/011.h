#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		//�б��Ľⷨ��Ȼ��O(n2),��Ȼ��ô���ǲ��еģ�ʹ����������õķ�������˫ָ�뷨��
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