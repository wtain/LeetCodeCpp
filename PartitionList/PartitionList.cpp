
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/partition-list/

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//class Solution {
//public:
//	ListNode* partition(ListNode* head, int x) {
//		ListNode* i = nullptr;
//		ListNode* j = head;
//		while (j) {
//			if (j->val < x) {
//				if (!i)
//					i = head;
//				else
//					i = i->next;
//				swap(i->val, j->val);
//			}
//			j = j->next;
//		}
//		return head;
//	}
//};

//Runtime: 12 ms, faster than 14.69% of C++ online submissions for Partition List.
//Memory Usage : 9.9 MB, less than 83.64% of C++ online submissions for Partition List.
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* i = nullptr, *i0 = nullptr;
		ListNode* j = nullptr, *j0 = nullptr;
		while (head) {
			auto next = head->next;
			if (head->val < x) {
				if (!i0)
					i0 = head;
				if (i)
					i->next = head;
				i = head;
			}
			else {
				if (!j0)
					j0 = head;
				if (j)
					j->next = head;
				j = head;
			}
			head = next;
		}
		if (j)
			j->next = nullptr;
		if (i)
			i->next = j0;
		return i0 ? i0 : j0;
	}
};

void printList(ListNode* head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(2);
	l1->next->next->next->next = new ListNode(5);
	l1->next->next->next->next->next = new ListNode(2);

	printList(Solution().partition(l1, 3)); // 1->2->2->4->3->5

    return 0;
}

