#pragma once
#include <functional>
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class trie {
public:

	trie()
	{
		val = 0;
		child = new trie *[3]();
		for (int i = 0; i < 3; i++) child[i] = nullptr;

	}

	vector<int>maximizeXor(vector<int>&nums, vector<vector<int>>&queries)
	{
		int qsize = queries.size(), nsize = nums.size();
		for (int i = 0; i < qsize; i++) queries[i].push_back(i);
		sort(queries.begin(), queries.end(), [](auto & x, auto & y) {return x[1] < y[1]; });
		sort(nums.begin(), nums.end());

		vector<int>ret(qsize);
		int nid = 0;
		for (const auto & q : queries)
		{
			ans = -1;
			int end = q[1];
			while (nid < nsize &&  nums[nid] <= end)
			{
				insert(nums[nid++]);
			}
			ret[q[2]] = nid ? get(q[0]) : -1;

		}
		return ret;
	}

private:
	int val;
	int ans = 0;
	trie ** child;


	void insert(int x)
	{
		trie * root = this;
		for (int i = 30; i >= 0; i--)
		{
			bool r = (x >> i) & 1;
			if (root->child[r] == nullptr)
				root->child[r] = new trie();
			root = root->child[r];
		}
		root->val = x;
	}
	int get(int x)
	{
		trie * root = this;
		int max = 0;
		for (int i = 30; i >= 0; i--)
		{
			bool r = (x >> i) & 1;
			if (root->child[!r])
			{
				max |= (1 << i);
				root = root->child[!r];
			}
			else
			{
				root = root->child[r];
			}
		}
		return max;

	}
	
};


/*================ this is too slow in submit ==================*/
// class Trie
// {
// public:
// 	Trie() {
// 		minn = INT_MAX;
// 		child = unique_ptr<Trie*[]>( new Trie*[2]() );
// 		for (int i = 0; i < 2; i++) child[i] = nullptr;
// 	}
// 
// 	vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
// 	{
// 		int size = queries.size();
// 		int limit = (*max_element(queries.begin(), queries.end(), [](auto & x, auto & y) { return x[1] < y[1]; }))[1];
// 		for (const auto & num : nums)
// 			if(num <= limit)
// 			insert(num);
// 		vector<int>ans(size);
// 		for (int i = 0; i < size; i++)
// 			ans[i] = get(queries[i][0], queries[i][1]);
// 		return ans;
// 	}
// 
// private:
// 	void insert(int x)
// 	{
// 		Trie*root = this;
// 		if (x < root->minn) root->minn = x;
// 		for (int i = 30; i >= 0; i--)
// 		{
// 			bool r = (x >> i) & 1;
// 			if (root->child[r] == nullptr)
// 				root->child[r] = new Trie();
// 			root = root->child[r];
// 			if (x < root->minn) root->minn = x;
// 		}
// 	}
// 
// 	int get(int x, int limit)
// 	{
// 		Trie * root = this;
// 		if (root->minn > limit) return -1;
// 		int ans = 0;
// 		for (int i = 30; i >= 0; i--)
// 		{
// 			int r = (x >> i) & 1;
// 			if (root->child[!r] != nullptr && root->child[!r]->minn <= limit)
// 			{
// 				ans |= (1 << i);
// 				root = root->child[!r];
// 			}
// 			else
// 			{
// 				root = root->child[r];
// 			}
// 		}
// 		return ans;
// 	}
// 
// 	int minn;
// 	unique_ptr<Trie*[] >child;
// 	//unique_ptr<Trie*[]>child;
// 	//unique_ptr < unique_ptr<Trie[]> >child;
// };
// 

class Trie {
public:
	Trie() {
		minn = INT_MAX;
		//child = unique_ptr<Trie*[]>(new Trie*[2]() );
		child[0] = nullptr; child[1] = nullptr;
	}
	void insert(int x)
	{
		Trie * root = this;
		if (root->minn > x) root->minn = x;
		for (int i = 30; i >= 0; i--)
		{
			bool r = (x >> i) & 1;
			if (root->child[r] == nullptr)
				root->child[r] = new Trie();
			root = root->child[r];
			if (root->minn > x) root->minn = x;
		}
	}

	int getm(int val, int limit)
	{
		Trie * root = this;
		int ans = 0;
		if (root->minn > limit) return -1;
		for (int i = 30; i >= 0; i--)
		{
			bool r = (val >> i) & 1;
			if (root->child[!r] != nullptr && root->child[!r]->minn <= limit)
			{
				ans |= (1 << i);
				root = root->child[!r];
			}
			else
				root = root->child[r];
		}
		return ans;
	}
private:
	int minn;
	unique_ptr<Trie*[]>child{new Trie*[2]};
};

class Solution
{
public:
	vector<int>maximizeXor(vector<int>&nums, vector<vector<int>>&queries)
	{
		Trie * root = new Trie();
		int size = queries.size();
		vector<int>ans(size);
		int maxn = (*max_element(queries.begin(), queries.end(), [](auto & x, auto & y) {return x[1] < y[1]; }))[1];
		for (const int & num : nums)
			if (num <= maxn)
				root->insert(num);
		for (int i = 0; i < size; i++)
			ans[i] = root->getm(queries[i][0], queries[i][1]);
		return ans;
	}
};


void ini()
{
	Solution * root = new Solution();
	vector<int>n({ 0,2,3,1,4 });
	vector<vector<int>>q({ { 3, 1 },{ 1, 3 },{ 5, 6 } });

	vector<int>n1({ 5,2,4,6,6,3 });
	vector<vector<int>>q1({ { 12, 4 },{ 8, 1 },{ 6, 3 } });

	for (const auto & x : root->maximizeXor(n1, q1))
	{
		cout << x << "  ";
	}
	cout << endl;
}