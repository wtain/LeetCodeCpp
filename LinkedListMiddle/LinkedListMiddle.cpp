
#include <iostream>

/*
https://leetcode.com/problems/middle-of-the-linked-list/

Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.



Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.


Note:

The number of nodes in the given list will be between 1 and 100.

*/

struct Node
{
	int data;
	Node* pNext;

	explicit Node(int v) : data(v), pNext(nullptr) {}
};

Node* CreateList(int n)
{
	Node* rv = nullptr;
	Node* current = nullptr;
	for (int i = 0; i < n; ++i)
	{
		Node* newNode = new Node(i);
		if (current)
		{
			current->pNext = newNode;
			current = newNode;
		}
		else
			rv = current = newNode;
	}

	return rv;
}

void PrintList(Node* pHead)
{
	while (pHead)
	{
		std::cout << pHead->data << " ";
		pHead = pHead->pNext;
	}
	std::cout << std::endl;
}

Node* Middle(Node* pHead)
{
	Node* pFirst = pHead;
	Node* pSecond = pHead;

	while (pSecond)
	{
		pSecond = pSecond->pNext;
		if (!pSecond)
			break;
		pSecond = pSecond->pNext;
		pFirst = pFirst->pNext;
	}
	return pFirst;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* pFirst = head;
		ListNode* pSecond = head;

		while (pSecond)
		{
			pSecond = pSecond->next;
			if (!pSecond)
				break;
			pSecond = pSecond->next;
			pFirst = pFirst->next;
		}
		return pFirst;
	}
};

int main()
{
	Node* pHead = CreateList(10);
	PrintList(pHead);
	std::cout << Middle(pHead)->data << std::endl;
	pHead = CreateList(9);
	PrintList(pHead);
	std::cout << Middle(pHead)->data << std::endl;

    return 0;
}

