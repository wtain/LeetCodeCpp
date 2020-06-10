
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <numeric>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3351/
https://leetcode.com/problems/random-pick-with-weight/

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input:
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input:
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.
*/

//Runtime: 196 ms, faster than 36.62% of C++ online submissions for Random Pick with Weight.
//Memory Usage : 40.6 MB, less than 30.17% of C++ online submissions for Random Pick with Weight.
class Solution {

	class Random
	{
	public:
		Random()
		{
			srand(static_cast<unsigned>(time(nullptr)));
		}

		int Next()
		{
			return rand();
		}

		int Next(int a, int b)
		{
			return a + Next() % (b - a + 1);
		}
	};

	vector<int> probs;
	Random random;
public:

	Solution(vector<int>& w) {
		probs.reserve(w.size());
		partial_sum(begin(w), end(w), back_inserter(probs));
	}

	int pickIndex() {
		if (probs.empty())
			return -1;
		int x = random.Next() % probs.back();
		return upper_bound(begin(probs), end(probs), x) - begin(probs);
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(w);
* int param_1 = obj->pickIndex();
*/

void test(const size_t nIterations, vector<int> w) {
	Solution s(w);
	vector<int> counts(w.size());
	for (size_t i = 0; i < nIterations; ++i)
		++counts[s.pickIndex()];
	int total = 0;
	for (size_t i = 0; i < counts.size(); ++i)
		total += counts[i];
	for (size_t i = 0; i < counts.size(); ++i)
		cout << setprecision(4) << static_cast<double>(counts[i]) / total << " ";
	cout << endl;
}

int main()
{
	test(10000, { 5, 2, 3 });
    return 0;
}

