#pragma once
#include<iostream>
#include <vector>
#include <string>

using namespace std;

//波兰表达式：没有括号，运算符总是在相关操作数之前，波兰表达式又被称为前缀表达式。
/*
一个中缀表达式转换为波兰表达式的过程为：
1、首先设定一个操作符栈，一个波兰表达式字符串，从右到左遍历中缀表达式
2、如果是操作数，则直接加入前缀表达式。
3、如果是右括号，直接压入操作符栈。如果是左括号，弹出右括号以上所有操作符，加入前缀表达式。
4、如果是操作符，如果当前操作符优先级低于操作符栈顶优先级，弹出栈顶操作符加入表达式，直至栈顶操作符的优先级低于当前操作符。压入当前操作符。
5、遍历完成，如果操作符栈不为空，弹出所有操作符加入表达式。
*/
template <class t>
class Sloutionpre
{
public:
	vector<string>cvtInorderToPreordder(vector<string>&inorder)
	{
		vector<string>ans;
		vector<string>ops;
		int n = inorder.size();
		string temp;
		for (int i = n - 1; i >= 0; i++)
		{
			temp = inorder[i];

		}
	}
	int eval(vetor<string>&tokens)
	{

	}
};


//逆波兰表达式：  没有括号，运算符总是放在相关的操作数之后。逆波兰表达式又被称为后缀表达式。

class Solution
{
public:
	int evalRPN(vector<string>&tokens)
	{
		vector<int>ans;
		int temp;
		string op;
		for (const auto & token : tokens) {
			if (token == "+") { temp = ans.back(); ans.pop_back(); temp = ans.back() + temp; ans.pop_back(); ans.push_back(temp); }
			else if (token == "-") { temp = ans.back(); ans.pop_back(); temp = ans.back() - temp; ans.pop_back(); ans.push_back(temp); }
			else if (token == "*") { temp = ans.back(); ans.pop_back(); temp = ans.back() * temp; ans.pop_back(); ans.push_back(temp); }
			else if (token == "/") { temp = ans.back(); ans.pop_back(); temp = ans.back() / temp; ans.pop_back(); ans.push_back(temp); }
			else ans.push_back(stoi(token));
		}
		return ans[0];
	}

	int evalRPN1(vector<string>&tokens)
	{
		vector<int>ans;
		int l, r;
		for (const string & token : tokens)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				l = ans.back(); ans.pop_back();
				r = ans.back(); ans.pop_back();
				if (token == "+") ans.push_back(l + r);
				else if (token == "-") ans.push_back(l - r);
				else if (token == "*") ans.push_back(l * r);
				else  ans.push_back(l / r);
			}
			else
				ans.push_back(stoi(token));
		}
		return ans[0];
	}
};