#pragma once
#include <vector>
#include <iostream>
using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder(){
		ans.clear();
		size = 0;
	}

	void addNum(int num) {
		ans.emplace_back(num);
		size++;
	}

	double findMedian() {
		heapsort();
		if (size & 1) return ans[size / 2];
		return double(ans[(size - 1) / 2] + ans[(size - 1) / 2 + 1]) / 2;
	}


private:

	//堆中加入新元素一次上溯 percolate up
	void up(int son)
	{
		int p = (son - 1) >> 1;
		while (p > son && ans[p] < ans[son])
		{
			swap(ans[p], ans[son]);
			son = p;
			p = (son - 1) >> 1;
		}
	}
	//删除堆顶需要下溯 percolate down。
	void down(int p, int len)
	{
		int son = (p << 1) + 1, r;
		while (son < len)
		{
			r = son + 1 < len ? son + 1 : son;
			son = ans[son] > ans[r] ? son : r;
			if (ans[son] > ans[p])
			{
				swap(ans[son], ans[p]);
				p = son;
				son = (p << 1) + 1;
			}
			else break;
		}
	}

	void heapsort()
	{
		for (int i = size / 2 - 1; i >= 0; i--)
			down(i, size);
		for (int i = size - 1; i > 0; i--)
		{
			swap(ans[0], ans[i]);
			down(0, i);
		}
	}

private:

	vector<int>ans;
	int size;

};

void ini()
{
	MedianFinder s;
	for (int i = 9; i > 5; i--)s.addNum(i);

	cout << s.findMedian();

	for (int i = 0; i < 6; i++)s.addNum(i);

	cout << s.findMedian();
}