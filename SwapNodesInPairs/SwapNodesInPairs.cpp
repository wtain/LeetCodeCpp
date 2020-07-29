
#include <iostream>

using namespace std;

/*
https://leetcode.com/problems/swap-nodes-in-pairs/
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.



Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
//Memory Usage : 7.6 MB, less than 43.80% of C++ online submissions for Swap Nodes in Pairs.
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head)
			return NULL;
		if (!head->next)
			return head;

		ListNode* newhead = head->next;
		ListNode* prev = NULL;
		ListNode* current = head;
		while (current && current->next)
		{
			ListNode* next = current->next;
			ListNode* tail = next->next;

			current->next = tail;
			next->next = current;

			if (prev)
				prev->next = next;

			prev = current;
			current = tail;
		}

		return newhead;
	}
};

void print(ListNode* head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(4);
	print(Solution().swapPairs(l1));

	l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(4);
	l1->next->next->next->next = new ListNode(5);
	print(Solution().swapPairs(l1));

    return 0;
}

