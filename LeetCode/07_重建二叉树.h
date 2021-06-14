#pragma once
#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

class Solution
{
private :
	vector<int>prelist, inlist;
public:
	TreeNode * rebuild(vector<int> &a, vector<int>&b)
	{
		int alen = a.size(), blen = b.size();
		if (alen == 0 || blen == 0 || alen != blen) return nullptr;
		prelist = a; inlist = b;
		return constructCore(0, alen - 1, 0, blen - 1);
	}
	TreeNode * constructCore( int astart, int aend, int bstart, int bend);

};
TreeNode * Solution::constructCore(int prestart, int preend, int instart, int inend)
{
	int rootval = prelist[prestart];
	TreeNode*root = new TreeNode(rootval);
	root->left = nullptr; root->right = nullptr;
	if (prestart == preend)
	{
		if (instart == inend && prelist[prestart] == inlist[instart])
			return root;
		else
			cerr << "Invalid List";
	}
	//ÖÐÐòËÑË÷×ó×ÓÊ÷£»
	int i = instart;
	while (i <= inend && inlist[i] != rootval) i++;
	if (i > inend) cerr << "Invalid List";
	int leftlen = i - instart;
	if (leftlen > 0)
		root->left = constructCore(prestart + 1, prestart + leftlen, instart, i - 1);
	if (leftlen < preend - prestart)
		root->right = constructCore(prestart + leftlen + 1, preend, i + 1, inend);
	return root;
}