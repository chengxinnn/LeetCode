#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*
 88
��֪����һ�����ǽ������е��������� nums �������е�ֵ���ػ�����ͬ��

�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ��ת ��
ʹ�����Ϊ [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
���磬 [0,1,2,4,4,4,5,6,6,7] ���±� 5 ������ת����ܱ�Ϊ [4,5,6,6,7,0,1,2,4,4] ��

���� ��ת�� ������ nums ��һ������ target �������дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С���� nums �д������Ŀ��ֵ target ���򷵻� true �����򷵻� false ��

���ӣ�https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
*/

class Solution
{
public:
	bool search(vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l < r)
		{
			while (l < r && nums[l] == nums[l + 1]) l++;
			while (l < r && nums[r] == nums[r - 1]) r--;
			int mid = l + (r - l) >> 1;
			if (nums[mid] == target) return true;
			if (nums[l] <= nums[mid])
			{
				if (nums[l] < target && target < nums[mid]) r = mid - 1;
				else l = mid + 1;
			}
			else
			{
				if (nums[mid] < target && target < nums[r]) l = mid + 1;
				else r = mid - 1;
			}
		}
		return nums[l] == target;
	}
};