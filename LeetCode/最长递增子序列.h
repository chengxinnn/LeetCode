#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution
{
public:

	/*
	����һ���������� nums ���ҵ�������ϸ���������еĳ��ȡ�
���������������������������У�ɾ������ɾ���������е�Ԫ�ض����ı�����Ԫ�ص�˳��
���磬[3,6,2,7] ������ [0,3,1,6,2,2,7] �������С�
	*/
	int lengthOfLIS(vector<int>nums)
	{
		int size = nums.size();
		if (size == 0) return 0;
		vector<int>dp(size, 1);
		for (int i = 1; i < size; i++)
			for (int j = 0; j < i; j++)
				dp[i] = max(dp[i], dp[j] + 1);
		return *max_element(dp.begin(), dp.end());

	}

 	/*
	����˹�������⡣
	����һ����ά�������� envelopes ������ envelopes[i] = [wi, hi] ����ʾ�� i ���ŷ�Ŀ�Ⱥ͸߶ȡ�
����һ���ŷ�Ŀ�Ⱥ͸߶ȶ�������ŷ���ʱ������ŷ�Ϳ��ԷŽ���һ���ŷ����ͬ����˹����һ����
����� ������ж��ٸ� �ŷ������һ�顰����˹���ޡ��ŷ⣨�����԰�һ���ŷ�ŵ���һ���ŷ����棩��
ע�⣺��������ת�ŷ�
	*/
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		int size = envelopes.size();
		sort(envelopes.begin(), envelopes.end());
		vector<int>dp(size, 1);
		for (int i = 1; i < size; i++)
			for (int j = 0; j < i; j++)
				if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
					dp[i] = max(dp[i], dp[j] + 1);

		return *max_element(dp.begin(), dp.end());
	}

};