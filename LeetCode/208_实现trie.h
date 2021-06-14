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
211��Ӻ��������ʡ�
���һ�����ݽṹ��֧�� ����µ��� �� �����ַ����Ƿ����κ���ǰ��ӵ��ַ���ƥ�� ��

ʵ�ִʵ��� WordDictionary ��

WordDictionary() ��ʼ���ʵ����
void addWord(word) �� word ��ӵ����ݽṹ�У�֮����Զ�������ƥ��
bool search(word) ������ݽṹ�д����ַ�����?word ƥ�䣬�򷵻� true �����򣬷���? false ��word �п��ܰ���һЩ '.' ��ÿ��?. �����Ա�ʾ�κ�һ����ĸ��
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