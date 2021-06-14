#pragma once
#include "util.h"


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {

		ListNode*p = new ListNode(), *former = p, *tail, *last;
		p->next = head;
		tail = head;
		int cur = 1;
		while (head)
		{
			tail = former;
			for (int i = 0; i < k; i++)
			{
				tail = tail->next;
				if (!tail) return p->next;
			}
			last = tail->next;
			ret(head, tail);
			former->next = tail;
			head->next = last;
			former = head;
			head = last;
		}
		return p->next;
	
	}

	//方法二：插入法，每次选择前面的指针，塞入tail的next
	void ret(ListNode*head, ListNode*tail)
	{
		ListNode*pre = head, *temp;
		while (pre != tail)
		{
			temp = pre;
			pre = pre->next;
			temp->next = tail->next;
			tail->next = temp;
		}

	}

	//方法一 ：栈存储k个节点，实际上空间消耗O（n)
	ListNode* ret(ListNode* head, int k)
	{
		ListNode*stack = new ListNode[k];
		ListNode*former = head, *tail;
		int cur = 0;
		while (head && k)
		{
			stack[cur++] = *head;
			head = head->next;

			k--;
		}
		//长度不够k，不变
		if (k != 0) return former;
		cur--;
		tail = stack[cur].next;
		former = &stack[cur];
		head = former;
		while (cur > 0)
		{
			head->next = &stack[cur - 1];
			head = head->next;
			cur--;
		}
		head->next = tail;
		return former;
	}
};


class Solution1
{
public:
	stack<ListNode*> sl;
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode*dummy = new ListNode(), *former = dummy, *last, *temp;
		dummy->next = head;

		while (true)
		{
			int cur = 0;
			temp = head;
			while (cur < k && temp)
			{
				
				sl.emplace(temp);
				temp = temp->next;
				cur++;
			}
			if (cur != k) return dummy->next;
			while (!sl.empty())
			{
				former->next = sl.top();
				sl.pop();
				former = former->next;
			}
			former->next = temp;
			head = temp;

		}
		return dummy->next;
	}

};