
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/binary-search/


Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1


Note:

You may assume that all elements in nums are unique.
n will be in the range [1, 10000].
The value of each element in nums will be in the range [-9999, 9999].
Accepted

*/

int Search(const std::vector<int>& vec, const int v)
{
	int l = 0, r = vec.size(); // O = 0..l + r..n-1
	while (l < r)
	{
		int m = l + (r - l) / 2; // m = l..r-1
		if (vec[m] == v)
			return m;
		if (vec[m] < v) // l..m-1 m m+1..r
			l = m + 1;
		else
			r = m;
	}
	/*if (l < vec.size() && l >=0 && vec[l] == v)
		return l;*/
	return -1;
}

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size(); // O = 0..l + r..n-1
		while (l < r)
		{
			int m = l + (r - l) / 2; // m = l..r-1
			if (nums[m] == target)
				return m;
			if (nums[m] < target) // l..m-1 m m+1..r
				l = m + 1;
			else
				r = m;
		}
		/*if (l < vec.size() && l >=0 && vec[l] == v)
		return l;*/
		return -1;
	}
};

int main()
{
	std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<int> v2 = { 1, 2, 3, 4, 5, 5, 5, 8, 9, 10 };
	std::vector<int> v3 = { 1, 2, 3, 4, 5, 5, 5, 8, 9 };
	std::vector<int> v4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::cout << Search(v1, 0) << std::endl;
	std::cout << Search(v1, 1) << std::endl;
	std::cout << Search(v1, 5) << std::endl;
	std::cout << Search(v1, 10) << std::endl;
	std::cout << Search(v1, 100) << std::endl;

	std::cout << std::endl;

	std::cout << Search(v2, 0) << std::endl;
	std::cout << Search(v2, 1) << std::endl;
	std::cout << Search(v2, 5) << std::endl;
	std::cout << Search(v2, 10) << std::endl;
	std::cout << Search(v2, 100) << std::endl;

	std::cout << std::endl;

	std::cout << Search(v3, 0) << std::endl;
	std::cout << Search(v3, 1) << std::endl;
	std::cout << Search(v3, 5) << std::endl;
	std::cout << Search(v3, 10) << std::endl;
	std::cout << Search(v3, 100) << std::endl;

	std::cout << std::endl;

	std::cout << Search(v4, 0) << std::endl;
	std::cout << Search(v4, 1) << std::endl;
	std::cout << Search(v4, 5) << std::endl;
	std::cout << Search(v4, 10) << std::endl;
	std::cout << Search(v4, 100) << std::endl;

    return 0;
}



/*

void urlify(std::string& s);

std::string s0 = "my url";
s0.reserve(20);
urlify(s0);
assert(s0 == "my%20url");


void urlify(std::string& s)
{
// 01234567
// ab c de0
// 2 spaces -> increase 2*2=4 -> 8+4=12 0..11
// 0         1
// 012345678901
//     ab c de0

// ab%20b c de0
// ab%20c%20de0


// 0         1
// 012345678901
// ab c de
//       ^    ^

static const std::string SpaceToken = "%20";

const size_t n = std::count(std::begin(s), std::end(s), ' '); // N
const size_t sz = 2 * n;
s.resize(s.length() + sz);
auto w = s.rbegin();
auto r = w + sz;
while (r != s.rend()) // N
{
if (*r != ' ')
*w++ = *r++;
else
{
w = std::copy(SpaceToken.rbegin(), SpaceToken.rend(), w);
++r;
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node
{
int data;
Node* pLeft;
Node* pRight;

explicit Node(int d)
: data(d)
, pLeft(nullptr)
, pRight(nullptr)
{
}
};

class TreeSummator
{
std::vector<int> m_levelSums;
public:

explicit TreeSummator(Node* pRoot)
{
Initialize(Node* pRoot, 0);
for (size_t i = 1; i < m_levelSums.size(); ++i)
m_levelSums[i] += m_levelSums[i-1];
}

int SumLevels(size_t maxLevel)
{
if (maxLevel >= m_levelSums.size())
throw std::out_of_range("Level is too deep");
return m_levelSums[maxLevel];
}

private:

void Initialize(Node* pRoot, size_t level)
{
if (!pRoot)
return;
if (m_levelSums.size() == level)
m_levelSums.push_back(pRoot->data);
else
m_levelSums[level] += pRoot->data;

if (pRoot->pLeft)
Initialize(pRoot->pLeft, level + 1);

if (pRoot->pRight)
Initialize(pRoot->pRight, level + 1);
}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



*/