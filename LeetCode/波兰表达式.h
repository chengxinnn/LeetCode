#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

/*
�������������ʽ����׺���ʽ
���磺5 + ( 6 �C 4 / 2 ) * 3
�������ʽ��ǰ׺���ʽ��
��ʽ��ǰ׺��ʽΪ��+ 5 * - 6 / 4 2 3
��׺���ʽת�������ʽ�Ĺ���Ϊ��
1����������ɨ������������׺���ʽ
2������ǲ�������ֱ�Ӽ�����ʽ��
3������������ţ�ѹ�������ջ������������ţ�����������ֱ�������š�
4������ǲ���������ǰ���������ȼ�С��ջ�����������ȼ���ʱ���򵯳�ջ��������ʽ��ֱ��ջ�����ȼ�С�ڵ��ڵ�ǰ���������ȼ���ѹ��ջ��
5�������ʽ��ת���õ�ǰ׺���ʽ��
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
�沨�����ʽ���Ǻ�׺���ʽ��
��׺���ʽת��׺���ʽ�Ĺ���Ϊ��
1��������ɨ���������ʽ��
2������ǲ�������ֱ�Ӽ�����ʽ��
3������������ţ�ѹ�����վ������������ţ�������
4������ǲ���������ջ�����ȼ����ڵ�ǰ���ȼ����򵯳�ջ��Ԫ��ֱ��С�ڵ��ڵ�ǰ���������ȼ����ٽ���ѹ��ջ��
5��
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
