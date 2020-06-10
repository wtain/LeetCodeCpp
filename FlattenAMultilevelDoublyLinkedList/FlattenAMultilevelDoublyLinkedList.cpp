
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.



Example 1:

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation:

The multilevel linked list in the input is as follows:



After flattening the multilevel linked list it becomes:


Example 2:

Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:

The input multilevel linked list is as follows:

1---2---NULL
|
3---NULL
Example 3:

Input: head = []
Output: []


How multilevel linked list is represented in test case:

We use the multilevel linked list from Example 1 above:

1---2---3---4---5---6--NULL
|
7---8---9---10--NULL
|
11--12--NULL
The serialization of each level is as follows:

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
To serialize all levels together we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
Merging the serialization of each level and removing trailing nulls we obtain:

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]


Constraints:

Number of Nodes will not exceed 1000.
1 <= Node.val <= 10^5

*/

// Definition for a Node.
class Node {
public:
int val;
Node* prev;
Node* next;
Node* child;
};

// Runtime: 4 ms, faster than 94.21% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
// Memory Usage : 7.5 MB, less than 100.00% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
class Solution {
public:
	Node* getLast(Node* node) {
		Node* prev = nullptr;
		while (node) {
			prev = node;
			node = node->next;
		}
		return prev;
	}

	Node* flatten(Node* head) {
		Node* current = head;

		while (current) {
			Node* tail = current->next;

			if (current->child) {

				Node* sublist = flatten(current->child);
				current->child = nullptr;

				current->next = sublist;
				sublist->prev = current;

				if (tail) {
					Node* last = getLast(sublist);
					tail->prev = last;
					last->next = tail;
				}
			}

			current = tail;
		}

		return head;
	}
};

//class Solution {
//public:
//	Node* getLast(Node* node) {
//		Node* prev = nullptr;
//		while (node) {
//			prev = node;
//			node = node->next;
//		}
//		return prev;
//	}
//
//	Node* flatten(Node* head) {
//		Node* current = head;
//
//		//stack<pair<Node*, Node*>> states;
//
//		while (current) {
//			Node* tail = current->next;
//
//			if (current->child) {
//
//				Node* sublist = flatten(current->child);
//				current->child = nullptr;
//
//				current->next = sublist;
//				sublist->prev = current;
//
//				if (tail) {
//					Node* last = getLast(sublist);
//					tail->prev = last;
//					last->next = tail;
//				}
//			}
//
//			current = tail;
//		}
//
//		return head;
//	}
//};

void printSingleList(Node* pHead) {
	while (pHead) {
		cout << pHead->val;
		if (pHead->next)
			cout << " ";

		if (pHead->child)
			cout << "(CHILD!)";

		if (pHead->next && pHead->next->prev != pHead)
			cout << "(BROKEN LINK!)";

		pHead = pHead->next;
	}
}

Node* constructNode(int v) {
	Node* node = new Node();
	node->val = v; 
	node->prev = nullptr;
	node->next = nullptr;
	node->child = nullptr;
	return node;
}

Node* constructLevel(initializer_list<int> vals) {
	Node* pHead = nullptr, *pCurr = nullptr;
	for (int v : vals) {
		Node* pNew = constructNode(v);
		if (!pCurr) {
			pHead = pNew;
		}
		else {
			pCurr->next = pNew;
			pNew->prev = pCurr;
		}
		pCurr = pNew;
	}
	return pHead;
}

int main()
{
	{
		Node* pHead1 = constructLevel({ 1, 2, 3, 4, 5, 6 });
		Node* pHead2 = constructLevel({ 7, 8, 9, 10 });
		Node* pHead3 = constructLevel({ 11, 12 });

		pHead1->next->next->child = pHead2;

		pHead2->next->child = pHead3;

		printSingleList(Solution().flatten(pHead1));
		cout << endl; // 1,2,3,7,8,11,12,9,10,4,5,6
	}

	{
		Node* pHead1 = constructLevel({ 1, 2 });
		Node* pHead2 = constructLevel({ 3 });

		pHead1->child = pHead2;

		printSingleList(Solution().flatten(pHead1));
		cout << endl; // 1,3,2
	}

	{
		printSingleList(Solution().flatten(nullptr));
		cout << endl; // []
	}

    return 0;
}

