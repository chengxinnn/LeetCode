#pragma once
#include <vector>
#include <string>

using namespace std;

vector<int> getNext(string s)
{
	
	int size = s.size();
	vector<int>next(size, 0);
	next[0] = -1;
	int i = 0,j = -1;
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

int match(string s, string p)
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