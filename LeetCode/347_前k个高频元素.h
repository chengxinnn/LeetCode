#pragma once
#include <functional>
#include<iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> ans(k, 0);
		priority_queue< int, vector<int>, greater<int> > pq(nums.begin(), nums.end());
		int id = 0, top;
		ans[id] = pq.top();
		k--;
		pq.pop();
		do {
			top = pq.top();
			pq.pop();
			if (top != ans[id])
			{
				ans[++id] = top;
				k--;
			}
		} while (k);
		return ans;
	}
};