#pragma once
#include <set>
#include <memory>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;


//================================ 

auto cmp = [](int  x, int  y) { return x >= y; };

class Solution
{
public:
	/*
	LeetCode 1099. 小于 K 的两数之和（二分查找）
	给你一个整数数组 A 和一个整数 K，请在该数组中找出两个元素，
	使它们的和小于 K 但尽可能地接近 K，返回这两个元素的和。
	如不存在这样的两个元素，请返回 -1。
	*/
	int towSum(vector<int>&vec, int K)
	{
		/*
		在LeetCode两数之和中，我们固定一个数，从左到右遍历，在map中寻找是否有该值，有即成功，否则将K-a[i]加入map
		对于这类小于的题，不再用map,而是set，通过c++ lowerbound或者upperbound找到边界值，保存到结果。
		*/
		int size = vec.size();
		set<int, greater<int> >pre;

		int maxnum = INT_MIN;
		for (int j = 0; j < size; j++)
		{
			auto it = pre.upper_bound(K -vec[j]);
			if (it != pre.end())
				maxnum = max(maxnum, vec[j] + *it);
			pre.insert(vec[j]);
		}
		return maxnum;
	}

	int twoSum1(vector<int>&vec, int K)
	{
		int size = vec.size();
		sort(vec.begin(), vec.end());
		int mx = INT_MIN, l, r, mid;
		for (int i = 0; i < size; i++)
		{
			l = i + 1; r = size - 1;
			while (l <= r)
			{
				mid = l + ((r - l) >> 1);
				if (vec[mid] >= K - vec[i])
					r = mid - 1;
				else 
				{
					if (mid == size - 1 || (vec[mid + 1] >= K - vec[i]))
					{
						mx = max(mx, vec[i] + vec[mid]);
						break;
					}
					else
						l = mid + 1;
				}
			}
		}
		return mx;
	}




