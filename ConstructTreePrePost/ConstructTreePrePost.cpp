
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

/*
TreeNode* constructFromPrePostImpl(Iterator pre1, Iterator pre2, Iterator post1, Iterator post2)
{
if (pre1 == pre2)
return NULL;
const int rootVal = *pre1;
TreeNode* root = new TreeNode(*pre1);
Iterator postk = find(post1, post2, rootVal);

if (post1 == post2)
return root;

Iterator prel = pre1 + 1;
Iterator postr = postk - 1;

Iterator preRbegin = pre2;
Iterator postRbegin = post1;

Iterator preRend = pre2;
Iterator postRend = postr;

Iterator postl = post2;
Iterator prer = pre2;

Iterator preLbegin = prel;
Iterator preLend = pre2;

Iterator postLbegin = post1;
Iterator postLend = post2;

if (prel != pre2)
{
const int lVal = *prel;
postl = find(post1, post2, lVal);
postRbegin = postl + 1;
postLend = postl;
}

if (postr != post1)
{
const int rVal = *postr;
prer = find(pre1, pre2, rVal);
preRbegin = prer;
preLend = prer;
}

root->left = constructFromPrePostImpl(preLbegin, preLend, postLbegin, postLend);
root->right = constructFromPrePostImpl(preRbegin, preRend, postRbegin, postRend);

return root;
}
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:

	typedef vector<int>::const_iterator Iterator;

	pair<TreeNode*, TreeNode*> constructFromPrePostImpl(Iterator pre1, Iterator pre2, Iterator post1, Iterator post2)
	{
		if (pre1 >= pre2)
			return{};
		const int Val1 = *pre1;

		Iterator postk = find(post1, post2, Val1); // guaranteed exists
		
		if (postk + 1 == post2)
		{
			TreeNode* root = new TreeNode(Val1);
			auto c = constructFromPrePostImpl(pre1 + 1, pre2, post1, post2 - 1);
			root->left = c.first;
			root->right = c.second;

			return { root, NULL };
		}
		else
		{
			// two trees...
			Iterator leftRootPre = pre1;
			Iterator leftRootPost = postk;

			Iterator rightRootPost = (post2 - 1);
			Iterator rightRootPre = find(pre1, pre2, *rightRootPost);

			auto c1 = constructFromPrePostImpl(pre1, rightRootPre, post1, leftRootPost + 1);
			auto c2 = constructFromPrePostImpl(rightRootPre, pre2, leftRootPost+1, post2);

			return{ c1.first, c2.first };
		}
	}

	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
	{
		return constructFromPrePostImpl(begin(pre), end(pre), begin(post), end(post)).first;
	}
};

/*
pre:  6, 10, 8, 5,       4, 2, 9, 3,   1, 7
post:                    2, 3, 9, 4,   7, 1,        5, 8, 10, 6
*/

/*
pre:    n A B =  n (l A1 A2) (r B1 B2)
post:	A B n =  (A1 A2 l) (B1 B2 r) n

           n                 n
		 A   B			 l       r
		               A1 A2   B1 B2


1 A B
A B 1


       4
  2		  6
1   3	5   7

pre?:  4 2 1 3 6 5 7
post?: 1 3 2 5 7 6 4

        1
	  2	   3
	4	5 6	 7

pre:  1, 2, 4, 5, 3, 6, 7
post: 4, 5, 2, 6, 7, 3, 1

root=1
pre  AB: 2, 4, 5, 3, 6, 7
post AB: 4, 5, 2, 6, 7, 3
          1
		 2
pre  A1: 4, 5
post A1: 4, 5

   1
  2	3

1 2 3
2 3 1


pre:  6, 10, 8, 5,       4, 2, 9, 3,   1, 7
post:                    2, 3, 9, 4,   7, 1,        5, 8, 10, 6


pre:  6, 10, 8, 5, 4, 2, 9, 3, 1, 7
post: 2, 3, 9, 4, 7, 1, 5, 8, 10, 6

pre:  6 (10, 8, 5, 4, 2, 9, 3, 1, 7)
post: (2, 3, 9, 4, 7, 1, 5, 8, 10) 6

                 6

pre:  6 (10, 8, 5) (4, 2, 9, 3, 1, 7)
post: (2, 3, 9, 4, 7, 1) (5, 8, 10) 6

                     6
			   10
			  8  5


pre:  6 (10, 8, 5, 4, 2, 9, 3, 1, 7)
post: (2, 3, 9, 4, 7, 1, 5, 8, 10) 6
               
pre:  6 (10, 8(5, 4, 2, 9, 3, 1, 7)))
post: (2, 3, 9, 4, 7, 1, 5, 8, 10) 6

4, 2, 9, 3,  1 7
2, 3, 9, 4,  7 1

2, 9, 3
2, 3, 9

			        6
			  10         8
			           5     4
					  1	7   9   2
					       3

6(10,8(5(1,7),4(9(3),2)))

					     6
				     10
				  8
			   5
		  4		    1
	  2	 	 9	  7
		   3


6(10(8(5(4(2,9(3,)),1(7,)),),),)


6
(
	10
	(
		8
		(
			5
			(
				4
				(
					2,
					9
					(
						3
						,
					)),1(7,
				)
			)
		)
		,
	)
	,
)



*/

