
#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* left, *right, *parent;

	Node(int v) : value(v), left(nullptr), right(nullptr), parent(nullptr)
	{
		
	}
};

int depth(Node* n)
{
	int d = 0;
	while (n)
	{
		++d;
		n = n->parent;
	}
	return d;
}

Node* findCommonAncestor(Node* left, Node* right)
{
	int d1 = depth(left);
	int d2 = depth(right);
	while (d1 > d2)
	{
		--d1;
		left = left->parent;
	}
	while (d2 > d1)
	{
		--d2;
		right = right->parent;
	}
	while (d1 > 1)
	{
		--d1;
		left = left->parent;
	}
	return left;
}

int main()
{
	Node* root = new Node(5);
	Node* n1 = new Node(1); root->left = n1; n1->parent = root;
	Node* n2 = new Node(2); root->right = n2; n2->parent = root;
	Node* n3 = new Node(3); n2->right = n3; n3->parent = n2;

	cout << findCommonAncestor(n1, n3)->value << endl;

    return 0;
}

