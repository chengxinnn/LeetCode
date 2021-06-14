#pragma once
#include <iostream>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		int size1 = num1.size();
		int size2 = num2.size();

		int*mul = new int[size1 + size2]();

		for (int i = size1 - 1; i >= 0; i--)
		{
			for (int j = size2 - 1; j >= 0; j--)
			{
				int bitmul = int(num1[i] - '0') * int(num2[j] -'0');
				bitmul += mul[i + j + 1];
				mul[i + j + 1] = bitmul % 10;
				mul[i + j] += bitmul / 10;
			}
		}

		//for (int i = 0; i < size1 + size2; i++)
		//	cout << mul[i];
		int cnt = 0;
		while (cnt < size1 + size2 && mul[cnt] == 0)
			cnt++;

		string ans;
		ans.resize(size1 + size2 - cnt);
		for (int i = 0; i < ans.size(); i++)
			ans[i] = mul[i + cnt] +'0';
		return ans;

	}
};