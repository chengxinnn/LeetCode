
#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int partition(vector<int>&vec, int l, int r)
	{
		if (l == r) return l;
		int mid = l + ((r - l) >> 1);

		if (vec[l] > vec[mid]) swap(vec[mid], vec[l]);
		if (vec[mid] > vec[r]) swap(vec[mid], vec[r]);
		if (vec[l] < vec[mid]) swap(vec[mid], vec[l]);

		int pivot = vec[l];

		while (l < r)
		{
			while (l < r && vec[r] > pivot) r--;
			vec[l] = vec[r];
			while (l < r && vec[l] <= pivot) l++;
			vec[r] = vec[l];
		}
		vec[l] = pivot;
		return l;
	}
	vector<int> GetLeastNumbers_Solution(vector<int> &vec, int k) {
		int size = vec.size();
		if (k > size || k < 1) return{};
		int l = 0, r = size - 1;
		while (l < r)
		{
			int p = partition(vec, l, r);
			if (p == k - 1) return vector<int>(vec.begin(), vec.begin() + k);
			if (p + 1 > k)
				r = p - 1;
			else
				l = p + 1;
		}
		return vector<int>(vec.begin(), vec.begin() + k);

	}
};

void ini()
{
	Solution s;
	vector<int>ans = { 1,1,2,3,4,65,7,78,8,3,2,1 };
    ans = s.GetLeastNumbers_Solution(ans, 4);
	for (int i = 0; i < 4; i++)
		cout << ans[i];

}