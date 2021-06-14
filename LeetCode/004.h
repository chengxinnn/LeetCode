#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int med(int lp, int rp)
{
	int sum = lp + rp;
	if (sum >= 0)
		return sum / 2.0 + 0.5;
	else
	{
		return -int(-double(sum) + 0.5);
	}
}

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();

		if (n > m)  //��֤����1һ����� //Ϊ�˼ӿ��ٶ� �Գ��ȶ̵Ľ��ж���
		{
			return findMedianSortedArrays(nums2, nums1);
		}
		int LMax1 = 0, LMax2 = 0, RMin1 = 0, RMin2 = 0, c1, c2, lo = 0, hi = n;
		while (lo <= hi) {
			c1 = (hi + lo + 1) / 2;
			c2 = (m + n) / 2 - c1;

			LMax1 = (c1 == 0) ? INT_MIN : nums1[c1 - 1];
			RMin1 = (c1 == n) ? INT_MAX : nums1[c1];
			LMax2 = (c2 == 0) ? INT_MIN : nums2[c2 - 1];
			RMin2 = (c2 == m) ? INT_MAX : nums2[c2];

			if (LMax1 > RMin2)
				hi = c1 - 1;
			else if (LMax2 > RMin1)
				lo = c1 + 1;
			else
				break;
		}
		if ((m + n) % 2)
			return min(RMin1, RMin2);
		else
			return ((int64_t)max(LMax1, LMax2) + (int64_t)min(RMin1, RMin2)) / 2.0;
	}





	double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();

		if (n > m)  //��֤����1һ�����
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		// Ci Ϊ��i������ĸ�,����C1Ϊ2ʱ��ʾ��1������ֻ��2��Ԫ�ء�LMaxiΪ��i�����������Ԫ�ء�RMiniΪ��i�����������Ԫ�ء�
		int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //����Ŀǰ���������'#'��������1��2*n����

		while (lo <= hi)   //����
		{
			c1 = (lo + hi) / 2;  //c1�Ƕ��ֵĽ��
			c2 = m + n - c1;

			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
			RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

			if (LMax1 > RMin2)
				hi = c1 - 1;
			else if (LMax2 > RMin1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
	}


};