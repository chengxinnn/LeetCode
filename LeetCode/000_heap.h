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
/*******************�����󶥶�*******************
    Ҫ���д�С���������轨���󶥶ѡ�
	��Ϊ���һ�ε�����ʱ��������root��������β��
	ÿ��pop�Ӷ�β��ʼ��

	*/
Heap::Heap(vector<int> vec)
{
	heap = vec;
	heapSort();
	for_each(heap.begin(), heap.end(), [](const int & x) {cout << x << " "; });
}
/*********************����***********************
    �����һ����Ҷ�ӽڵ�n/2��ʼ,���µ�����
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
/********************ɸѡ����**********************
  ��һ�����ݵĹ���

  ��root��ʼ�������ӽڵ�Ƚϣ����ӽڵ����root��ֵ��
  �򽻻�root�������ӽڵ��ֵ���Ӷ��ӽڵ��λ�ü�������
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