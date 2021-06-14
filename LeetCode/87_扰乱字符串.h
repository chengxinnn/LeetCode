#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
	bool isScramble(string& s1, string & s2) {
		if (s1.size() != s2.size()) return false;
		return trans(s1, s2);
	}

	bool trans(string&s1, string &s2)
	{
		string key = s1 + s2;
		if (mem.count(key)) return mem[s1 + s2];
		if (s1 == s2)
		{
			mem[key] = true;
			return true;
		}
		for (int i = 1, len = s1.size(); i <len; ++i)
		{
			string left1 = s1.substr(0, i), right1 = s1.substr(i);

			if (trans(left1, s2.substr(0, i)) && trans(right1, s2.substr(i)) ||
				trans(left1, s2.substr(len - i)) && trans(right1, s2.substr(0, len - i)))
			{
				mem[key] = true;
				return true;
			}
		}
		mem[key] = false;
		return false;
	}
private:
	map<string, bool>mem;
};


void ini()
{
	Solution s;
	cout << "string(abcde), string(caebd)     "  << s.isScramble(string("rgeat"), string("great")) << endl;
}