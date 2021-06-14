#pragma once

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int kConcatenationMaxSum(vector<int>& arr, int k) {
		int n = arr.size(), dp = 0, sum = 0, maxx = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			dp = (dp < 0) ? arr[i % n] : dp + arr[i % n];
			maxx = (dp > maxx) ? dp : maxx;
			if (i == n - 1 && k == 1) return maxx;
			if (i < n) sum += arr[i];
		}
		long long kk = k;
		return ((max(0, sum)*(kk - 2)) + maxx) % 1000000007;
	}

	int kConcatenationMaxSum1(vector<int>& arr, int k) {
		long long mod = 1e9 + 7;
		int N = arr.size(), minv = 0, maxv = 0, maxd = 0, sum = 0;
		for (int i = 0; i < N; ++i)
		{
			sum += arr[i];
			if (sum < minv) minv = sum;
			if (sum > maxv) maxv = sum;
			if (sum - minv > maxd) maxd = sum - minv;
		}
		long long k1 = maxd, k2 = maxv + sum - minv, kn = maxd + (k - 1)*((long long)sum);
		return (k == 1) ? k1 : (max(k1, max(k2, kn)) % mod);
	}
};