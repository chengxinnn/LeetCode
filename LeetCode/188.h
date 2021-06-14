#pragma once
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int size = prices.size();
		if (size == 0 || k == 0) return 0;
		vector<int> pro;
		int profit = 0, i = 0;
		for (i = 1; i < size; i++)
		{
			if (prices[i] >= prices[i - 1])
	        {
				profit += prices[i] - prices[i - 1];
			}
			else
			{
				if (profit != 0) pro.emplace_back(profit);
				profit = 0;
			}
		}
		if(profit) pro.emplace_back(profit);
		profit = 0; i = 0;
		sort(pro.begin(), pro.end(), [](int x, int y) { return x > y; });
		while (k && pro.size()-i)
		{
			profit += pro[i];
			i++;
			k--;
		}
		return profit;

	}
};