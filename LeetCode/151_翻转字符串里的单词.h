#pragma once
#include <iostream>
#include <string>

using namespace std;


/*ֱ����Դ�ַ����ϴ���
���ȷ�ת�ַ�����
Ȼ������ַ�����ת�õ����ַ���Ϊ���ʡ�

*/
class Solution {
public:
	string reverseWords(string s) {
		reverse(s.begin(), s.end());
		int size = s.size();
		int id = 0, end = 0;
		for (int start = 0; start < size; start++)
		{
			if (s[start] != ' ')
			{
				if (id != 0) s[id++] = ' ';
				end = start;
				while (end < size && s[end] != ' ') s[id++] = s[end++];
				reverse(s.begin() + start, s.begin() + end);
				start = end;
			}
		}
		s.erase(id, s.size() - id);
		return s;

	}
};