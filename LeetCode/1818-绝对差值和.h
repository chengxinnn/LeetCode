#pragma once

#include <iostream>
#include <vector>

using namespace std;
/*
������������������ nums1 �� nums2 ������ĳ��ȶ��� n ������ nums1 �� nums2 �� ���Բ�ֵ�� ����Ϊ���� |nums1[i] - nums2[i]|��0 <= i < n���� �ܺͣ��±�� 0 ��ʼ����
�����ѡ�� nums1 �е� ����һ�� Ԫ�����滻 nums1 �е� ���� һ��Ԫ�أ��� ��С�� ���Բ�ֵ�͡����滻���� nums1 �����һ��Ԫ�� ֮�� ��������С���Բ�ֵ�͡���Ϊ�𰸿��ܴܺ�������Ҫ�� 109 + 7 ȡ�� �󷵻ء�
*/
class Solution {
public:
	int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
		int size = nums1.size();
		int max = 0, ans = 0, id = size + 1, id1;
		for (int i = 0; i < size; ++i)
		{
			nums2[i] -= nums1[i];
			ans += abs(nums2[i]);
			if (abs(nums2[i]) > max)
			{
				max = abs(nums2[i]);
				id = i;
			}
		}
		if (id == size + 1) return ans;
		max = INT_MAX;
		for (int i = 0; i < size; ++i)
		{
			if (abs(nums1[i] - nums2[id] - nums1[id]) < max)
			{
				max = abs(nums1[i] - nums2[id] - nums1[id]);
				id1 = i;
			}
		}
		return  ans - abs(nums2[id]) + abs(nums1[id1] - nums2[id] - nums1[id]);
	}
};