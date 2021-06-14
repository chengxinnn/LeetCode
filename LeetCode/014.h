#pragma once
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int ssize = strs.size(), len = 0, id = 0, minlen = INT_MAX;
		if (ssize == 0) return "";
		char temp;
		bool ok = true;
		for (string & str : strs)
			minlen = minlen >= str.size() ? str.size() : minlen;
		while (id < minlen)
		{
			temp = strs[0][id];
			for (string & str : strs)
				if (str[id] != temp) { ok = false; break; }
			if (ok) { len++; id++; }
			else break;
		}
		return len ? strs[0].substr(0, len) : "";
	}


	string longestCommonPrefix1(vector<string>& strs) {
		if (strs.size() == 0) return "";
		string ans = strs[0];
		for (int i = 0; i < strs.size(); i++)
		{
			if (strs[i].substr(0, ans.size()) != ans)
			{
				ans = ans.substr(0, ans.size() - 1);
				i--;
			}
		}
		return ans;
	}

		string longestCommonPrefix2(vector<string>& strs) {
			if (!strs.size()) {
				return "";
			}
			int minLength = min_element(strs.begin(), strs.end(), [](const string& s, const string& t) {return s.size() < t.size(); })->size();
			int low = 0, high = minLength;
			while (low < high) {
				int mid = (high - low + 1) / 2 + low;
				if (isCommonPrefix(strs, mid)) {
					low = mid;
				}
				else {
					high = mid - 1;
				}
			}
			return strs[0].substr(0, low);
		}

		bool isCommonPrefix(const vector<string>& strs, int length) {
			string str0 = strs[0].substr(0, length);
			int count = strs.size();
			for (int i = 1; i < count; ++i) {
				string str = strs[i];
				for (int j = 0; j < length; ++j) {
					if (str0[j] != str[j]) {
						return false;
					}
				}
			}
			return true;
		}
};