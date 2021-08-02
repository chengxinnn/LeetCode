#pragma once

#include <iostream>
#include <vector>

using namespace std;
/*
给你两个正整数数组 nums1 和 nums2 ，数组的长度都是 n 。数组 nums1 和 nums2 的 绝对差值和 定义为所有 |nums1[i] - nums2[i]|（0 <= i < n）的 总和（下标从 0 开始）。
你可以选用 nums1 中的 任意一个 元素来替换 nums1 中的 至多 一个元素，以 最小化 绝对差值和。在替换数组 nums1 中最多一个元素 之后 ，返回最小绝对差值和。因为答案可能很大，所以需要对 109 + 7 取余 后返回。
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