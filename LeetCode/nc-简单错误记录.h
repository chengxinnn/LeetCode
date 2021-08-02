#pragma once
#include <string>
#include <iostream>
#include <map>
#include <set>

using namespace std; 

struct cmp
{
	bool operator()()
};


void ini()
{
	using psi = pair<string, pair<int, int>>;
	map<string, pair<int, int> >mp;
	string temp; int num;
	while (cin >> temp >> num)
	{
		if(temp == "") break;
		size_t p = temp.rfind('\\');
		string s = p == string::npos ? temp : temp.substr(p + 1);
		if (mp.count(s))
			mp[s].first = num, mp[s].second += 1;

	}
}