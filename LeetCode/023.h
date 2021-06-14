#pragma once
#include "util.h"
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	ListNode*mergeKLists(vector<ListNode*>& lists) {


	}

	//使用queue将所有的（list.size()个head)元素按val从小到大自动排序
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		auto dummy = new ListNode(), cur = dummy;
		auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val; };
		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
		for (auto list : lists) if (list) pq.push(list);
		while (pq.size()) {
			cur = cur->next = pq.top(); pq.pop();
			if (cur->next) pq.push(cur->next);
		}
		return dummy->next;
	}

	ListNode* mergeKTwoList(ListNode*l1, ListNode*l2)
	{
		if (!l1)return l2;
		if (!l2)return l1;
		if (l1->val <= l2->val) { l1->next = mergeKTwoList(l1->next, l2); return l1; }
		else { l2->next = mergeKTwoList(l1, l2->next); return l2; }
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode*l1;
		if (lists.size() == 0) return NULL;
		l1 = lists[0];
		for (int i = 1; i < lists.size(); i++)
			l1 = mergeKTwoList(l1, lists[i]);
		return l1;

	}
};