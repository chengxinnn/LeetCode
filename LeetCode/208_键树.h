#pragma once
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class Trie {
private:
	vector<unique_ptr<Trie> > child; //未找到child的函数定义
	bool isword;
public:

	Trie() {
		
		isword = false;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie*t = this;

	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Trie*t = this;

		return t->isword;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie*t = this;

		return true;
	}
};

void ini()
{
	Trie*root;
	root->insert("apple");
	root->insert("apples");
	root->insert("anapple");
	root->insert("buleapple");
	root->insert("zta");
	root->insert("plz");
	cout << root->search("apple") << endl;
	cout << root->startsWith("blu");
}