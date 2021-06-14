#pragma once
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int Afirstbethan(int * a , int l, int r, int target)
{
	int mid = -1, originL = l, originR = r;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (a[mid] < target) l = mid + 1;
		else r = mid;
	}
	return (a[l] >= target) ? l : -1;
}
int Afirstbigthan(int * a, int l, int r, int target)
{
	int mid = -1, originL = l, originR = r;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (a[mid] <= target) l = mid + 1;
		else r = mid;
	}
	return (a[l] > target) ? l : -1;

}
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

template <class ForwardIterator, class T>
ForwardIterator upper_boundd(ForwardIterator first, ForwardIterator last, const T& val)
{
	ForwardIterator it;
	iterator_traits<ForwardIterator>::difference_type count, step;
	count = distance(first, last);
	step = count / 2;
	while (step>0)
	{
		it = first; step = count / 2; advance(it, step);
		if (*it >= val)
			count = step;
		else
		{
			first = it;
			count -= step;
		}

	}
	if (it == first && *it >= val) return last;
	return first;
}
