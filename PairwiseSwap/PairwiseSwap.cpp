
#include <iostream>

class List
{
private:
	struct Node
	{
		Node* pNext;
		int data;

		explicit Node(int value) : data(value), pNext(nullptr) {}
	};

	Node* m_pHead;

public:

	explicit List(int N)
	{
		m_pHead = nullptr;
		for (int i = 0; i < N; ++i)
		{
			Node* pTail = m_pHead;
			m_pHead = new Node(N - i);
			m_pHead->pNext = pTail;
		}
	}

	~List()
	{
		Node* pHead = m_pHead;
		while (pHead)
		{
			Node* pNext = pHead->pNext;
			delete pHead;
			pHead = pNext;
		}
	}

	friend std::ostream& operator << (std::ostream& stream, const List& list)
	{
		Node* pHead = list.m_pHead;
		while (pHead)
		{
			stream << pHead->data << " ";
			pHead = pHead->pNext;
		}
		return stream;
	}

	void PairwiseSwapFast()
	{
		m_pHead = PairwiseSwapFast(m_pHead);
	}

private:
	static Node* PairwiseSwapFast(Node* pHead)
	{
		if (!pHead)
			return nullptr;
		if (!pHead->pNext)
			return pHead;
	
		Node* pNewHead = pHead->pNext;
		Node* pPrev = nullptr;
		while (pHead && pHead->pNext)
		{
			Node* pSecond = pHead->pNext;
			Node* pTail = pSecond->pNext;
			pSecond->pNext = pHead;
	
			if (pPrev)
				pPrev->pNext = pSecond;
			
			pHead->pNext = pTail;
	
			pPrev = pHead;
			pHead = pTail;
		}
	
		return pNewHead;
	}
};

//Node* Generate(int N)
//{
//	Node* pHead = nullptr;
//	for (int i = 0; i < N; ++i)
//	{
//		Node* pTail = pHead;
//		pHead = new Node(N - i);
//		pHead->pNext = pTail;
//	}
//	return pHead;
//}

//void PrintList(Node* pHead)
//{
//	while (pHead)
//	{
//		std::cout << pHead->data << " ";
//		pHead = pHead->pNext;
//	}
//	std::cout << std::endl;
//}

//Node* PairwiseSwap(Node* pHead)
//{
//	if (!pHead)
//		return nullptr;
//	if (!pHead->pNext)
//		return pHead;
//	Node* pSecond = pHead->pNext;
//	pHead->pNext = PairwiseSwap(pSecond->pNext);
//	pSecond->pNext = pHead;
//	return pSecond;
//}
//
//Node* PairwiseSwapFast(Node* pHead)
//{
//	if (!pHead)
//		return nullptr;
//	if (!pHead->pNext)
//		return pHead;
//
//	Node* pNewHead = pHead->pNext;
//	Node* pPrev = nullptr;
//	while (pHead && pHead->pNext)
//	{
//		Node* pSecond = pHead->pNext;
//		Node* pTail = pSecond->pNext;
//		pSecond->pNext = pHead;
//
//		if (pPrev)
//			pPrev->pNext = pSecond;
//		
//		pHead->pNext = pTail;
//
//		pPrev = pHead;
//		pHead = pTail;
//	}
//
//	return pNewHead;
//}

int main()
{
	/*Node* pHead = Generate(10);
	PrintList(pHead);

	pHead = PairwiseSwap(pHead);

	PrintList(pHead);

	pHead = PairwiseSwapFast(pHead);

	PrintList(pHead);

	pHead = Generate(9);

	PrintList(pHead);

	pHead = PairwiseSwapFast(pHead);

	PrintList(pHead);*/

	List list1(10);
	std::cout << list1 << std::endl;
	list1.PairwiseSwapFast();
	std::cout << list1 << std::endl;

	List list2(9);
	std::cout << list2 << std::endl;
	list2.PairwiseSwapFast();
	std::cout << list2 << std::endl;

    return 0;
}

