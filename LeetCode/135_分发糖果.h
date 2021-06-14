#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
	/*
	老师想给孩子们分发糖果，有 N?个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
    你需要按照以下要求，帮助老师给这些孩子分发糖果：
	每个孩子至少分配到 1 个糖果。
	相邻的孩子中，评分高的孩子必须获得更多的糖果。
	那么这样下来，老师至少需要准备多少颗糖果呢？
	*/
	int candy(vector<int>&ratings) 
	{
		/*我的思路是找最小值赋1，再找次小峰。实际上可以由无数小峰，是我们解决不了的
	    查看题解发现大佬思路:
	    用temp数组存储多余的糖果数
		第一次遍历从左向右如果i>i-1 那么其值为temp【i-1】 +  1，这样我们的temp记录的是相较于峰谷爬坡的值
		第二次遍历从右向左如果i<i+1 那么则是一个反向爬坡的过程，其值为temp【i】和temp【i+1】+1中较大者，
		因为第一次便利时峰谷值必然为0，第一次爬坡时左峰可能更长其值更大，所以此时取最大者。
		*/
		int size = ratings.size();
		int *temp = new int[size]();
		for (int i = 1; i < size; i++)
			temp[i] = ratings[i] > ratings[i - 1] ? temp[i - 1] + 1 : temp[i];
		for (int i = size - 2; i >= 0; i--)
			temp[i] = ratings[i] > ratings[i + 1] ? max(temp[i + 1] + 1, temp[i]) : temp[i];
		return size + accumulate(temp, temp + size, int(0));
	}
	

};