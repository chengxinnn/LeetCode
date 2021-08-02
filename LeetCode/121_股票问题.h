#pragma once
#include <vector>
#include <iostream>

#include <algorithm>

using namespace std;


/*
121. 买卖股票的最佳时机
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int buy = INT_MIN, sell = 0;
		for (const int & x : prices)
		{
			buy = max(buy, -x);
			sell = max(sell, buy + x);
		}
		return sell;
	}

};

/*
122. 买卖股票的最佳时机 II == 多次交易
*/

class Solution2 {
public:
	/*
	dp  只有i与i-1之间的状态转换，只需要两个变量就能实现 buy sell。buy初始化为INTMIN，初始时没有收益。
	sell为卖出股票 ，收益为零。 第i天开始的时候,要根据股价涨跌判断是买入还是卖出，如果价格跌了，考虑昨天卖出，今天买入。
	如果价格涨了，考虑昨天持有，今天卖出的利润
	*/
	int maxProfit(vector<int>& prices) {
		int buy = INT_MIN, sell = 0;
		for (const int & x : prices)
		{
			sell = max(sell, buy + x);
			buy = max(buy, sell - x);
		}
		return sell;
	}
};
/*
123. 买卖股票的最佳时机 III  你最多可以完成 两笔 交易。
*/

class Solution3 {
public:
	int maxProfit(vector<int>& prices) {
		/*
		DP  思路和上一题一样， 考虑状态转移方程，在第i天，如果是第一次买入股票，我们可以选择买也可以选择不买，
		有buy1 = max（ buy1‘’， -prices[i]），buy1’是上一天的。
		如果是对于第一次卖股票操作而言，我们可以不卖，也可以卖了赚钱，有sell1 = max(sell1, buy1 + prices[i])。
		考虑到当天买入卖出收益为零，可以直接使用buy1。buy2和sell2是第二次买卖的操作，和第一次意义一样。
		然后考虑边界条件。 初始时，没有收入，将所有持有设为负无穷。不持有为0
		*/
		int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
		for (const int & x : prices)
		{
			buy1  = max(buy1, -x);
			sell1 = max(sell1, buy1 + x);
			buy2  = max(buy2, sell1 - x);
			sell2 = max(sell2, buy2 + x);
		}
		return sell2;
	}
};


/*
188. 买卖股票的最佳时机 IV  你最多可以完成 k 笔交易。
*/

class Solution4 {
public:
	int maxProfit(int k, vector<int>& prices) {
		int size = prices.size(); if (size < 2) return 0;
		vector<vector<int>> dp(2, vector<int>(k, 0));
		for (int i = 0; i < k; i++) dp[1][i] = -prices[0];
		for (int i = 1; i < size; i++)
		{
			dp[1][0] = max(dp[1][0], -prices[i]);
			dp[0][0] = max(dp[0][0], dp[1][0] + prices[i]);
			for (int j = 1; j < k; j++)
			{
				dp[1][j] = max(dp[0][j-1] - prices[i], dp[1][j]);
				dp[0][j] = max(dp[1][j] + prices[i], dp[0][j]);
			}
		}
		return dp[0][k - 1];
	}
};


/*
309. 最佳买卖股票时机 == 冷冻期
你可以尽可能地完成更多的交易（多次买卖一支股票）:
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
*/
class Solution5
{
	int maxProfit(vector<int>& prices) {
		int buy = INT_MIN, sell0 = 0, sell1 = 0;
		int nbuy, nsell0, nsell1;
		for (const auto & x : prices)
		{
			nbuy = max(buy, sell1 - x);
			nsell0 = buy + x;
			nsell1 = max(sell0, sell1);
			buy = nbuy;
			sell0 = nsell0;
			sell1 = nsell1;
		}
		return max(sell0, sell1);
	}
};

/*
714. 买卖股票的最佳时机  == 手续费
你可以尽可能地完成更多的交易
*/
class Solution6 {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int buy = INT_MIN + fee, sell = 0;
		for (const auto & x : prices)
		{
			buy = max(buy, sell - x);
			sell = max(sell, buy + x - fee);
		}
		return sell;
	}

};

void ini()
{
	Solution s;
	cout << s.maxProfit( vector<int>({ 3,2,6,5,0,3 }));
}