#pragma once
#include <string>
using  namespace std;

class Solution {
public:
	int ssize, psize;
	bool isMatch(string s, string p) {
		ssize = s.size();
		psize = p.size();
		return isMatch(s, p, 0, 0);

	}

	bool isMatch(string&s, string&p, int i, int j)
	{

		if (j >= psize) return i >= ssize;
		if (i >= ssize)
		{
			while (j < psize)
			{
				if (p[j] != '*' && (j + 1) < psize && p[j + 1] == '*') { j+=2;  continue; }
				return false;
			}
			return true;

		}



		bool match = s[i] == p[j] || p[j] == '.';
		if (p[j + 1] == '*')
			return (match&&isMatch(s, p, i + 1, j)) || isMatch(s, p, i, j + 2);
		else
			return match&&isMatch(s, p, i + 1, j + 1);

	}
};