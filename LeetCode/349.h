#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>&nums1, vector<int>&nums2)
	{
		unordered_map<int, int>map;
		for (int i : nums1)
			map[i] = 1;
		vector<int>res;
		for (int i : nums2)
			if (map[i])
			{
				map[i] = 0;
				res.push_back(i);	
			}
				







		return res;
	}

	vector<int> intersection1(vector<int>&nums1, vector<int>&nums2)
	{
		unordered_set<int> mset;
		for (int i : nums1)
			mset.insert(i);
		vector<int>res;
		for (int i : nums2)
			if (mset.count(i))
			{
				mset.erase(i);
				res.push_back(i);
			}
		return res;
	}
};