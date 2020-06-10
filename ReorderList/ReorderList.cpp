

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/reorder-list/

Given a singly linked list L: L0?L1?…?Ln-1?Ln,
reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void PrintList(ListNode* node)
{
	while (node)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}

ListNode* ConstructList(const std::vector<int>& v)
{
	ListNode* result = nullptr;
	for (int i = v.size() - 1; i >= 0; --i)
	{
		ListNode* node = new ListNode(v[i]);
		node->next = result;
		result = node;
	}
	return result;
}

//class Solution {
//public:
//	void reorderList(ListNode* head)  // wrong task understanding!!
//	{
//		if (!head || !head->next)
//			return;
//
//		ListNode* list1 = head;
//		ListNode* list2 = head->next;
//
//		ListNode* curr1 = list1;
//		ListNode* curr2 = list2;
//		bool turn = true;
//		ListNode* tail = head->next->next;
//		while (tail)
//		{
//			ListNode* next = tail->next;
//			if (turn)
//			{
//				curr1->next = tail;
//				curr1 = curr1->next;
//				tail->next = nullptr;
//			}
//			else
//			{
//				tail->next = curr2;
//				curr2->next = nullptr;
//				list2 = curr2 = tail;				
//			}
//			tail = next;
//			turn = !turn;
//		}
//
//		curr1 = list1;
//		curr2 = list2;
//
//		ListNode* curr = head;
//		ListNode* next1 = curr1->next;
//		ListNode* next2 = curr2;
//		ListNode* next = curr2;
//		turn = false;
//		while (next)
//		{
//			if (turn)
//			{
//				curr->next = next1;
//				next1 = next1->next;
//				next = next2;
//			}
//			else
//			{
//				curr->next = next2;
//				next2 = next2->next;
//				next = next1;
//			}
//			curr = curr->next;
//			turn = !turn;
//		}
//	}
//};

//class Solution {
//public:
//	void reorderList(ListNode* head)
//	{
//		ListNode* list1 = NULL; // odd
//		ListNode* list2 = NULL; // even
//		bool turnOdd = true;
//		while (head)
//		{
//			ListNode* next = head->next;
//			if (turnOdd)
//			{
//				list1->next = head;
//				head->next = NULL;
//			}
//			else
//			{
//				head->next = list2;
//				list2 = head;
//			}
//			turnOdd = !turnOdd;
//			head = next;
//		}
//	}
//};

class Solution {                                                                                   
public:

	ListNode* Middle(ListNode* head)
	{
		ListNode* p1 = head;
		ListNode* p2 = head;
		while (p2)
		{
			p2 = p2->next;
			if (!p2)
				break;
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}

	ListNode* Reverse(ListNode* head)
	{
		ListNode* prev = NULL;
		while (head)
		{
			ListNode* next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		return prev;
	}

	void PairwiseMerge(ListNode* head, ListNode* tail)
	{
		ListNode* p1 = head;
		ListNode* p2 = tail;
		while (p1)
		{
			ListNode* next1 = p1->next;
			ListNode* next2 = p2 ? p2->next : NULL;
			if (p2)
			{
				p1->next = p2;
				p2->next = next1;
			}

			p1 = next1;
			p2 = next2;
		}
	}

	void reorderList(ListNode* head)
	{
		if (!head || !head->next)
			return;
		ListNode* mid = Middle(head);
		ListNode* tail = mid->next;
		mid->next = NULL;
		tail = Reverse(tail);
		PairwiseMerge(head, tail);
	}
};

int main()
{
	vector<int> v1 = { 1,2,3,4 };
	auto list1 = ConstructList(v1);
	vector<int> v2 = { 1,2,3,4,5 };
	auto list2 = ConstructList(v2);

	Solution().reorderList(list1);
	PrintList(list1);

	Solution().reorderList(list2);
	PrintList(list2);

    return 0;
}

