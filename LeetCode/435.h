#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//初始想到的方法，思路总是寻找第一个边界相邻的作为下一个边界条件
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int size = intervals.size();
		if (size <= 1) return 0;
		int ans, right, j, i = 0, minans = size;
		stable_sort(intervals.begin(), intervals.end(), [](vector<int>x, vector<int>y) {return x[1] < y[1]; });
		while (i < minans)
		{
			ans = i;
			right = intervals[i][1];
			for (j = i + 1; j < size; j++)
			{
				if (right <= intervals[j][0]) {
					right = intervals[j][1];
					continue;
				}
				ans++;
			}
			minans = ans < minans ? ans : minans;
			i++;
		}
		return minans;
	}

	int eraseOverlapIntervals1(vector<vector<int>>& intervals) {
		if (intervals.empty()) return 0;
		int size = intervals.size();
		sort(intervals.begin(), intervals.end(), [](vector<int>&x, vector<int>&y) {return x[1] < y[1]; });
		int num = 1, i = 0;
		for (int j = 1; j < intervals.size(); ++j) {
			if (intervals[j][0] >= intervals[i][1]) {
				i = j;
				++num;
			}
		}
		return size - num;
	}

};