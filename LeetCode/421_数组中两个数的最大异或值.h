#pragma once
#include <vector>
#include <iostream>

using namespace std;


/*
给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。
*/
class Solution
{
public:
	int findMaximumXOR(vector<int>& nums) {
		ans = 0;
		trie * root = new trie();
		for (int i = 1; i < nums.size(); i++)
			if (add(root, nums[i - 1]))
				maxnow(root, nums[i]);
		freetrie(root);
		return ans;
	}
private:


	struct trie
	{
		trie *left = nullptr;
		trie *right = nullptr;
		trie() {}
	};

	int add(trie*root, int  x)
	{
		if (x < 0) return -1;
		for (int i = 30; i >= 0; i--)
		{
			bool r = (x >> i) & 1;
			if (r) {
				if (root->right == nullptr)
					root->right = new trie();
				root = root->right;
			}
			else {
				if (root->left == nullptr)
					root->left = new trie();
				root = root->left;
			}
		}
		return 1;
	}

	void maxnow(trie*root, int x)
	{
		if (x < 0)return;
		int maxn = 0;
		for (int i = 30; i >= 0; i--)
		{
			bool r = (x >> i) & 1;
			//如果当前有最佳值
			if (!r)
			{
				if (root->right != nullptr) { maxn |= (1 << i); root = root->right; }
				else root = root->left;
			}
			else
			{
				if (root->left != nullptr) { maxn |= (1 << i); root = root->left; }
				else root = root->right;
			}
		}
		if (maxn > ans) ans = maxn;
	}

	void freetrie(trie*root)
	{
		if (!root) return;
		if (root->left) freetrie(root->left);
		if (root->right) freetrie(root->right);
		delete root;
	}


	int ans = 0;
	
};

void ini()
{
	Solution s;
	cout << s.findMaximumXOR(vector<int>({ 3,10,5,25,2,8 })) << endl;
}