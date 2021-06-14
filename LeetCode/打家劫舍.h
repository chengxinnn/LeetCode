#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
	/*
	��ҽ��� 1
	����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�
	Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
	����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�
	*/
public:
	/*
	�����dp����
	˼��˼·
	1.���ֽ׶Σ�����������ǿռ����������仮��Ϊ��ͬ�Ľ׶�
	2.״̬ת�Ʒ��̡�����һ���׶ε�״̬�Ƶ����׶ε�״̬��
	3.Ѱ�ұ߽�������
	*/
	int rob1(vector<int>&nums)
	{
		int size = nums.size();
		if (size == 0) return 0;
		if (size == 1) return nums[0];
		vector<int>dp(size);
		dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < size; ++i)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[size - 1];
	}
	int rob11(vector<int>&nums)
	{
		int size = nums.size();
	    vector<	vector<int>>dp(size + 1, vector<int>(2, 0));
		for (int i = 1; i <= size; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = dp[i - 1][0] + nums[i - 1];
		}
		return max(dp[size][0], dp[size][1]);
	}
};

class Solution2
{
	/*
	��ҽ���2
	��λ��ס������
	*/
public:
	/*
	��һ��˼·
	ÿ��������ѭ������������ǲ���ֱ�Ӵ���
	���ǵ����Ǻ������һ��nums[size - 1]��ʱ�򣬾��ƻ���ѭ��������ֻ��Ҫ���ǡ�0- size-2]��
	Ҫ͵���һ��Ԫ�أ��Ͳ���͵ȡ��һ��Ԫ�أ����Դӵڶ���Ԫ�ؿ�ʼ��1 - size-1�����������һ��Ԫ�ص����ֵ��
	Ȼ��ȡ����ֵ��
	*/
	int rob2(vector<int>&nums)
	{
		int size = nums.size();
		if (size == 0) return 0;
		if (size <= 2) return *max_element(nums.begin(), nums.end());
		vector<int>dp1(size, 0), dp2(size, 0);
		dp1[1] = nums[0]; 
		for (int i = 2; i < size; ++i)
			dp1[i] = max(dp1[i - 2] + nums[i - 1], dp1[i - 1]);

		dp2[0] = nums[1];
		for (int i = 2; i < size; ++i)
			dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
		return max(dp1[size - 1], dp2[size - 1]);
	}
	int rob22(vector<int>&nums)
	{
		/*
		�����ռ䣬������LeetCode�ϼ���ô�з�ӳ
		���ǿռ任ʱ��ĺá�
		*/
		int size = nums.size();
		if (size == 0) return 0;
		if (size <= 2) return *max_element(nums.begin(), nums.end());

		int dp10 = 0, dp11 = nums[0], dp12;
		for (int i = 2; i < size; ++i)
		{
			dp12 = max(dp10 + nums[i], dp11);
			dp10 = dp11;
			dp11 = dp12;
		}

		int dp20 = 0, dp21 = nums[1], dp22;
		for (int i = 2; i < size; ++i)
		{
			dp22 = max(dp20 + nums[i], dp21);
			dp20 = dp21;
			dp21 = dp22;
		}

		return max(dp12, dp22);
	}
	int rob22(vector<int>&nums)
	{
		int size = nums.size();
		if (size == 0) return 0;
		if (size <= 2) return *max_element(nums.begin(), nums.end());
		vector<vector<int>> dp(size, vector<int>(2, 0));
		//����һ�� dp�����¼��һ���Ƿ�͵ dp[i][0]�����һ��δ��͵ʱ����i����͵��������� dp[i][1]�����һ����͵ʱ����i����͵���������
		dp[0][0] = 0;       dp[0][1] = nums[0];
		dp[1][0] = nums[1]; dp[1][1] = nums[0];
		for (int i = 2; i < size - 1; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + nums[i]);
		}
		dp[size - 1][0] = max(dp[size - 2][0], dp[size - 3][0] + nums[size - 1]);
		dp[size - 1][1] = dp[size - 2][1];
		return max(dp[size -1 ][0], dp[size -1][1]);
	}
};
void ini()
{
	Solution1 s1;
	
}