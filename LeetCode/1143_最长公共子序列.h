#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 *
 *���������ַ���?text1 ��?text2�������������ַ������ ���������� �ĳ��ȡ���������� ���������� ������ 0 ��

һ���ַ�����?������?��ָ����һ���µ��ַ�����������ԭ�ַ����ڲ��ı��ַ������˳��������ɾ��ĳЩ�ַ���Ҳ���Բ�ɾ���κ��ַ�������ɵ����ַ�����

���磬"ace" �� "abcde" �������У��� "aec" ���� "abcde" �������С�
�����ַ����� ���������� ���������ַ�������ͬӵ�е������С�
 **/

class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int s1 = text1.size(), s2 = text2.size();
		vector<vector<int>>dp(2, vector<int>(s2 + 1, 0));
		int now = 0, pre = 1;
		for (int i = 0; i < s1; i++)
		{
			for (int j = 0; j < s2; j++)
				dp[now][j + 1] = text1[i] == text2[j] ? dp[pre][j] + 1 : max(dp[now][j], dp[pre][j + 1]);
			swap(now, pre);
		}
		return dp[pre][s2];
	}
};

void ini(int j = 0)
{
	Solution s;
	cout << s.longestCommonSubsequence("3142", "124");

	
}

