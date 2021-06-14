#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = nums1.size(), size2 = nums2.size();
		if ((size1 + size2) % 2 == 1)
			return getk(nums1, nums2, (size1 + size2) / 2 + 1);
		else
			return (getk(nums1, nums2, (size1 + size2) / 2) + getk(nums1, nums2, (size1 + size2) / 2 + 1));
	}
	int getk(vector<int>&nums1, vector<int>&nums2, int k)
	{
		int s1 = nums1.size(), s2 = nums2.size();
		int id1 = 0, id2 = 0;
		while (true)
		{
			if (id1 == s1)  return nums2[id2 + k - 1];
			if (id2 == s2)  return nums1[id1 + k - 1];
			if (k == 1) return min(nums1[id1], nums2[id2]);
			int pid1 = min(id1 + k / 2 - 1, s1 - 1);
			int pid2 = min(id2 + k / 2 - 1, s2 - 1);
			if (nums1[pid1] <= nums2[pid2])
			{
				k -= pid1 - id1 + 1;
				id1 = pid1 + 1;
			}
			else
			{
				k -= pid2 - id2 + 1;
				id2 = pid2 + 1;
			}
		}
		return 0;
	}
};



class Solution1 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		size1 = nums1.size(), size2 = nums2.size();
		int num = size1 + size2;
		if (num % 2)
			return gkthnum(nums1, nums2, num / 2 + 1);
		else
			return (gkthnum(nums1, nums2, num / 2 + 1) + gkthnum(nums1, nums2, num / 2)) / 2;

	}

	double gkthnum(vector<int>&nums1, vector<int>&nums2, int k)
	{
		int l = 0, r = 0;

		while (1)
		{
			if (l == size1) return nums2[r + k - 1];
			if (r == size2) return nums1[l + k - 1];
			if (k == 1)     return min(nums2[r], nums1[l]);

			int id1 = min(l + k / 2 - 1, size1 - 1);
			int id2 = min(r + k / 2 - 1, size2 - 1);

			if (nums1[id1] < nums2[id2])
			{
				k -= id1 - l + 1;
				l = id1 + 1;
				
			}
			else
			{
				k -= id2 - r + 1;
				r = id2 + 1;
				
			}
		}
	}

private:
	int size1;
	int size2;
};
void ini()
{
	Solution1 s;
	cout << s.findMedianSortedArrays(vector<int>({ 1,3 }), vector<int>({ 2 }));


	
}