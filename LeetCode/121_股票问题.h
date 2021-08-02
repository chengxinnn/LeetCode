#pragma once
#include <vector>
#include <iostream>

#include <algorithm>

using namespace std;


/*
121. ������Ʊ�����ʱ��
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
122. ������Ʊ�����ʱ�� II == ��ν���
*/

class Solution2 {
public:
	/*
	dp  ֻ��i��i-1֮���״̬ת����ֻ��Ҫ������������ʵ�� buy sell��buy��ʼ��ΪINTMIN����ʼʱû�����档
	sellΪ������Ʊ ������Ϊ�㡣 ��i�쿪ʼ��ʱ��,Ҫ���ݹɼ��ǵ��ж������뻹������������۸���ˣ����������������������롣
	����۸����ˣ�����������У���������������
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
123. ������Ʊ�����ʱ�� III  ����������� ���� ���ס�
*/

class Solution3 {
public:
	int maxProfit(vector<int>& prices) {
		/*
		DP  ˼·����һ��һ���� ����״̬ת�Ʒ��̣��ڵ�i�죬����ǵ�һ�������Ʊ�����ǿ���ѡ����Ҳ����ѡ����
		��buy1 = max�� buy1������ -prices[i]����buy1������һ��ġ�
		����Ƕ��ڵ�һ������Ʊ�������ԣ����ǿ��Բ�����Ҳ��������׬Ǯ����sell1 = max(sell1, buy1 + prices[i])��
		���ǵ�����������������Ϊ�㣬����ֱ��ʹ��buy1��buy2��sell2�ǵڶ��������Ĳ������͵�һ������һ����
		Ȼ���Ǳ߽������� ��ʼʱ��û�����룬�����г�����Ϊ�����������Ϊ0
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
188. ������Ʊ�����ʱ�� IV  ����������� k �ʽ��ס�
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
309. ���������Ʊʱ�� == �䶳��
����Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ��:
������Ʊ�����޷��ڵڶ��������Ʊ (���䶳��Ϊ 1 ��)��
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
714. ������Ʊ�����ʱ��  == ������
����Ծ����ܵ���ɸ���Ľ���
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