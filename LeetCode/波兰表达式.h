#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

/*
常见的算数表达式是中缀表达式
例如：5 + ( 6 – 4 / 2 ) * 3
波兰表达式是前缀表达式。
上式其前缀形式为：+ 5 * - 6 / 4 2 3
中缀表达式转波兰表达式的过程为：
1、从右向左扫描整个整个中缀表达式
2、如果是操作树，直接加入表达式。
3、如果是右括号，压入操作符栈。如果是左括号，弹出操作符直至右括号。
4、如果是操作符：当前操作符优先级小于栈顶操作符优先级的时候，则弹出栈，并入表达式，直至栈顶优先级小于等于当前操作符优先级，压入栈。
5、最后表达式翻转，得到前缀表达式。
*/
inline int preority(const char & op);

string convertInToPre(string &inorder)
{
	stack<char>op;
	string ans;
	int size = inorder.size();
	int num = 0,time = 0;
	char temp;
	for (int i = size - 1; i >= 0; i--)
	{
		if (i == 9)
			int x = 1;
		temp = inorder[i];
		if (isdigit(temp))
		{
			num = 0; time = 1;
			while (i >= 0 && isdigit(inorder[i]))
			{
				num += time * (inorder[i] - '0');
				time *= 10;
				i--;
			}
			i++;
			ans += to_string(num);
		}
		else if (temp == ')')
			op.emplace(temp);
		else if (temp == '(')
		{
			while (!op.empty())
			{

				if (op.top() == ')')
				{
					op.pop();
					break;
				}
				ans.push_back(op.top());
				op.pop();
			}
		}
		else if (temp == ' ') continue;
		else
		{
			while (!op.empty() && preority(op.top()) > preority(temp))
			{
				ans.push_back(op.top());
				op.pop();
			}
			op.emplace(temp);
		}
	}

	while (!op.empty())
	{
		ans.push_back(op.top());
		op.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int calPre(const string & s)
{
	vector<int>ans;
	int pre, last;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (isdigit(s[i]))
			ans.emplace_back(s[i] - '0');
		else
		{
			pre = ans.back(); ans.pop_back();
			last = ans.back(); ans.pop_back();
			switch(s[i])
			{
			case '+': ans.push_back(pre + last); break;
			case '-': ans.push_back(pre - last); break;
			case '*': ans.push_back(pre * last); break;
			case '/': ans.push_back(pre / last); break;
			default:
				break;
			}
		}
	}
	return ans.back();
}

/*
逆波兰表达式就是后缀表达式。
中缀表达式转后缀表达式的过程为：
1、从左到右扫描整个表达式。
2、如果是操作数，直接加入表达式。
3、如果是左括号，压入操作站，如果是右括号，。。。
4、如果是操作符，若栈顶优先级高于当前优先级，则弹出栈顶元素直至小于等于当前操作符优先级，再将其压入栈。
5、
*/
string convertInToPo(const string & s)
{
	string ans;
	string op;
	int n = s.size();
	int num; 
	for (int i = 0; i < n ; i++)
	{
		if (isdigit(s[i]))
		{
			num = 0;
			while (i >= 0 && isdigit(s[i]))
				num = num * 10 + s[i++] - '0';
			i--;
			ans += to_string(num);
		}
		else if (s[i] == ' ') continue;
		else if (s[i] == '(')
			op.push_back('(');
		else if (s[i] == ')')
		{
			while (!op.empty() && op.back() != '(')
			{
				ans.push_back(op.back());
				op.pop_back();
			}
			if (!op.empty()) op.pop_back();
		}
		else
		{
			while (!op.empty() && preority(op.back()) > preority(s[i]))
			{
				ans.push_back(op.back());
				op.pop_back();
			}
			op.push_back(s[i]);
		}
	}
	while (!op.empty())
	{
		ans.push_back(op.back());
		op.pop_back();
	}
	return ans;
}

int calPost(const  string & s)
{
	vector<int>ans;
	int pre, last;
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]))
			ans.emplace_back(s[i] - '0');
		else
		{
			last = ans.back(); ans.pop_back();
			pre = ans.back(); ans.pop_back();
			switch (s[i])
			{
			case '+': ans.push_back(pre + last); break;
			case '-': ans.push_back(pre - last); break;
			case '*': ans.push_back(pre * last); break;
			case '/': ans.push_back(pre / last); break;
			default:
				break;
			}
		}
	}
	return ans.back();

}




inline int preority(const char & op)
{
	if (op == '+' || op == '-') return 1;
	else if (op == '*' || op == '/') return 2;
	else return 0;
}
