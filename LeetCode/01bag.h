#pragma once
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
public:


	/************************************************************
	*��������     �� 01�������⣬n����Ʒ��ÿһ����Ʒ���Լ��ļ�ֵ����������������һ���ı�������װ�µ����ļ�ֵ
	*״̬ת�Ʒ��� �� dp[i][j] =max( dp[i-1][ j - k*w[i]] + k*val[i] ); 0 <= k <= j/w[i]
	*************************************************************/
	int traditionalBag(vector<int>& val, vector<int>& w, int W)
	{
		int size = val.size();

		vector<vector<int>> dp(size + 1, vector<int>(W + 1, 0));

		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				if (j - w[i - 1] >= 0)
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + val[i - 1]);
				else
					dp[i][j] = dp[i - 1][j];

			}
		}

		return dp[size][W];


	}

	int traditionalBag1d(vector<int>& val, vector<int>& w, int W)
	{
		int size = val.size();

		vector<int> dp(W + 1, 0);

		for (int i = 0; i < size; i++)
		{
			for (int j = W; j >= w[i - 1]; j--)
			{
				dp[j] = max(dp[j], dp[j - w[i]] + val[i]);

			}
		}
		return dp[W];

	}



	/************************************************************
	*��������     �� ��ȫ�������⣬ÿһ����Ʒ�����Լ���������ֵ��ÿһ����Ʒ���޿��ã����ڱ�������һ��ʱ��װ�µ�����ֵ
	*״̬ת�Ʒ��� �� dp[i][j] = max( dp[i-1][j - k*w[i]] + k*val[i] ); 0 <= k <= j/w[i]
	*************************************************************/
	int unlimitedBag(vector<int>& val, vector<int>& w, int W)
	{
		int size = val.size();
		int maxval = 0;
		int i, j, k = 0;

		vector<vector<int>> dp(size + 1, vector<int>(W + 1, 0));

		for ( i = 1; i <= size; i++)
		{
			for (j = 1; j <= W; j++)
			{			
				for ( k = 0; k <= j / w[i - 1]; k++)
				{
					maxval = max(dp[i - 1][j - k * w[i - 1]] + k * val[i - 1], maxval);
				}
				dp[i][j] = maxval;
			}
			maxval = 0;
		}

		return dp[size][W];
	}

	//�������㷨����ѭ�������������ʱ�����ģ��ڴ�ʹ�ü��ɱ�������ѭ��

	/************************************************************
	*��������     �� ��������ʹ������ѭ�������������ʱ�������
	*״̬ת�Ʒ��� �� dp[i][j] = max( dp[i-1][j - k*w[i]] + k*val[i] ); 0 <= k <= j/w[i]
	*************************************************************/
	int unlimitedBag_simp(vector<int>& val, vector<int>& w, int W)
	{
		int size = val.size();

		vector<vector<int>> dp(size + 1, vector<int>(W + 1, 0));

		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				if (j >= w[i - 1])
					dp[i][j] = max(dp[i][j - w[i - 1]] + val[i - 1], dp[i - 1][j]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		return dp[size][W];
	}



	int unlimitedBag_1d(vector<int>& val, vector<int>& w, int W)
	{
		int size = val.size();

		vector<int> dp(W + 1, 0);

		for (int i = 0; i < size; i++)
			for (int j = w[i]; j <= W; j++)
				dp[j] = max(dp[j - w[i]] + val[i], dp[j]);


		return dp[W];
	}

};