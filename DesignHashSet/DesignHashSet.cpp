
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <set>

using namespace std;

/*
https://leetcode.com/problems/design-hashset/
Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet.
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);
hashSet.add(2);
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);
hashSet.contains(2);    // returns true
hashSet.remove(2);
hashSet.contains(2);    // returns false (already removed)

Note:

All values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashSet library.
Accepted
*/

//Runtime: 180 ms, faster than 32.86% of C++ online submissions for Design HashSet.
//Memory Usage : 42.1 MB, less than 38.89% of C++ online submissions for Design HashSet.
//class MyHashSet {
//
//	typedef list<int> TBucket;
//
//	vector<TBucket> hashtable;
//public:
//	/** Initialize your data structure here. */
//	MyHashSet() {
//		hashtable.resize(1000);
//	}
//
//	int hash(int key) {
//		return key % hashtable.size();
//	}
//
//	void add(int key) {
//		hashtable[hash(key)].push_back(key);
//	}
//
//	TBucket& bucket(int key) {
//		return hashtable[hash(key)];
//	}
//
//	void remove(int key) {
//		auto& b = bucket(key);
//		
//		b.remove(key);
//	}
//
//	/** Returns true if this set contains the specified element */
//	bool contains(int key) {
//		auto& b = bucket(key);
//		return find(begin(b), end(b), key) != end(b);
//	}
//};

//Runtime: 184 ms, faster than 30.16% of C++ online submissions for Design HashSet.
//Memory Usage : 43.2 MB, less than 38.89% of C++ online submissions for Design HashSet.
//class MyHashSet {
//
//	typedef set<int> TBucket;
//
//	vector<TBucket> hashtable;
//public:
//	/** Initialize your data structure here. */
//	MyHashSet() {
//		hashtable.resize(1000);
//	}
//
//	int hash(int key) {
//		return key % hashtable.size();
//	}
//
//	void add(int key) {
//		//hashtable[hash(key)].push_back(key);
//		hashtable[hash(key)].insert(key);
//	}
//
//	TBucket& bucket(int key) {
//		return hashtable[hash(key)];
//	}
//
//	void remove(int key) {
//		auto& b = bucket(key);
//
//		//b.remove(key);
//		b.erase(key);
//	}
//
//	/** Returns true if this set contains the specified element */
//	bool contains(int key) {
//		auto& b = bucket(key);
//		//return find(begin(b), end(b), key) != end(b);
//		return b.find(key) != end(b);
//	}
//};

//Runtime: 176 ms, faster than 36.39% of C++ online submissions for Design HashSet.
//Memory Usage : 42.1 MB, less than 38.89% of C++ online submissions for Design HashSet.
//class MyHashSet {
//
//	typedef list<int> TBucket;
//
//	vector<TBucket> hashtable;
//public:
//	/** Initialize your data structure here. */
//	MyHashSet() {
//		hashtable.resize(1000);
//	}
//
//	void add(int key) {
//		hashtable[key % hashtable.size()].push_back(key);
//	}
//
//	void remove(int key) {
//		auto& b = hashtable[key % hashtable.size()];
//		
//		b.remove(key);
//	}
//
//	/** Returns true if this set contains the specified element */
//	bool contains(int key) {
//		auto& b = hashtable[key % hashtable.size()];
//		return find(begin(b), end(b), key) != end(b);
//	}
//};

//Runtime: 232 ms, faster than 16.68% of C++ online submissions for Design HashSet.
//Memory Usage : 115.3 MB, less than 33.33% of C++ online submissions for Design HashSet.
//class MyHashSet {
//
//	typedef list<int> TBucket;
//
//	vector<TBucket> hashtable;
//public:
//	/** Initialize your data structure here. */
//	MyHashSet() {
//		hashtable.resize(100000);
//	}
//
//	void add(int key) {
//		hashtable[key % hashtable.size()].push_back(key);
//	}
//
//	void remove(int key) {
//		auto& b = hashtable[key % hashtable.size()];
//
//		b.remove(key);
//	}
//
//	/** Returns true if this set contains the specified element */
//	bool contains(int key) {
//		auto& b = hashtable[key % hashtable.size()];
//		return find(begin(b), end(b), key) != end(b);
//	}
//};

//Runtime: 188 ms, faster than 27.89% of C++ online submissions for Design HashSet.
//Memory Usage : 48.8 MB, less than 33.33% of C++ online submissions for Design HashSet.
class MyHashSet {

	typedef list<int> TBucket;

	vector<TBucket> hashtable;
public:
	/** Initialize your data structure here. */
	MyHashSet() {
		hashtable.resize(10000);
	}

	void add(int key) {
		hashtable[key % hashtable.size()].push_back(key);
	}

	void remove(int key) {
		auto& b = hashtable[key % hashtable.size()];

		b.remove(key);
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		auto& b = hashtable[key % hashtable.size()];
		return find(begin(b), end(b), key) != end(b);
	}
};

/**
* Your MyHashSet object will be instantiated and called as such:
* MyHashSet* obj = new MyHashSet();
* obj->add(key);
* obj->remove(key);
* bool param_3 = obj->contains(key);
*/

int main()
{
	MyHashSet hashSet;
	hashSet.add(1);
	hashSet.add(2);
	cout << boolalpha << hashSet.contains(1) << endl;    // returns true
	cout << boolalpha << hashSet.contains(3) << endl;    // returns false (not found)
	hashSet.add(2);
	cout << boolalpha << hashSet.contains(2) << endl;    // returns true
	hashSet.remove(2);
	cout << boolalpha << hashSet.contains(2) << endl;    // returns false (already removed)
    return 0;
}

