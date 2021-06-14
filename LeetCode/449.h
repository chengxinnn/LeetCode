#pragma once
#include <iostream>
#include <string >
using namespace std;
class Solution {
public:
	char findTheDifference(string s, string t) {
		char exor = 0;
 		for (char c : s + t) {
			cout << c << " ";
			exor ^= c;
		}
		return exor;
	}

	char findTheDifference(string& s, string& t) {
		int sum1 = 0, sum2 = 0;
		for (char&ch : s)
			sum1 += ch;
		for (char&ch : t)
			sum2 += ch;
		return (char)(sum2 - sum1);

	}
};