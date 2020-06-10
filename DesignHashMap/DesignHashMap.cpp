
#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
https://leetcode.com/problems/design-hashmap/
Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

Example:

MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);
hashMap.put(2, 2);
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found)

Note:

All keys and values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashMap library.
*/

class MyHashMap {

	vector<list<pair<int, int>>> hashtable;

public:
	/** Initialize your data structure here. */
	MyHashMap() {
		hashtable.resize(1019);
	}

	int hash(int key) { return key % hashtable.size(); }

	list<pair<int, int>>& bucket(int key) { return hashtable[hash(key)]; }

	/** value will always be non-negative. */
	void put(int key, int value) {
		auto& b = bucket(key);
		for (auto& p : b) {
			if (p.first == key) {
				p.second = value;
				return;
			}
		}
		b.emplace_back(key, value);
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		auto& b = bucket(key);
		for (auto& p : b) {
			if (p.first == key) {
				return p.second;
			}
		}
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		auto& b = bucket(key);
		for (auto pit = begin(b); pit != end(b); ++pit) {
			if (pit->first == key) {
				b.erase(pit);
				return;
			}
		}
	}
};

/**
* Your MyHashMap object will be instantiated and called as such:
* MyHashMap* obj = new MyHashMap();
* obj->put(key,value);
* int param_2 = obj->get(key);
* obj->remove(key);
*/

int main()
{
	MyHashMap hashMap;
	hashMap.put(1, 1);
	hashMap.put(2, 2);
	cout << hashMap.get(1) << endl;            // returns 1
	cout << hashMap.get(3) << endl;            // returns -1 (not found)
	hashMap.put(2, 1);          // update the existing value
	cout << hashMap.get(2) << endl;            // returns 1
	hashMap.remove(2);          // remove the mapping for 2
	cout << hashMap.get(2) << endl;            // returns -1 (not found)

    return 0;
}

