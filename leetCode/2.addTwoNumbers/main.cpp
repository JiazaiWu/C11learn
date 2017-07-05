/*************************************************************************
    > File Name: main.cpp
    > Author: jiazai_wu
    > Mail: wujiazaiwh@163.com 
    > Created Time: Wed 05 Jul 2017 10:32:53 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		struct ListNode head(0);
		struct ListNode *node = &head;
		int sum = 0;
		while (l1 || l2 || sum) {
			if (l1) {
				sum += l1->val;
				l1 = l1->next;
			}

			if (l2) {
				sum += l2->val;
				l2 = l2->next;
			}

			node->next = new ListNode(sum % 10);
			node = node->next;
			sum /= 10;

		}

		return head.next;
    }
};
