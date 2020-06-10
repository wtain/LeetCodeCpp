
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/peeking-iterator/

Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

Example:

Assume that the iterator is initialized to the beginning of the list: [1,2,3].

Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
You call next() the final time and it returns 3, the last element.
Calling hasNext() after that should return false.
Follow up: How would you extend your design to be generic and work with all types, not just integer?
*/

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
	vector<int>::const_iterator i, e;
public:
	Iterator(const vector<int>& nums) : i(begin(nums)), e(end(nums)) {}
	Iterator(const Iterator& iter) : i(iter.i), e(iter.e) {}
	virtual ~Iterator() {}
	// Returns the next element in the iteration.
	int next() { return *i++; }
	// Returns true if the iteration has more elements.
	bool hasNext() const { return i != e; }
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.

	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return Iterator(*this).next();
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		return Iterator::next();
	}

	bool hasNext() const {
		return Iterator::hasNext();
	}
};
//
//Iterator::Iterator(const vector<int>& nums) {}
//Iterator::~Iterator() {}


int main()
{
	vector<int> nums = {1, 2, 3};
	PeekingIterator it(nums);

	cout << it.next() << endl; // 1
	cout << it.peek() << endl; // 2
	cout << it.next() << endl; // 2
	cout << it.next() << endl; // 3
	cout << boolalpha << it.hasNext() << endl; // false

    return 0;
}

