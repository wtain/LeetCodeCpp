
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3422/
https://leetcode.com/problems/iterator-for-combination/

Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.


Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false


Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.

Generate all combinations as a preprocessing.
Use bit masking to generate all the combinations.
*/

//Runtime: 28 ms, faster than 69.34% of C++ online submissions for Iterator for Combination.
//Memory Usage : 12.3 MB, less than 81.82% of C++ online submissions for Iterator for Combination.
//Runtime: 32 ms, faster than 52.43% of C++ online submissions for Iterator for Combination.
//Memory Usage : 12.4 MB, less than 71.04% of C++ online submissions for Iterator for Combination.
//Runtime: 32 ms, faster than 52.43% of C++ online submissions for Iterator for Combination.
//Memory Usage : 12.2 MB, less than 90.06% of C++ online submissions for Iterator for Combination.
class CombinationIterator {
	vector<bool> mask;
	string chars;
	bool bHasNext;
	bool bHasCurrent;
public:
	CombinationIterator(string characters, int combinationLength)
	: chars(characters) {
		//sort(begin(chars), end(chars));
		mask.resize(chars.length());
		for (int i = 0; i < combinationLength; ++i)
			mask[i] = true;
		bHasNext = combinationLength > 0;
		bHasCurrent = bHasNext;
	}

	bool checkCanMoveMask() const {
		int i = 0;
		while (i < mask.size() && !mask[i])
			++i;
		while (i < mask.size() && mask[i])
			++i;
		return i < mask.size();
	}

	void moveMask() {
		// 110 -> 101
		// 101 -> 011
		// 011
		/// 11..11000..00 - first state
		/// 00..00111..11 - terminal state
		if (!bHasNext) {
			bHasCurrent = false;
			return;
		}
		int zeroPos = -1;
		int i = mask.size() - 1;
		int cnt1 = 0;
		for (; i >= 0; --i) {
			if (!mask[i])
				zeroPos = i;
			else if (zeroPos != -1)
				break;
			else {
				++cnt1;
				mask[i] = false;
			}
		}
		mask[i] = false;
		mask[zeroPos] = true;
		for (int j = zeroPos + 1; j < mask.size() && cnt1 > 0; ++j, cnt1--) {
			mask[j] = true;
		}
		bHasNext = checkCanMoveMask();
	}

	string buildCombination() {
		string result;
		for (int i = 0; i < mask.size(); ++i)
			if (mask[i])
				result += chars[i];
		return result;
	}

	string next() {
		auto result = buildCombination();
		moveMask();
		return result;
	}

	bool hasNext() {
		return bHasCurrent;
	}
};

/**
* Your CombinationIterator object will be instantiated and called as such:
* CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
* string param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/

int main()
{
	{
		CombinationIterator it("ahijp", 2);
		while (it.hasNext())
			cout << it.next() << endl;
		// ah ai aj ap hi hj

		/*
		a h i j p
		1 1 0 0 0
		1 0 1 0 0
		1 0 0 1 0
		1 0 0 0 1
		0 1 1 0 0
		0 1 0 1 0
		*/
	}
	cout << endl << endl;
	
	{
		CombinationIterator it("bvwz", 2);
		while (it.hasNext())
			cout << it.next() << endl;
		// bv bw bz

		/*
		     b v w z
			 1 1 0 0
			 1 0 1 0
			 1 0 0 1
		*/
	}
	cout << endl << endl;

	CombinationIterator iterator("abc", 2); // creates the iterator.

	cout << iterator.next() << endl; // returns "ab"
	cout << boolalpha << iterator.hasNext() << endl; // returns true
	cout << iterator.next() << endl; // returns "ac"
	cout << boolalpha << iterator.hasNext() << endl; // returns true
	cout << iterator.next() << endl; // returns "bc"
	cout << boolalpha << iterator.hasNext() << endl; // returns false

	cout << endl << endl;
	{
		CombinationIterator it("abc", 2);
		while (it.hasNext())
			cout << it.next() << endl;
	}

	cout << endl << endl;
	{
		CombinationIterator it("abcd", 3);
		while (it.hasNext())
			cout << it.next() << endl;
	}

    return 0;
}

