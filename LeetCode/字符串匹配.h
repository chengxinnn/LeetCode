#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
//================KMP===================//
int KMPSearch(string pattern, string match)
{
	int m = pattern.size(), n = match.size();
	if (n == 0) return 0;
	vector<int>next(n, 0);
	for (int i = 1, j = 0; i < n; i++)
	{
		while (j > 0 && match[j] != match[i])
			j = next[j - 1];
		if (match[i] == match[j])
			j++;
		next[i] = j;
	}

	for (int i = 0, j = 0; i < m; i++)
	{
		while (j > 0 && match[j] != pattern[i])
			j = next[j - 1];
		if (pattern[i] == match[j])
			j++;
		if (j == n)
			return i - n + 1;
	}
	return -1;
}

//================KMP===================//
vector<int> getNext(string s)
{

	int size = s.size();
	vector<int>next(size, 0);
	next[0] = -1;
	int i = 0, j = -1;
	while (i < size - 1)
	{
		if (j == -1 || s[i] == s[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}

	return next;
}

int KMPSearch1(string s, string p)
{
	vector<int>next = getNext(p);
	int m = s.size(), n = p.size();
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (j < 0 || s[i] == p[j])
		{
			i++; j++;
		}
		else
			j = next[j];

	}
	return  j == n ? i - j : -1;
}

//================Sunday===================//

int SundaySearch(string pattern, string match) {
	int psize = pattern.size();
	int msize = match.size();
	if (psize <= 0 || msize <= 0)
		return -1;
	int j = 0, k;
	int m = msize;
	for (int i = 0; i<psize;) {
		if (pattern[i] != match[j]) {
			for (k = msize - 1; k >= 0; k--) {
				if (match[k] == pattern[m])
					break;
			}
			i = m - k;
			j = 0;
			m = i + msize;
		}
		else {
			if (j == msize - 1)
				return i - j;
			i++;
			j++;
		}
	}
}

//================Sunday===================//
int SundaySearch1(string pattern, string match)
{
	int psize = pattern.size(), msize = match.size();
	if (msize == 0) return 0;
	unordered_map<char, int>offset;
	for (int i = 0; i < msize; i++)
		offset[match[i]] = msize - i;
	int i = 0, k = 0;
	while (i <= psize - msize)
	{
		for (k = 0; k < msize && pattern[i + k] == match[k]; k++);
		if (k == msize) return i;
		if (offset.count(pattern[i + msize])) i += offset[pattern[i + msize]];
		else i += msize + 1;
	}
	return -1;
}

//================Sunday===================//

int Sunday(string s, string p)
{
	int ssize = s.size(), psize = p.size();
	if (ssize == 0 || psize == 0 || psize > ssize) return -1;
	for (int i = 0, j = 0, slast = psize, pi = 0; i < ssize; )
	{
		if (s[i] == p[j])
		{
			if (j == psize - 1)
				return i - j;
			i++;
			j++;
		}
		else
		{
			for (pi = psize - 1; pi >= 0; pi--)
				if (s[slast] == p[pi])
					break;
			i = slast - pi;
			j = 0;
			slast = i + psize;
		}
	}
	return -1;
}







void ini()
{
	cout << KMPSearch("AAACAAAB", "AAAB") << endl;
	cout << SundaySearch("abc", "abc") << endl;
	cout << SundaySearch1("mississippi","issi") << endl;
}