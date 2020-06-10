
#include <iostream>
#include <vector>
#include <stack>
#include <functional>

using namespace std;

struct Node
{
	Node* left, *right;
	char v;

	explicit Node(char c) : v(c), left(nullptr), right(nullptr) {}
};

// null -> nullptr
// function<Node*, bool> ->
// Modifying the input tree
vector<Node*> getForestAfterNodeCut(Node* root, function<bool(Node*)> shouldBeErased)
{
	stack<pair<Node*, Node*>> toVisit; // node and parent
	vector<Node*> results;
	if (!root)
		return results;
	toVisit.push(make_pair(root, nullptr));
	if (!shouldBeErased(root))
		results.push_back(root);
	while (!toVisit.empty())
	{
		auto nodeAndParent = toVisit.top();
		toVisit.pop();
		Node* node = nodeAndParent.first;
		Node* parent = nodeAndParent.second;
		if (shouldBeErased(node))
		{
			if (parent)
			{
				if (parent->left == node)
					parent->left = nullptr;
				else // right
					parent->right = nullptr;
			}
			if (node->left && !shouldBeErased(node->left))
				results.push_back(node->left);
			if (node->right && !shouldBeErased(node->right))
				results.push_back(node->right);
		}
		if (node->left)
			toVisit.push(make_pair(node->left, node));
		if (node->right)
			toVisit.push(make_pair(node->right, node));
	}
	return results;
}

bool shouldBeErased(Node* n)
{
	return n->v == 'B' || n->v == 'I';
}

void printTree(Node* root)
{
	if (!root)
		return;
	cout << root->v;
	if (root->left || root->right)
	{
		cout << "(";
		printTree(root->left);
		if (root->left && root->right)
			cout << ",";
		printTree(root->right);
		cout << ")";
	}
}

void printForest(const vector<Node*>& forest)
{
	for (const auto& n : forest)
	{
		printTree(n);
		cout << endl;
	}
	cout << endl;
}

int main()
{
	Node* F = new Node('F');
	Node* B = new Node('B');
	Node* G = new Node('G');
	F->left = B;
	F->right = G;
	Node* A = new Node('A');
	Node* D = new Node('D');
	B->left = A;
	B->right = D;
	Node* C = new Node('C');
	Node* E = new Node('E');
	D->left = C;
	D->right = E;
	Node* I = new Node('I');
	G->right = I;
	Node* H = new Node('H');
	I->left = H;

	printTree(F);
	cout << endl << endl;
	auto v = getForestAfterNodeCut(F, shouldBeErased);
	printForest(v);
	
    return 0;
}

