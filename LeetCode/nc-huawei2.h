#pragma once
#include<iostream>
#include <vector>
using namespace std;

int partition(vector<int>&vec, int l, int r)
{
	if (l < r)
	{
		swap(vec[l + ((r - l) >> 1)], vec[l]);
		int p = vec[l];
		while (l < r)
		{
			while (l < r && vec[r] > p)--r;
			vec[l] = vec[r];
			while (l < r && vec[l] <= p) ++l;
			vec[r] = vec[l];
		}
		vec[l] = p;
		return l;
	}
}

void sort(vector<int> & vec, int l, int r)
{
	if (l < r)
	{
		int p = partition(vec, l, r);
		sort(vec, l, p - 1);
		sort(vec, p + 1, r);
	}

}

void count(vector<int>&x, int &id)
{
	id = 1;
	int size = x.size();
	sort(x, 0, size - 1);
	for (int i = 1; i < size; ++i)
	{
		if (x[i] == x[i - 1])
			continue;
		x[id++] = x[i];
	}
}

void ini()
{
	int len;
	int nums[2001];
	while (cin >> len)
	{
		for (int i = 0; i < len; ++i) cin >> nums[i];
		set<int>s(nums, nums + len);
		for (const auto & x : s)
			cout << x << endl;
	}

	

}