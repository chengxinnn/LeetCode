#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class BigNum
{
private:
	string data;
	bool neg;
public:
	BigNum() { data = ""; neg = 0; }
	BigNum(int n) { data.resize(n, '0'); }
	BigNum(string&s, bool&n) :data(s), neg(n) {}
	
	string addBigNum(BigNum&a, BigNum&b);
	string subBigNum(BigNum& a, BigNum& b);
	string proBigNum(BigNum& a, BigNum& b);
	string divBigNum(BigNum& a, BigNum& b);

};


string BigNum::addBigNum(BigNum& a, BigNum &b)
{

	BigNum ans;
	int alen = a.data.size() - 1, blen = b.data.size() - 1;
	BigNum ans(max(alen, blen) + 1);
	int clen = ans.data.size() - 1;
	int flag = 0;
	while( alen >= 0 || blen >= 0)
	{
		int num = flag;
		if (alen >= 0) num += a.data[alen--] - '0';
		if (blen >= 0) num += b.data[blen--] - '0';
		flag = num / 10;
		ans.data[clen--] = num % 10;
	}
	int i = 0;
	while (i < ans.data.size() && ans.data[i] == '0') i++;
	return ans.data.substr(i);
}
string BigNum::subBigNum(BigNum& a, BigNum& b)
{

}
string BigNum::proBigNum(BigNum& a, BigNum& b)
{

}
string BigNum::divBigNum(BigNum& a, BigNum& b)
{

}