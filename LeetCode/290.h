#pragma once
#include <string>
#include <unordered_map>
using  namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string s) {
		int psize = pattern.size(), ssize = s.size();
		if (psize == 0 || ssize == 0)  return false;
		string str;
		unordered_map<string, char> map1;
		unordered_map<char, string> map2;

		int first = 0, end = 0, pid = 0;
		while (end < ssize)
		{
			if (s[end] == ' ' || end + 1 == ssize)
			{
				if(s[end] == ' ')     str = s.substr(first, end - first);
				if(end + 1 == ssize)  str = s.substr(first, end - first+1);

				if ((map1.count(str) != 0 && map1[str] != pattern[pid]) ||
					(map2.count(pattern[pid]) != 0 && map2[pattern[pid]] !=str))
					return false;
				map1[str] = pattern[pid]; map2[pattern[pid]] = str;
				first = end = end + 1; pid++;
				continue;
			}
			end++;
		}
		return true;

	}
};