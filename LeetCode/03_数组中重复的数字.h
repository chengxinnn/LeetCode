#pragma once
#include <iostream>
#include <set>
#include <vector>
using namespace std;;


/*
һ���ⷨ��ʱ�����ȵĻ�������set
*/
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int size = nums.size();
		set<int>s;
		for (const auto & x : nums)
		{
			if (s.count(x))
				return x;
			else
				s.insert(x);
		}
		return 0;

	}

	/*����ǿռ�Ҫ��O(1)�Ļ�����ʹ��һ��ԭ��hash ��
	��Ϊ��Ŀ�и���Ԫ����0 - n-1�ģ����ǿ����뵽��Ԫ��i�ŵ������λ��i��
	�����ŵ���ȷ��λ�ã���������������ط���Ԫ�����ʱ��˵���������ظ���
	*/
	int findRepeatNumber(vector<int>& nums) {
		int size = nums.size();
		for (int i = 0; i < size; i++)
			while (nums[i] != i)
			{
				if (nums[i] == nums[nums[i]]) return nums[i];
				swap(nums[i], nums[nums[i]]);
			}
		return 0;
	}

};


