#pragma once
#include<iostream>
#include <vector>
#include <string>

using namespace std;

//�������ʽ��û�����ţ��������������ز�����֮ǰ���������ʽ�ֱ���Ϊǰ׺���ʽ��
/*
һ����׺���ʽת��Ϊ�������ʽ�Ĺ���Ϊ��
1�������趨һ��������ջ��һ���������ʽ�ַ��������ҵ��������׺���ʽ
2������ǲ���������ֱ�Ӽ���ǰ׺���ʽ��
3������������ţ�ֱ��ѹ�������ջ������������ţ������������������в�����������ǰ׺���ʽ��
4������ǲ������������ǰ���������ȼ����ڲ�����ջ�����ȼ�������ջ��������������ʽ��ֱ��ջ�������������ȼ����ڵ�ǰ��������ѹ�뵱ǰ��������
5��������ɣ����������ջ��Ϊ�գ��������в�����������ʽ��
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


//�沨�����ʽ��  û�����ţ���������Ƿ�����صĲ�����֮���沨�����ʽ�ֱ���Ϊ��׺���ʽ��

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