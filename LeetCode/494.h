#pragma once
#include <vector>

using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int> & nums, int S) {
		int sum = 0;
		for (int num : nums) {
			sum += num;
		}
		// ��������Ϊ������sum + SΪ�����Ļ�������Ҫ��
		if (((sum + S) & 1) == 1) {
			return 0;
		}
		// Ŀ��Ͳ����ܴ����ܺ�
		if (S > sum) {
			return 0;
		}
		sum = (sum + S) >> 1;
		int len = nums.size();
		vector < vector<int>> dp(len + 1, vector<int>(sum + 1, 0));

		dp[0][0] = 1;

		// ����������� j �ĳ�ֵ�� 1 �Ļ�����Ҫ�ȳ�ʼ�� j = 0 �����
		/* int count = 1;
		for (int i = 1; i <= len; i++) {
		// ��0 ����
		if (nums[i - 1] == 0) {
		count *= 2;
		}
		dp[i][0] = count;
		} */

		// 01���� 
		// i(1 ~ len)��ʾ��������һ��ѡ���� i ��Ԫ�أ�j(0 ~ sum) ��ʾ���ǵĺ�
		for (int i = 1; i <= len; i++) {
			for (int j = 0; j <= sum; j++) {
				// װ���£���ѡ��ǰԪ�أ�
				if (j - nums[i - 1] < 0) {
					dp[i][j] = dp[i - 1][j];
					// ��װ�ɲ�װ����ǰԪ�ؿ�ѡ�ɲ�ѡ��
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
				}
			}
		}

		return dp[len][sum];
	}



	int findTargetSumWays1(vector<int> & nums, int S) {

		long long sum = 0;
		for (int num : nums)
			sum += num;

		if ((sum + S) % 2 == 1)
			return 0;

		if (S > sum)
			return 0;

		sum = (sum + S) / 2;
		vector<int> dp(sum + 1);
		dp[0] = 1;

		for (int num : nums)
			for (int i = sum; i >= num; --i)
				dp[i] += dp[i - num];//����ʣ��i�ķ���������װ��num�Ͳ�װ��num

		return dp[sum];
	}

};
