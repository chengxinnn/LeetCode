#pragma once
#include <vector>
#include <algorithm>
using namespace std;

/*
����һ���������� nums �����пɲ�������Ԫ�أ����㷵�ظ��������п��ܵ��Ӽ����ݼ�����
�⼯ ���� �����ظ����Ӽ������صĽ⼯�У��Ӽ����԰� ����˳�� ���С�
*/
class Solution {
public:
	vector<vector<int>>ans = { {} };
	vector<int>temp;

	vector<vector<int>> subsets(vector<int>& nums) {
		back(nums, 0);
		return ans;
	}
	void back(vector<int>&nums, int start)
	{
		if (start == nums.size())return;
		for (int i = start; i < nums.size(); i++)
		{
			temp.push_back(nums[i]);
			ans.push_back(temp);
			back(nums, i + 1);
			temp.pop_back();
		}
	}


	vector<vector<int>> subsets1(vector<int>& nums) {
		vector<vector<int>>ans = { {} };
		vector<int>temp;
		int len;
		for (int i = 0; i < nums.size(); i++)
		{
			len = ans.size();
			for (int j = 0; j < len; j++)
			{
				temp = ans[j];
				temp.push_back(nums[i]);
				ans.push_back(temp);
			}
		}
		return ans;
	}
};


/*
����һ���������� nums �����п��ܰ����ظ�Ԫ�أ����㷵�ظ��������п��ܵ��Ӽ����ݼ�����
�⼯ ���� �����ظ����Ӽ������صĽ⼯�У��Ӽ����԰� ����˳�� ���С�
*/
class Solution {
private:
	vector<vector<int>> res;
	vector<int> temp;
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		back(nums, 0);
		return res;
	}
	void back(vector<int>& nums, int start) {
		res.push_back(temp);
		for (int i = start; i<nums.size(); i++) {
			if (i != start&&nums[i] == nums[i - 1])//ȥ��
				continue;
			temp.push_back(nums[i]);
			back(nums, i + 1);
			temp.pop_back();//����
		}
		return;
	}
};