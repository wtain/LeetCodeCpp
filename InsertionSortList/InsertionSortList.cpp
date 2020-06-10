
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:

	ListNode* insertNode(ListNode* sortedList, ListNode* curr)
	{
		ListNode* place = sortedList;
		ListNode* prev = nullptr;
		while (place && curr->val > place->val)
		{
			prev = place;
			place = place->next;
		}

		if (!prev)
		{
			curr->next = sortedList;
			sortedList = curr;
		}
		else
		{
			prev->next = curr;
			curr->next = place;
		}
		return sortedList;
	}

	ListNode* insertionSortList(ListNode* head) 
	{
		if (!head || !head->next)
			return head;

		ListNode* sortedList = head;
		ListNode* tail = head->next;
		head->next = nullptr;

		while (tail)
		{
			ListNode* curr = tail;
			ListNode* rest = tail->next;

			sortedList = insertNode(sortedList, curr);

			tail = rest;
		}

		return sortedList;
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
	//const vector<int> v1 = { 4, 2, 1, 3 };
	const vector<int> v1 = { -1,5,3,4,0 };
	ListNode* l1 = ConstructList(v1);
	PrintList(l1);

	auto ls = Solution().insertionSortList(l1);
	PrintList(ls);

    return 0;
}

