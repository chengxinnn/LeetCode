#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

/*
������ 17.21. ֱ��ͼ��ˮ��
����һ��ֱ��ͼ(Ҳ����״ͼ)���������˴�����ԴԴ���ϵص�ˮ��
���ֱ��ͼ�ܴ����ˮ��?ֱ��ͼ�Ŀ��Ϊ 1��
*/
class Solution {
public:
	int trap(vector<int>& height) {
		vector<int>sk;
		int ans = 0;
		int size = height.size();
		for (int i = 0; i < size; i++)
		{
			if (sk.empty() || height[i] < height[sk.back()])
				sk.push_back(i);
			else if (height[i] == height[sk.back()])
				sk.back() = i;
			else
			{
				while (sk.size() && height[i] > height[sk.back()])
				{
					int cur = sk.back();
					sk.pop_back();
					if (!sk.empty())
					{
						int h = min(height[sk.back()], height[i]) - height[cur];
						ans += h * (i - sk.back() - 1);
					}
				}
				sk.push_back(i);
			}
		}
		return ans;
	}

	//˫ָ��  ���ľ����������ȥ���ӵ��������ˮ��������
	int trap1(vector<int>&height)
	{
		int size = height.size();
		int left = 0, right = size - 1;
		int high = 1, vol = 0;
		int sum = accumulate(height.begin(), height.end(), 0);
		while (left <= right)
		{
			while (left <= right && height[left] < high)
				left++;
			while (left <= right && height[right] < high)
				right--;
			vol += right - left + 1;
			high++;
		}
		return vol - sum;
	}
};



void ini()
{
	Solution s;
	vector<int>nums = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int area = s.trap1(nums);
	cout << area;

}