#pragma once
#include <iostream>

using namespace std;

class trie
{
public:
	trie()
	{
		isWord = false;
		child = new trie*[26]();
		for (int i = 0; i < 26; i++)
			child[i] = nullptr;
	}

	void insert(const string& word)
	{
		trie* root = this;
		for (const auto & ch : word)
		{
			if (root->child[ch - 'a'] == nullptr)
				root->child[ch - 'a'] = new trie();
			root = root->child[ch - 'a'];
		}
		root->isWord = 1;
	}

	bool search(const string & word)
	{
		trie * root = this;
		for (const char & ch : word)
		{
			if (root->child[ch - 'a'] != nullptr)
				root = root->child[ch - 'a'];
			else
				return false;
		}
		return root->isWord;
	}

	bool startwith(const string & word)
	{
		trie * root = this;
		for (const char & ch : word)
		{
			if (root->child[ch - 'a'] != nullptr)
				root = root->child[ch - 'a'];
			else
				return false;
		}
		return true;
	}

private:
	trie**child;
	bool isWord;
};


/*
211添加和搜索单词。
设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

实现词典类 WordDictionary ：

WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与?word 匹配，则返回 true ；否则，返回? false 。word 中可能包含一些 '.' ，每个?. 都可以表示任何一个字母。
*/
class trie1
{
public:
	trie1()
	{
		isWord = false;
		child = new trie1*[26]();
		for (int i = 0; i < 26; i++)
			child[i] = nullptr;
	}

	void insert(const string& word)
	{
		trie1* root = this;
		for (const auto & ch : word)
		{
			if (root->child[ch - 'a'] == nullptr)
				root->child[ch - 'a'] = new trie1();
			root = root->child[ch - 'a'];
		}
		root->isWord = 1;
	}

	bool search(trie1*root,  string & word, int id)
	{
		if (id == word.size() && root->isWord) return true;
		if(word[id]!= '.')
		{
			if (root->child[word[id] - 'a'] != nullptr)
				if (search(root->child[word[id] - 'a'], word, id + 1))
					return true;
		}
		else
		{
			for (int i = 0; i < 26; i++)
			{
				if (root->child[i] != nullptr)
					if (search(root->child[i], word, id + 1))
						return true;
			}
		}
		return false;
	}

private:
	trie1**child;
	bool isWord;

};


void ini()
{
	//trie*root = new trie();
	//root->insert("apple");
	//root->insert("string ");
	//root->insert("google");

	//cout << root->search("google") << endl;
	//cout << root->startwith("str") << endl;
	//cout << root->startwith("appr") << endl;

	trie1*root = new trie1();
	root->insert("apple");
	root->insert("google");
	
	cout << root->search(root, string("goo..."), 0) << endl;




}