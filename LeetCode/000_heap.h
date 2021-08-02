#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heap
{
public:

	Heap(vector<int>vec);
	
private:
	vector<int>heap;
	void heapAdjust(const int& root, const int& len);
	void heapSort();
};
/*******************建立大顶堆*******************
    要序列从小到大排序需建立大顶堆。
	因为最后一次调整的时候会把最大的root调整到队尾。
	每次pop从队尾开始。

	*/
Heap::Heap(vector<int> vec)
{
	heap = vec;
	heapSort();
	for_each(heap.begin(), heap.end(), [](const int & x) {cout << x << " "; });
}
/*********************建堆***********************
    从最后一个非叶子节点n/2开始,向下调整。
*/
void Heap::heapSort()
{
	int len = heap.size();
	for (int i = len / 2 - 1; i >= 0; i--)
		heapAdjust(i, len);
	for (int j = len - 1; j > 0; j--)
	{
		swap(heap[0], heap[j]);
		heapAdjust(0, j);
	}

}
/********************筛选调整**********************
  是一次下溯的过程

  从root开始，与其子节点比较，若子节点大于root的值，
  则交换root与最大儿子节点的值，从儿子节点的位置继续向下
*/
void Heap::heapAdjust(const int& root, const int& len)
{
	int l = root * 2 + 1;
	
	if (l < len)
	{
		int maxson = l;
		int r = l + 1;
		if (r < len && heap[r] > heap[l])
			maxson = r;
		if (heap[maxson] > heap[root])
		{
			swap(heap[root], heap[maxson]);
			heapAdjust(maxson, len);
		}
	}
	

}