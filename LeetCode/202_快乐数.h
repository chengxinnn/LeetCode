#pragma once
#include <iostream>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		int fast = n;
		int slow = n;
		do {
			slow = squarenum(slow);
			fast = squarenum(fast);
			fast = squarenum(fast);
		} while (fast != slow);
		return fast == 1 ? true : false;
	}

	int squarenum(int n)
	{
		int ans = 0;
		while (n)
		{
			ans += (n % 10) * (n % 10);
			n /= 10;
		}
		return ans;
	}

};

class Solution1 {
public:
	bool isPowerOfTwo(int n) {
		if (n < 1) return false;
		int i = 0;
		while (i < 31)
		{
			int x = 1 << i;
			if (x == n)
				return true;
			i++;
		}
		return false;


	}
};


#include <numeric>
class Solution2 {
public:
	bool isPowerOfTwo(int n) {
		if (n < 1) return false;
		cout << (n & (n - 1));
		if (   (n & (n - 1)) == 0) return true;
		return false;
	}
};