#pragma once
#include "util.h"

class Solution {
public:
	int maxDepth(TreeNode* root) {
		using pti = pair<TreeNode *, int>;
		stack<pti>f, fd;
		f.push(pti(root, 1));
		pti tmp;
		int ans = 0;
		while (!f.empty())
		{
			tmp = f.top(); f.pop(); // fd.push(tmp);
			if (tmp.second > ans) ans = tmp.second;
			cout << ans << " ";
			if (tmp.first->left != nullptr)
				f.push(pti(tmp.first->left, tmp.second + 1));
			if (tmp.first->right != nullptr) f.push(pti(tmp.first->right, tmp.second + 1));
		}
		return ans;
	}
};

void ini()
{
	Solution s;
	TreeNode * root = buildTree(vector<int>({ 3,9,20,'#','#',15,7 }));

	cout << s.maxDepth(root);
}