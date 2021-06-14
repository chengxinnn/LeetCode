#pragma once
#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


template <class ForwardIterator, class T>
ForwardIterator lower_boundd(ForwardIterator first, ForwardIterator last, const T& val)
{
	ForwardIterator it;
	iterator_traits<ForwardIterator>::difference_type count, step;
	count = distance(first, last);
	step = count / 2;
	while (step>0)
	{
		it = first; step = count / 2; advance(it, step);
		if (*it > val)
			count = step;
		else if (*it < val)
		{
			first = it;
			count -= step;
		}
		else
			return it;
	}
	if (it == first && *it > val) return last;
	return first;
}


int* lower_boundd(int *first, int last, const int& val)
{
	int * it = first;
	int count = last,step = count / 2;

	step = count / 2;
	while (step>0)
	{
		it = first; step = count / 2; it += step;
		if (*it > val)
			count = step;
		else if (*it < val)
		{
			first = it;
			count -= step;
		}
		else
			return it;
	}
	if (it == first && *it > val) return it + last;
	return first;
}

class Solution {
public:
	int shipWithinDays(vector<int>& weights, int D) {
		int l = *max_element(weights.begin(), weights.end()), r = accumulate(weights.begin(), weights.end(), 0);
		while (l < r)
		{
			int mid = l + ((r - l) >> 1);
			int day = 1, sum = 0;
			for (const int & weight : weights)
			{
				sum += weight;
				if (sum > mid)
				{
					day++;
					sum = weight;
				}
			}
			if (day > D) l = mid + 1;
			else
				r = mid;
		}
		return l;
	}
};

void ini()
{
	Solution s;
	cout << s.shipWithinDays(vector<int>({ 1,2,3,4,5,6,7,8,9,10 }), 1);
}