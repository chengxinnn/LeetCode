#pragma once
#include <iostream>

using namespace std;

struct BST{
	int val;
	BST*left, *right;
	BST(int v) :val(v), left(nullptr), right(nullptr) {};
	BST() :val(0), left(nullptr), right(nullptr) {};

};

bool searchTree(BST*root, BST*p, const int & key)
{
	if (root == nullptr) return false;
	int val = root->val;
	if (val == key) {p = root; return true;	}
	else if (val < key)return searchTree(root->left, p, key);
	else return searchTree(root->right, p, key);
	return false;
}

bool searchNode(BST*root, BST**p, const int & key)
{
	if (root == nullptr) return false;
	int val = root->val;
	*p = root;
	if (val == key) return true;
	else if (val < key) return searchNode(root->right, p, key);
	else return searchNode(root->left, p, key);
}

bool insertNode(BST*root, const int & key)
{
	if (root == nullptr) return false;
	BST*temp = nullptr;
	if (!searchNode(root, &temp, key))
	{
		BST*son = new BST(key);
		if (temp == nullptr)  root = son;
		else if (key > temp->val) temp->right = son;
		else  temp->left = son;
		return true;
	}
}

bool deleteNode(BST*root, const int & key)
{
	if (root == nullptr) return false;
	BST*p = nullptr, *son = nullptr;
	if (!searchNode(root, &p, key)) return false;
	if(p->right == nullptr)
	{
		son = p->left;
		p->right = son->right;
		p->left = son->left;
		free(son);
	}
	else if (p->left == nullptr)
	{
		son = p->right;
		p->left = son->left;
		p->right = son->right;
		free(son);
	}
	else
	{
		son = p->left;
		BST*f = p;
		while (son->right != nullptr) { f = son;  son = son->right; }
		p->val = son->val;
		if(f != p) f->right = son->left;
		else f->left = son->left;

	}
	return true;
}

void preOrder(BST*root)
{
	if (root == nullptr)
		return;
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}