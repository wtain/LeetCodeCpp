#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;


//class RandomizedCollection {
//	unordered_multiset<int> m_values;
//public:
//	/** Initialize your data structure here. */
//	RandomizedCollection() {
//
//	}
//
//	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
//	bool insert(int val) 
//	{
//		auto it = m_values.find(val);
//		bool result = (it == end(m_values));
//		m_values.emplace_hint(it, val);
//		return result;
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

class RandomizedCollection {
	unordered_map<int, unordered_set<int>> m_index;
	vector<int> m_values;
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val)
	{
		auto it = m_index.find(val);
		bool result = (it == end(m_index));
		m_index[val].emplace(m_values.size());
		m_values.push_back(val);
		return result;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val)
	{
		auto it = m_index.find(val);
		if (it == end(m_index))
			return false;
		int lastV = m_values.back();
		auto it2 = it->second.begin();
		int index = *it2;
		m_index[val].erase(index);
		if (m_index[val].empty())
			m_index.erase(it);

		if (index != m_values.size() - 1)
		{
			m_index[m_values.back()].erase(m_values.size()-1);
			m_index[m_values.back()].insert(index);
			m_values[index] = m_values.back();
		}

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

double TestProbability(const RandomizedCollection& rset, int v, int nSample = 1000)
{
	int c = 0;
	for (int i = 0; i < nSample; ++i)
	{
		RandomizedCollection rs = rset;
		if (rs.getRandom() == v)
			++c;
	}
	return static_cast<double>(c) / nSample;
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	RandomizedCollection rset;

	/*
	cout << boolalpha << rset.insert(1) << endl; // true
	cout << boolalpha << rset.insert(1) << endl; // false
	cout << boolalpha << rset.insert(2) << endl; // true

	cout << boolalpha << rset.getRandom() << endl; // 1 (67%) or 2 (33%)
	cout << TestProbability(rset, 1) << endl; // ~0.67

	cout << boolalpha << rset.remove(1) << endl; // true
	cout << boolalpha << rset.getRandom() << endl; // 1 or 2 (50/50)
	cout << TestProbability(rset, 1) << endl; // ~0.5
	*/

	cout << boolalpha << rset.insert(1) << endl;
	cout << boolalpha << rset.remove(2) << endl;
	cout << boolalpha << rset.insert(2) << endl;
	cout << boolalpha << rset.getRandom() << endl;
	cout << boolalpha << rset.remove(1) << endl;
	cout << boolalpha << rset.insert(2) << endl;
	cout << boolalpha << rset.getRandom() << endl;


    return 0;
}

