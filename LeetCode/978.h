#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxTurbulenceSize(std::vector<int>& A) {

		int n = A.size();
		int ans = 1;;

		vector<vector<int>> dp(n, vector<int>(2));
		dp[0][0] = 1;
		dp[0][1] = 1;

		for (int i = 1; i < n; i++)
		{
			dp[i][0] = 1;
			dp[i][1] = 1;
			if (A[i] < A[i - 1])
				dp[i][0] = dp[i - 1][1] + 1;
			if (A[i] > A[i - 1])
				dp[i][1] = dp[i - 1][0] + 1;
		}

		for (int i = 0; i < n; ++i) ans = std::max(ans, std::max(dp[i][0], dp[i][1]));

		return ans;


	}

};




class Solution1 {
public:
	int maxTurbulenceSize(std::vector<int>& A) {
		int n = A.size(), ans = 1;
		int dp0 = 1, dp1 = 1;

		for (int i = 1; i < n; i++)
		{
			if (A[i] < A[i - 1])
			{
				dp0 = dp1 + 1;
				dp1 = 1;
			}
			else if (A[i] > A[i - 1])
			{
				dp1 = dp0 + 1;
				dp0 = 1;
			}
			else {
				dp0 = dp1 = 1;
			}
			cout << dp0 << "             " << dp1 << endl;
			ans = max(ans, max(dp0, dp1));
		}

		return ans;
	}
};