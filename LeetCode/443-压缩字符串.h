#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;
/*
����һ���ַ���ʹ��ԭ���㷨����ѹ����
ѹ����ĳ��ȱ���ʼ��С�ڻ����ԭ���鳤�ȡ�
�����ÿ��Ԫ��Ӧ���ǳ���Ϊ1?���ַ������� int �������ͣ���
�����ԭ���޸���������󣬷���������³��ȡ�
*/

class Solution {
public:
	int compress(vector<char>& chars) {
		int id = 0, size = chars.size(), len;
		for (int i = 0, j = 0; i < size; ++i)
		{
			len = 1;
			for (j = i + 1; j < size ; ++j, ++len)
				if (chars[j] != chars[i]) 
					break;

			chars[id++] = chars[i];
			if (len == 1) continue;
			for (char ch : to_string(len))
				chars[id++] = ch;
			i = j - 1;
		}
		return id;
	}
};

void ini()
{
	Solution s;
	cout << s.compress(vector<char>({ 'a','a','b','b','c','c','c' }));
}