	/*
	在全是正整数的一维数组中，求解和不超过 K 的最大连续子数组之和
	*/
	int maxSumArray(vector<int>& arr, int k)
	{
		int size = arr.size();
		vector<int>sum(size , 0);
		sum[0] = arr[0];
		for (int i = 1; i < size; i++)
			sum[i] += sum[i - 1] + arr[i];
		
		int ans = INT_MIN;
		for (int j = size - 1; j > 0; j--)
		{
			auto it = lower_bound(sum.begin(), sum.end(), sum[j] - k);
			if (it != sum.end())
				ans = max(ans, sum[j] - *it);
		}
		return ans;
	}

	
	/*
	在一维数组中，求解和不超过 K 的最大连续子数组之和
	*/
	int maxSumArray1(vector<int>& arr, int k)
	{
		int size = arr.size();
		vector<int>sum(size, 0);
		sum[0] = arr[0];
		for (int i = 1; i < size; i++)
			sum[i] += sum[i - 1] + arr[i];
		set<int>pre;
		pre.insert(0);
		int ans = INT_MIN;
		for (int i = 0; i < size; i++)
		{
			auto it = pre.lower_bound(sum[i] - k );
			if (it != pre.end())
			{
				ans = max(ans, sum[i] - *it);
			}
			pre.insert(sum[i]);
		}
		return ans;
	}
	/*
	209. 长度最小的子数组
	给定一个含有?n?个正整数的数组和一个正整数 target 。
	找出该数组中满足其和 ≥ target 的长度最小的 连续子数组?[numsl, numsl+1, ..., numsr-1, numsr] ，
	并返回其长度。如果不存在符合条件的子数组，返回 0 。
	*/
	int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
		int start = 0, end = 0, sum = 0;
		if (n == 0) {
			return 0;
		}
		int ans = n + 1;
		while (end<n) {
			sum += nums[end];
			while (sum >= target) {
				ans = min(ans, end - start + 1);
				sum -= nums[start];
				start++;
			}
			end++;
		}
		return ans>n ? 0 : ans;
	}

	int minSubArrayLen1(int target, vector<int>& nums)
	{
		int n = nums.size(),ans = n + 1;
		unique_ptr<int[]>sums(new int[n + 1]());
		for (int i = 0; i < n; i++)
			sums[i + 1] = nums[i] + sums[i];
		for (int i = 0; i <= n; i++)
		{
			int t = target + sums[i];
			auto it = lower_bound(sums.get(), sums.get() + n + 1, t);
			if (it != sums.get() + n + 1)
				ans = min(ans, static_cast<int>(it - sums.get()) - i);

		}
		return ans == n + 1 ? 0 : ans;
	}

	int minSubArrayLen2(int target, vector<int>& nums)
	{
		int l = 0, r = 0, sum = 0, size = nums.size();
		int minlen = size + 1;

		while (r < size)
		{
			sum += nums[r++];
			while (sum >= target)
			{
				minlen = min(minlen, r - l );
				sum -= nums[l++];
			}
		}
		return minlen == size + 1 ? 0 : minlen;
	}






	//862. 和至少为 K 的最短子数组
	/*
	返回 A 的最短的非空连续子数组的长度，该子数组的和至少为 K 。
    如果没有和至少为 K 的非空子数组，返回 -1 。
	*/
	int shortestSubarray(vector<int>& A, int K) {
		vector<int>a(A.size() + 1, 0);
		for (int i = 1; i <= A.size(); i++) a[i] = A[i - 1];
		int sum = 0, st = 1, res = INT_MAX;
		for (int i = 1, n = a.size(); i < n; i++)
		{
			if (a[i] >= K)return 1;
			sum += a[i];
			if (sum <= 0) {
				sum = 0;
				st = i + 1;
				continue;
			}
			for (int j = i - 1; a[j + 1]<0; j--) {
				a[j] += a[j + 1];
				a[j + 1] = 0;
			}//！！！！！！！！
			if (sum >= K) {
				while (sum - a[st] >= K || a[st] <= 0)sum -= a[st++];
				res = min(res, i - st + 1);
			}
		}
		return res == INT_MAX ? -1 : res;
	}


	int shortestSubarray1(vector<int>& nums, int K) {
		int size = nums.size();
		vector<int>sums(size + 1, 0);
		for (int i = 1; i <= size; i++) sums[i] += nums[i - 1] + sums[i - 1];
		deque<int>ss;
		int ans = size + 1;
		for (int j = 0; j <= size; j++)
		{
			while (!ss.empty() && sums[j] <= sums[ss.back()])
				ss.pop_back();
			while (!ss.empty() && sums[j] - sums[ss.front()] >= K)
			{
				int i = ss.front();
				ss.pop_front();
				ans = min(ans, j - i);
			}
			ss.push_back(j);
		}
		return ans == size + 1 ? -1 : ans;
	}



	/*
	给定一个长度为 n 的数组 A ，?500≤Ai≤500，要求出 。长度不大于 M 的连续子数组的最大和。
	*/
	int maxSumSubArray(vector<int>&nums, int M)
	{
		int size = nums.size();
		vector<int>sums(size + 1, 0);
		for (int i = 1; i <= size; i++) sums[i] += sums[i - 1] + nums[i - 1];
		deque<int>ss;
		int maxnum = INT_MIN;
		for (int j = 0; j <= size; j++)
		{
			while (!ss.empty() && sums[j] < sums[ss.back()])
				ss.pop_back();
			ss.push_back(j);
			while (!ss.empty() && j - ss.front() > M)
				ss.pop_front();
			maxnum = max(maxnum, sums[j] - sums[ss.front()]);
		}
		return maxnum == INT_MAX ? -1 : maxnum;
	}





	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>>asum(m + 1, vector<int>( n + 1, 0));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				asum[i][j] = matrix[i - 1][j - 1] + asum[i - 1][j] + asum[i][j - 1] - asum[i - 1][j - 1];
		int ans = INT_MIN;
	    //区域和所有元素可以看做一个数列，是否存在两数差最近接k
		for (int trow = 1; trow <= m; trow++)
		{
			for (int brow = trow; brow <= m; brow++)
			{
				set<int>vec;
				vec.insert(0);
				for (int rcol = 1; rcol <= n; rcol++)
				{
					int right = asum[brow][rcol] - asum[trow - 1][rcol];
					auto left = vec.lower_bound(right - k);
					if (left != vec.end())
						ans = max(ans, right - *left);
					vec.insert(right);
				}
			}
		}
		return ans;
	}
};

void ini()
{
	Solution s;
	vector<vector<int>>vec({ {1,0,1 }, { 0,-2,3 } });

	cout << "LeetCode 1099. 小于 K 的两数之和（二分查找）       ";
	cout << s.towSum(vector<int>({ 2,19,5,28,3,2 }), 8) << endl;

	cout << s.twoSum1(vector<int>({ 2,19,5,28,3,2 }), 8) << endl;


	cout << "209. 长度最小的子数组              ";
	cout << s.minSubArrayLen2(7, vector<int>({ 2,3,1,2,4,3 })) << endl;

	cout << "862. 和至少为 K 的最短子数组       ";
	cout << s.shortestSubarray1(vector<int>({ 1,2,3,-4,4,2,6,-3,7 }), 15) << endl;

	cout << "长度不超过M的连续子数组的最大和    ";
	cout << s.maxSumSubArray(vector<int>({ 1,2, -3, 4,3, 1, -2, 5, 3, -2,6, 2 }), 3) << endl;

	cout << s.maxSumSubmatrix(vec, 2) << endl;;

	cout << s.maxSumArray(vector<int>({ 1,3,4,6,1,8,2,3 }), 13) << endl;

	cout << s.maxSumArray1(vector<int>({ 1,1,-4,6,8,-2,3 }), 7) << endl;
}