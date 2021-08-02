#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/*
	153 ��ת�����������Сֵ ���ظ�
	�����Ŀ����Ҫ˼·���ö��ַ������ϵرƽ���Сֵ��

	һ����Կ��Է�Ϊ���������ԭ����ϴ�һ��������ת�����࣬��һ�����������Ҳࡣ
	�ɴ����ǿ�����������м�ֵ�����жϣ�
	���м�ֵС�������Ҳ��ֵʱ��˵���ڵ�ǰ���֣������ǵ����ģ���СֵӦ���ڰ����м�ֵ�����
	���м�ֵ���������Ҳ��ֵʱ��˵���Ҳ෢������ת����СֵӦ���ڲ������м�ֵ���Ҳࡣ
	*/
	int findMin153(vector<int>& nums) {
		int size = nums.size();
		int left = 0, right = size - 1, mid = 0;
		while (left < right)
		{
			mid = (left + right) >> 1;
			if (nums[mid] < nums[right]) right = mid;
			else  left = mid + 1;
		}
		return nums[left];
	}
   	/*
	154, ���ظ�Ԫ�� 
	һ�ַ�ʽ�� �ų��ظ�Ԫ�صĸ��š��������������
	*/
	int findMin154(vector<int>& nums)
	{ 
		int size = nums.size();
		int l = 0, r = size - 1;
		while (l < r)
		{
			while (l < r && nums[l] == nums[l + 1]) l++;
			while (r > l && nums[r] == nums[r - 1]) r--;
			int mid = l + ((r - l) >> 1);
			if (nums[mid] > nums[r])
				l = mid + 1;
			else
				r = mid;
		}
		return nums[l];
	}
	/*
	154, ���ظ�Ԫ��
	����һ��˼���ǣ� ���м�ֵС�ڴ����Ҳ�ֵ��ʱ�򣬴���ʽ��ԭ����һ����
	���м�ֵ�����Ҳ��ʱ����Сֵ�������м�ֵ����࣬Ҷ�����м�ֵ���Ҳࡣ���Ǽ�Ȼ���м�ֵ��ȣ���Ȼ�������ұ߽硣��С�ұ߽硣
	*/
	int findMin1542(vector<int>& nums)
	{
		int size = nums.size();
		int l = 0, r = size - 1;
		while (l < r)
		{
			int mid = l + ((r - l) >> 1);
			if (nums[mid] > nums[r])
				l = mid + 1;
			else if (nums[mid] < nums[r])
				r = mid;
			else
				r--;

		}
	}

};

int ini()
{
	Solution s;
	vector<int>ss = { 1, 2,3,4,5 };
	cout << s.findMin(ss);
	return 0;
}