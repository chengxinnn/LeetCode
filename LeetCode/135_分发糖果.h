#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
	/*
	��ʦ��������Ƿַ��ǹ����� N?������վ����һ��ֱ�ߣ���ʦ�����ÿ�����ӵı��֣�Ԥ�ȸ��������֡�
    ����Ҫ��������Ҫ�󣬰�����ʦ����Щ���ӷַ��ǹ���
	ÿ���������ٷ��䵽 1 ���ǹ���
	���ڵĺ����У����ָߵĺ��ӱ����ø�����ǹ���
	��ô������������ʦ������Ҫ׼�����ٿ��ǹ��أ�
	*/
	int candy(vector<int>&ratings) 
	{
		/*�ҵ�˼·������Сֵ��1�����Ҵ�С�塣ʵ���Ͽ���������С�壬�����ǽ�����˵�
	    �鿴��ⷢ�ִ���˼·:
	    ��temp����洢������ǹ���
		��һ�α��������������i>i-1 ��ô��ֵΪtemp��i-1�� +  1���������ǵ�temp��¼��������ڷ�����µ�ֵ
		�ڶ��α��������������i<i+1 ��ô����һ���������µĹ��̣���ֵΪtemp��i����temp��i+1��+1�нϴ��ߣ�
		��Ϊ��һ�α���ʱ���ֵ��ȻΪ0����һ������ʱ�����ܸ�����ֵ�������Դ�ʱȡ����ߡ�
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