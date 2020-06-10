
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/split-linked-list-in-parts/

Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input:
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].
Example 2:
Input:
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
Note:

The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Runtime: 8 ms, faster than 92.27% of C++ online submissions for Split Linked List in Parts.
Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Split Linked List in Parts.
*/
class Solution {
public:

	int getLength(ListNode* pHead) {
		int l = 0;
		while (pHead) {
			pHead = pHead->next;
			++l;
		}
		return l;
	}

	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		const int n = getLength(root);
		int li = n / k;
		if (n % k)
			++li;

		int mod = n % k;

		vector<ListNode*> result(k);

		int currentList = 0, currentLength = 0;
		while (root) {
			auto next = root->next;
			//auto tail = result[currentList];

			if (!currentLength)
				result[currentList] = root;

			if (++currentLength == li) {

				currentLength = 0;

				if (mod && currentList+1 == mod)
					--li;

				root->next = nullptr;

				++currentList;
			}

			root = next;
		}

		return result;
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

void printSolution(const vector<ListNode*>& result) {
	for (ListNode* pHead : result) {
		cout << "[";
		printList(pHead);
		cout << "] ";
	}
	cout << endl;
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
	printSolution(Solution().splitListToParts(constructList({ 1, 2, 3 }), 5)); // [1],[2],[3],[],[]
	printSolution(Solution().splitListToParts(constructList({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }), 3)); // [1, 2, 3, 4], [5, 6, 7], [8, 9, 10]

    return 0;
}

