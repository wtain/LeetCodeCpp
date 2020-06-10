

#define NULL 0


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


	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* result = NULL;

		ListNode* pFirst = l1;
		ListNode* pSecond = l2;

		ListNode* pCurrent = NULL;

		int carry = 0;
		while (pFirst || pSecond || carry)
		{
			int n = carry;
			if (pFirst)
				n += pFirst->val;
			if (pSecond)
				n += pSecond->val;
			carry = n / 10;
			n %= 10;

			ListNode* d = new ListNode(n);
			
			if (!pCurrent)
				pCurrent = result = d;
			else
			{
				pCurrent->next = d;
				pCurrent = d;
			}

			if (pFirst)
				pFirst = pFirst->next;
			if (pSecond)
				pSecond = pSecond->next;
		}
		if (!result)
			result = new ListNode(0);
		return result;
	}
};

int main()
{
    return 0;
}

