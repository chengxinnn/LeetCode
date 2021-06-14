#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		int N = price.size();
		int res = inner_product(price.begin(), price.end(), needs.begin(), 0);
		if (memo.count(needs)) {
			return memo[needs];
		}

		for (const auto& offer : special) {
			auto rem = helper(offer, needs);
			if (rem.empty()) {
				continue;
			}
			res = min(res, offer.back() + shoppingOffers(price, special, rem));
		}

		memo[needs] = res;
		return memo[needs];
	}

	vector<int> helper(const vector<int>& offer, const vector<int>& needs) {
		vector<int> remainder(needs.size(), 0);
		for (int i = 0; i < needs.size(); i++) {
			if (offer[i] > needs[i]) {
				return{};
			}
			remainder[i] = needs[i] - offer[i];
		}

		return remainder;
	}

private:
	map<vector<int>, int> memo;
};
