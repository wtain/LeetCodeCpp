
#include <iostream>

using namespace std;

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* newHead = new ListNode();
		ListNode* newCurrent = newHead;
		ListNode* current = head;
		while (current) {
			ListNode* current1 = current->next;
			ListNode* prev1 = current;
			while (current1 && current1->val == current->val) {
				prev1 = current1;
				current1 = current1->next;
			}
			if (current == prev1) {
				newCurrent->next = current;
				newCurrent = newCurrent->next;
				newCurrent->next = nullptr;
			}
			current = current1;
		}
		return newHead->next;
	}
};

//ListNode* newHead = new ListNode();
//
//
//ListNode* prev = newHead;
//ListNode* newCurrent = nullptr;
//
//ListNode* current = head;
//while (current) {
//	if (!newCurrent) {
//		newHead->next = current;
//		newCurrent = current;
//	}
//	else {
//		if (current->val == newCurrent->val) {
//			while (current && current->val == newCurrent->val)
//				current = current->next;
//			newCurrent = prev;
//		}
//		else {
//			prev = newCurrent;
//			prev->next = current;
//			newCurrent = current;
//		}
//	}
//	current = current->next;
//}
//
//return newHead->next;

void printList(ListNode* node) {
	while (node) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}

int main()
{
	{
		ListNode* node = new ListNode(1);
		node->next = new ListNode(2);
		node->next->next = new ListNode(3);
		node->next->next->next = new ListNode(3);
		node->next->next->next->next = new ListNode(4);
		node->next->next->next->next->next = new ListNode(4);
		node->next->next->next->next->next->next = new ListNode(5);
		printList(Solution().deleteDuplicates(node)); // 1->2->5
	}

	{
		ListNode* node = new ListNode(1);
		node->next = new ListNode(1);
		node->next->next = new ListNode(1);
		node->next->next->next = new ListNode(2);
		node->next->next->next->next = new ListNode(3);
		printList(Solution().deleteDuplicates(node)); // 2->3
	}

	{
		printList(Solution().deleteDuplicates(nullptr)); // 
	}

	{
		ListNode* node = new ListNode(1);
		node->next = new ListNode(1);
		node->next->next = new ListNode(1);
		printList(Solution().deleteDuplicates(node)); // 
	}

	{
		ListNode* node = new ListNode(1);
		node->next = new ListNode(2);
		node->next->next = new ListNode(2);
		printList(Solution().deleteDuplicates(node)); // 1
	}

    return 0;
}

