#pragma once
#include "util.h"
using namespace std;


class Solution {
public:
	vector<int> temp;
	vector<vector<int>> vec;
	vector<TreeNode*> childs;
	vector<TreeNode*> tempchild;

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root)childs.emplace_back(root);
		backtracking(true);
		return vec;
	}
	//»ØËÝ
	void backtracking(bool toright)
	{
		temp.clear();
		tempchild.clear();

		int size = childs.size();
		if (size == 0) return;
		int start = toright ? 0 : size - 1;
		int end = toright ? start + size : start - size;

		for (TreeNode*child : childs)
		{
			if (child->left) tempchild.emplace_back(child->left);
			if (child->right)tempchild.emplace_back(child->right);
		}
		while (start != end)
		{
			temp.emplace_back(childs[start]->val);
			start = toright ? start + 1 : start - 1;
		}
		vec.emplace_back(temp);
		childs = tempchild;
		backtracking(!toright);
	}
};