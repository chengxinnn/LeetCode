#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory>
#include <numeric>
#include "util.h"

using namespace std;

#include "7-bridge.h"



int main()
{

	//我在笔记本那边小小改一下
	// OK  i have received it
	vector<vector<int>>dp(2);
	dp[0] = vector<int>(2, 0);
	dp[1] = vector<int>(5, 1);
	cout << sizeof(int) << "   " << &dp[0][0] << "  " << &dp[1][0] << "  " << &dp[1].back() << "  " << endl;



























	system("pause");
}
