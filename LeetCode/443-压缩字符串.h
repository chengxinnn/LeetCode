#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;
/*
给定一组字符，使用原地算法将其压缩。
压缩后的长度必须始终小于或等于原数组长度。
数组的每个元素应该是长度为1?的字符（不是 int 整数类型）。
在完成原地修改输入数组后，返回数组的新长度。
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