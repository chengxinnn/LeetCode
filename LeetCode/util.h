#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

template<class outtype, class intype>
outtype convert(const intype& in)
{
	outtype out;
	stringstream ss;
	ss << in;
	ss >> out;
	return out;
}


template<class datatype>
void  get2dVec(string s, vector<vector<datatype>> &ans)
{
	string ss = s.substr(1, s.size() - 2);
	vector<datatype> temp;
	size_t start, end;
	for (int i = 0; i < ss.size(); i++)
	{
		if (ss[i] != '[')  continue;
		if (ss[i] == '[')
		{
			start = i + 1;
			temp.clear();
			for (end = start + 1; ss[end] != ']'; end++)
			{
				if (ss[end] != ',') continue;


				datatype x = convert<datatype>(ss.substr(start, end - start));
				temp.emplace_back(x);
				start = end + 1;
			}
			datatype x = convert<datatype>(ss.substr(start, end - start));
			temp.emplace_back(x);
			ans.emplace_back(temp);
		}
		i = end;
	}

}

template<class datatype>
vector<vector<datatype>> get2dVec(string s)
{
	vector<vector<datatype>> ans;
	string ss = s.substr(1, s.size() - 2);
	vector<int> temp;
	datatype x;
	size_t start, end;
	for (int i = 0; i < ss.size(); i++)
	{
		if (ss[i] != '[')  continue;
		if (ss[i] == '[')
		{
			start = i + 1;
			temp.clear();
			for ( end = start + 1; ss[end] != ']'; end++)
			{
				if (ss[end] != ',') continue;


				x = convert<datatype>(ss.substr(start, end - start));
				temp.emplace_back(x);
				start = end + 1;
			}
			x = convert<datatype>(ss.substr(start, end - start));
			temp.emplace_back(x);
			ans.emplace_back(temp);
		}
		i = end;
	}
	return ans;

}

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};

ListNode*BuildList(vector<int>nums)
{
	ListNode*head = new ListNode() , *former = head, *temp = head;
	for (int num : nums)
	{
		temp = new ListNode(num);
		former->next = temp;
		former = temp;
	}
	return head->next;
}

void printList(ListNode* head)
{
	while (head)
	{
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << endl;
}

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode() : left(NULL), right(NULL) {};
};

TreeNode *ConstructBinaryTree(vector<int> arr, int i) {
	int len = arr.size();
	if (len < 1) return NULL;
	TreeNode *root = NULL;
	if (i < len && arr[i] != '#') {
		root = new TreeNode();
		if (root == NULL)return NULL;
		root->val = arr[i];
		root->left = ConstructBinaryTree(arr,  2 * i + 1);
		root->right = ConstructBinaryTree(arr,  2 * i + 2);
	}
	return root;
}

TreeNode *buildTree(vector<int>tree)
{
	return ConstructBinaryTree(tree, 0);
}

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
	if (node == nullptr) {
		cout << "Empty tree";
		return;
	}

	if (node->right) {
		prettyPrintTree(node->right, prefix + (isLeft ? "©¦   " : "    "), false);
	}

	cout << prefix + (isLeft ? "©¸©¤©¤ " : "©°©¤©¤ ") + to_string(node->val) + "\n";

	if (node->left) {
		prettyPrintTree(node->left, prefix + (isLeft ? "    " : "©¦   "), true);
	}
}
