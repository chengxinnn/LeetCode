#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	// int rob(vector<int>& nums) {

	//     /*ִ����ʱ��0 ms, ������ C++ �ύ�л�����100.00%���û�
	//     �ڴ����ģ�8 MB, ������ C++ �ύ�л�����5.08%���û�*/
	//     int n = nums.size();
	//     vector<vector<int>> dp(n + 1, vector<int>(2, 0));

	//     for(int i = 1; i <= n; i++)
	//     {
	//         dp[i][0]=  max(dp[i-1][0], dp[i-1][1]);
	//         dp[i][1] = dp[i-1][0] + nums[i - 1];
	//     }

	//     return max(dp[n][0], dp[n][1]);

	// }

	int rob(vector<int>&nums) {
		int n = nums.size();
		int dp0;
		vector<int> dp(2, 0);

		for (int i = 1; i <= n; i++)
		{
			dp0 = dp[0];
			dp[0] = max(dp[0], dp[1]);
			dp[1] = dp0 + nums[i - 1];
		}
		return max(dp[0], dp[1]);
	}
};