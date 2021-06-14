#pragma once
#include <vector>

class Solution {
public:
	bool lemonadeChange(std::vector<int>& bills) {
		int balance[3] = { 0 };
		for (int bill : bills)
		{
			printf("%d\n", bill);
			if (bill == 5)
				balance[0]++;
			else if (bill == 10)
			{
				if (balance[0] > 0)
				{
					balance[0]--;
					balance[1]++;
				}
				else
					return false;

			}
			else
			{
				if (balance[0] > 2)
				{
					balance[0] -= 3;
				}
				else if( balance[0 ] >0&& balance[1] > 0)
				{
					balance[0]--;
					balance[1]--;
					balance[2]++;
				}
				else
					return false;
			}
		}
		return true;


	}
};