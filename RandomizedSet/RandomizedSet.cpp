
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;

//class RandomizedSet {
//	unordered_set<int> m_values;
//public:
//	/** Initialize your data structure here. */
//	RandomizedSet() {
//
//	}
//
//	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
//	bool insert(int val) 
//	{
//		auto it = m_values.find(val);
//		if (it != end(m_values))
//			return false;
//		m_values.emplace_hint(it, val);
//		return true;
//	}
//
//	/** Removes a value from the set. Returns true if the set contained the specified element. */
//	bool remove(int val) 
//	{
//		auto it = m_values.find(val);
//		if (it == end(m_values))
//			return false;
//		m_values.erase(it);
//		return true;
//	}
//
//	/** Get a random element from the set. */
//	int getRandom() 
//	{
//		int i = rand() % m_values.size();
//		for (int b = 0; b < m_values.bucket_count(); ++b)
//		{
//			int sz = m_values.bucket_size(b);
//			if (i >= sz)
//				i -= sz;
//			else
//			{
//				auto it = m_values.begin(b);
//				advance(it, i);
//				return *it;
//			}
//		}
//		return 0;
//	}
//};

class RandomizedSet {
	unordered_map<int, int> m_index;
	vector<int> m_values;
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val)
	{
		auto it = m_index.find(val);
		if (it != end(m_index))
			return false;
		m_index.emplace_hint(it, val, m_values.size());
		m_values.push_back(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val)
	{
		auto it = m_index.find(val);
		if (it == end(m_index))
			return false;
		int lastV = m_values.back();
		m_index[lastV] = it->second;
		swap(m_values[m_values.size()-1], m_values[it->second]);
		m_index.erase(it);
		m_values.pop_back();
		return true;
	}

	/** Get a random element from the set. */
	int getRandom()
	{
		int i = rand() % m_values.size();
		return m_values[i];
	}
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/

double TestProbability(const RandomizedSet& rset, int v, int nSample = 1000)
{
	int c = 0;
	for (int i = 0; i < nSample; ++i)
	{
		RandomizedSet rs = rset;
		if (rs.getRandom() == v)
			++c;
	}
	return static_cast<double>(c) / nSample;
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	RandomizedSet rset;
	cout << boolalpha << rset.insert(1) << endl; // true
	cout << boolalpha << rset.insert(2) << endl; // true
	cout << boolalpha << rset.insert(2) << endl; // false

	cout << boolalpha << rset.getRandom() << endl; // 1 or 2
	cout << TestProbability(rset, 1) << endl; // ~0.5

	cout << boolalpha << rset.remove(1) << endl; // true
	cout << boolalpha << rset.getRandom() << endl; // 2

    return 0;
}

