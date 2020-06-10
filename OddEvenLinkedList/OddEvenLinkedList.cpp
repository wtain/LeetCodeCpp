
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/odd-even-linked-list/

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Runtime: 32 ms, faster than 6.18% of C++ online submissions for Odd Even Linked List.
//Memory Usage : 9.6 MB, less than 97.14% of C++ online submissions for Odd Even Linked List.
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode* oddHead = nullptr;
		ListNode* evenHead = nullptr;
		ListNode* oddCurr = nullptr;
		ListNode* evenCurr = nullptr;

		bool odd = true;

		while (head) {
			if (odd) {
				if (!oddHead)
					oddCurr = oddHead = head;
				else
					oddCurr->next = head;
				oddCurr = head;
			}
			else {
				if (!evenHead)
					evenCurr = evenHead = head;
				else
					evenCurr->next = head;
				evenCurr = head;
			}

			head = head->next;
			odd = !odd;
		}

		if (oddCurr)
			oddCurr->next = evenHead;

		if (evenCurr)
			evenCurr->next = nullptr;

		return oddHead;
	}
};

void printList(ListNode* pHead) {
	while (pHead) {
		cout << pHead->val;
		if (pHead->next)
			cout << ", ";
		pHead = pHead->next;
	}
}

ListNode* constructList(initializer_list<int> elems) {
	ListNode* pHead = nullptr, *pCurrent = nullptr;
	for (int e : elems) {
		ListNode* node = new ListNode(e);
		if (!pCurrent) {
			pCurrent = pHead = node;
		}
		else {
			pCurrent->next = node;
			pCurrent = pCurrent->next;
		}
	}

	return pHead;
}

int main()
{
	printList(Solution().oddEvenList(constructList({ 1, 2, 3, 4, 5 }))); // 1->3->5->2->4->NULL
	cout << endl;

	printList(Solution().oddEvenList(constructList({ 2,1,3,5,6,4,7 }))); // 2->3->6->7->1->5->4->NULL
	cout << endl;

    return 0;
}

