#pragma once
#include <sstream>
using namespace std;

class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		int res = N;
		int n;
		int times = 1;
		while (times <= res / 10)  //十以下的数字直接输出
		{
			n = res / times % 100;
			times *= 10;
			if (n / 10 > n % 10)
				res = res / times *times - 1;
		}
		return res;
	}

	int monotoneIncreasingDigits1(int N) {
		if (N < 10) return N;
		string s = to_string(N);
		int size = s.size();
		for (int i = size - 2; i >= 0; i--)
		{
			if (s[i] > s[i + 1])
			{
				s[i]--;
				for (int j = i + 1; j < size; j++)
					s[j] = '9';

			}
		}
		return stoi(s);
	}

	
};