// 1(2,3(4,5))
/*
1
2	   3
4	 5
*/
/*
TreeNode* constructTreeImpl(const std::string& s, int i1, int i2)
{
if (i1 > i2)
return NULL;
const std::string ebg = s.substr(i1, i2 - i1 + 1);
cout << ebg << endl;
int v = 0;
while (isdigit(s[i1]) && i1 <= i2)
{
v *= 10;
v += s[i1] - '0';
++i1;
}
TreeNode* root = new TreeNode(v);
if (i1 <= i2)
{
if (s[i1] == '(')
{
++i1;
int j1 = i1;
int b = 1;
while (i1 <= i2 && b > 0)
{
if (s[i1] == '(')
++b;
if (s[i1] == ')')
--b;
++i1;
}
--i1;
int j2 = i1;
i1 = j1;
while (s[i1] != ',')
++i1;
int cp = i1;
if (j1 < cp)
root->left = constructTreeImpl(s, j1, cp - 1);
if (j2 > cp)
root->right = constructTreeImpl(s, cp+1, j2-1);
}
}
return root;
}
*/

class Helper
{
	int parseInt(const std::string& s, int& i, int ie)
	{
		int v = 0;
		while (i <= ie && isdigit(s[i]))
		{
			v *= 10;
			v += s[i] - '0';
			++i;
		}
		return v;
	}

	/*
		INT = D+
		TREE = INT|INT(TREE,TREE)|e
	*/
	TreeNode* constructTreeImpl(const std::string& s, int& i, int ie)
	{
		if (i > ie || !isdigit(s[i]))
			return NULL;
		int v = parseInt(s, i, ie);
		
		TreeNode* node = new TreeNode(v);
		
		if (i <= ie)
		{
			if (s[i] == '(')
			{
				++i;
				node->left = constructTreeImpl(s, i, ie);
				if (s[i] != ',')
					throw 1;
				++i;
				node->right = constructTreeImpl(s, i, ie);
				if (s[i] != ')')
					throw 1;
				++i;
			}
			/*else
				throw 1;*/
		}

		return node;
	}

public:

	TreeNode* constructTree(const std::string& s)
	{
		//return constructTreeImpl(s, 0, s.length() - 1);
		int i = 0;
		return constructTreeImpl(s, i, s.length() - 1);
	}

	void printInOrder(TreeNode* root)
	{
		if (!root)
			return;
		cout << root->val << ", ";
		printInOrder(root->left);
		printInOrder(root->right);
	}

	void printPostOrder(TreeNode* root)
	{
		if (!root)
			return;
		printPostOrder(root->left);
		printPostOrder(root->right);
		cout << root->val << ", ";
	}
};

int main()
{
	/*
	vector<int> pre = { 1, 2, 4, 5, 3, 6, 7 }, 
		       post = { 4, 5, 2, 6, 7, 3, 1 };
	*/
	vector<int> pre = { 6, 10, 8, 5, 4, 2, 9, 3, 1, 7 }, 
		       post = { 2, 3, 9, 4, 7, 1, 5, 8, 10, 6 };

	TreeNode* root = Solution().constructFromPrePost(pre, post);

	//TreeNode* root = Helper().constructTree("1(2,3(4,5))");
	//TreeNode* root = Helper().constructTree("6(10,8(5(1,7),4(9(3,),2)))");
	//TreeNode* root = Helper().constructTree("6(10,8(5(9(3,),2),4(1,7)))");
	/*
	TreeNode* root = Helper().constructTree("6(10(8(5(4(2,9(3,)),1(7,)),),),)");
	*/
	Helper().printInOrder(root);
	cout << endl;
	Helper().printPostOrder(root);
	cout << endl;
	

    return 0;
}

