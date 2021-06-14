#pragma once
#include<iostream>

using namespace std;
class MapSum {
public:
	/** Initialize your data structure here. */
	MapSum() {
		isKey = false;
		val = 0;
		child = new MapSum*[26]();
		for (int i = 0; i < 26; i++) child[i] = nullptr;
	}

	void insert(string key, int val) {
		MapSum * root = this;
		for (const auto & ch : key)
		{
			if (root->child[ch - 'a'] == nullptr)
				root->child[ch - 'a'] = new MapSum();
			root = root->child[ch - 'a'];
		}
		root->isKey = 1;
		root->val = val;
	}

	int sum(string prefix) {
		MapSum*root = this;
		int ans = 0;
		for (const auto &ch : prefix)
		{
			if (root->child[ch - 'a'] == nullptr)
				return 0;
			root = root->child[ch - 'a'];
		}
		back(root, ans);
		return ans;
	}
	void back(MapSum * root, int & ans)
	{

		if (root->isKey) {
			ans += root->val;
		}
		for (int i = 0; i < 26; i++)
			if (root->child[i] != nullptr)
				back(root->child[i], ans);
	}

private:
	int isKey;
	int val;
	MapSum ** child;
};

void ini()
{
	MapSum * root = new MapSum();
	root->insert("apple", 3);
	cout << root->sum("ap") << endl;
	root->insert("app", 2);
	cout << root->sum("ap") << endl;
}