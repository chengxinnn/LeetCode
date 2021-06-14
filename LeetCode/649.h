#pragma once
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string predictPartyVictory(string senate) {
		int r = 0, d = 0, ans = 0, size = senate.size();

		for (int i = 0; i < size; i++)
		{
			printf("%c  ", senate[i]);
			if (senate[i] == 'R'&& r >= 0)
			{
				d--;
				ans++;
			}
			else if (senate[i] == 'R')
				r++;
			else if (senate[i] == 'D' && d >= 0)
			{
				r--;
				ans--;
			}
			else
				d++;

			printf("%d  %d  %d\n", r , d , ans);
		}
		if (ans > 0) return "Radiant";
		else if (ans < 0) return "Dire";
		else { return senate[size - 1] == 'R' ? "Dire" : "Radiant"; }

	}
};