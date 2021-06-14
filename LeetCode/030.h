#pragma once
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (words.size() == 0) return{};
		int wsize = words.size(), ssize = s.size(), len = words[0].size();
		vector<int> ans;
		unordered_map<string, int>hash;
		unordered_map<string, int>ha;
		int count = 0;
		for (string&word : words)
			hash[word]++;
		for (int i = 0; i <= ssize - len * wsize; i++)
		{
			if (!hash.count(s.substr(i, len))) continue;
			ha.clear(); count = 0;
			for (int j = 0; j < wsize; j++)
				ha[s.substr(i + j*len, len)]++;
			for (auto it = hash.begin(); it != hash.end(); it++)
				if (ha[it->first] != it->second) break;
				else count++;
				if (count == hash.size()) ans.emplace_back(i);
		}
		return ans;
	}
};