
#include <vector>
#include <algorithm>
#include <iostream>

#ifndef NULL
#define NULL 0
#endif

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

	struct ListComparator
	{
		bool operator() (ListNode* left, ListNode* right) const
		{
			return left->val > right->val;
		}
	};

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return NULL;
		ListNode* rv = NULL, *current = NULL;
		auto it = remove_if(begin(lists), end(lists), [](ListNode* n) 
		{ 
			return !n; 
		});
		lists.erase(it, end(lists));
		make_heap(begin(lists), end(lists), ListComparator());
		while (!lists.empty())
		{
			ListNode* li = lists.front();
			pop_heap(begin(lists), end(lists), ListComparator());
			lists.pop_back();
			if (!rv)
				rv = current = li;
			else
			{
				current->next = li;
				current = li;
			}
			li = li->next;
			if (li)
			{
				lists.push_back(li);
				push_heap(begin(lists), end(lists), ListComparator());
			}
		}
		return rv;
	}
};

int main()
{
	ListNode* l1 = new ListNode(1);
	vector<ListNode*> lists = { l1 };
	//vector<ListNode*> lists = { NULL, NULL };

	cout << Solution().mergeKLists(lists) << endl;

    return 0;
}

