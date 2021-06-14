#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		int l = 0, r = arr.size() - 1, p = 0;
		while (l < r)
		{
			p = partition(arr, l, r);
			if (p + 1> k) r = p - 1;
			else if (p + 1 < k) l = p + 1;
			else break;
		}
		return vector<int>(arr.begin(), arr.begin() + k);



	}

	int partition(vector<int>&arr, int l, int r)
	{
		int ra = rand() % (r - l + 1);
		swap(arr[l], arr[l + ra]);
		int p = arr[l];
		while (l < r)
		{
			while (l < r && arr[r] > p) r--;
			arr[l] = arr[r];
			while (l < r && arr[l] <= p)l++;
			arr[r] = arr[l];
		}
		arr[l] = p;
		return l;
	}
};