#pragma once
#include <iostream>

#include <string>
using namespace std;

class Solution
{
public:
	bool isNumber(string  s) {
		bool num = 0;
		int i = 0, size = s.size();
		while (i < size && s[i] == ' ') i++;

		//��������
		if (i < size && (s[i] == '+' || s[i] == '-')) i++;
		while (i < size && isdigit(s[i])) { i++; num = 1;}
		//С������
		if (i < size && s[i] == '.')
		{
			//�ж�ǰ��������һ��Ҫ�����֡�
			if ((i > 0 && isdigit(s[i - 1])) || (i < size - 1 && isdigit(s[i + 1])))
			{
				i++;
				while (i < size && isdigit(s[i])) i++;
				num = 1;
			}
			else
				return false;
		}
		//e����
		if (i < size && (s[i] == 'e' || s[i] == 'E'))
		{
			//��������
			++i;
			if (i < size && (s[i] == '+' || s[i] == '-')) i++;
			if (i < size && isdigit(s[i])) {
				while (i < size && isdigit(s[i])) i++;
			}
			else
				return 0;
		}

		while (i < size && s[i] == ' ') i++;

		return i == size && num;

	}
};


void ini()
{
	Solution s;
	cout << s.isNumber("2e0") << endl;
}