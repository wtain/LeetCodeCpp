
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:

	ListNode* merge(ListNode* h1, ListNode* h2)
	{
		ListNode* dummy = new ListNode(0);

		ListNode* current = dummy;
		while (h1 && h2)
		{
			if (h1->val < h2->val)
			{
				current->next = h1;
				h1 = h1->next;
			}
			else
			{
				current->next = h2;
				h2 = h2->next;
			}
			current = current->next;
		}

		while (h1)
		{
			current->next = h1;
			h1 = h1->next;
			current = current->next;
		}

		while (h2)
		{
			current->next = h2;
			h2 = h2->next;
			current = current->next;
		}

		return dummy->next;
	}

	ListNode* sortList(ListNode* head) 
	{
		if (!head || !head->next)
			return head;

		ListNode* s = head;
		ListNode* f = head->next;
		while (f && f->next)
		{
			s = s->next;
			f = f->next->next;
		}

		ListNode* list1 = head;
		ListNode* list2 = s->next;
		s->next = nullptr;
		
		list1 = sortList(list1);
		list2 = sortList(list2);

		return merge(list1, list2);
	}
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

int main()
{
	const vector<int> v1 = { 4, 2, 1, 3 };
	ListNode* l1 = ConstructList(v1);
	PrintList(l1);

	auto ls = Solution().sortList(l1);
	PrintList(ls);

    return 0;
}

