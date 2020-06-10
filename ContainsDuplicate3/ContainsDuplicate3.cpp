
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <iomanip>

using namespace std;

//////////////////////////////////////////

class Solution {
public:

	class Buffer
	{
		int m_capacity;
		set<long long> m_values;
		queue<set<long long>::iterator> m_index;
	public:
		explicit Buffer(int capacity)
			: m_capacity(capacity) {}

		void Put(int value) // log(K)
		{
			auto p = m_values.insert(value); // log(K)
			m_index.emplace(p.first); // C
			if (m_values.size() <= m_capacity)
				return;
			m_values.erase(m_index.front()); // C
			m_index.pop(); // C
		}

		//static int diff(int v1, int v2)
		//{
		//	if (v1 > v2)
		//		return v1 - v2;
		//	return v2 - v1;
		//}

		static bool DiffLess(int v1, int v2, int t)
		{
			if (v1 > v2)
				return v2 + t >= v1;
			return v1 + t >= v2;
		}

		bool Fits(long long v, long long t) const
		{
			long long vmt = v - t;
			auto itMin = m_values.lower_bound(vmt); // log(K)
			//auto itMax = m_values.upper_bound(v); // log(K)

			//if (itMin != m_values.end())
			//	--itMin;

			//if (itMin != m_values.end() &&
			//	diff(v, *itMin) <= t)
			//	return true;

			//if (itMax != m_values.end() &&
			//	diff(*itMax, v) <= t)
			//	return true;

			return itMin != m_values.end() && DiffLess(*itMin, v, t);

			//return false;
		}

		bool Empty() const
		{
			return m_values.empty();
		}
	};


	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		/*
		const int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
		const int ai = nums[i];
		for (int j = i+1; j <= i+k && j < n; ++j)
		{
		const long diff = abs(static_cast<long>(ai) - static_cast<long>(nums[j]));
		if (diff <= t)
		return true;
		}
		}
		return false;
		*/
		const int n = nums.size();
		// init buffer with first elements
		Buffer buffer(k);
		//for (int i = 0; i < k && i < n; ++i) // K*log(K)
		//	buffer.Put(nums[i]); // log(K)
		//for (int i = k; i < n; ++i) // (N-K)*log(K)
		for (int i = 0; i < n; ++i) // (N-K)*log(K)
		{
			const int ai = nums[i]; // C
			if (!buffer.Empty())
			{
				if (buffer.Fits(ai, t)) // log(K)
					return true;
			}
			buffer.Put(ai); // log(K)
		}
		return false;
	} // K*log(K) + (N-K)*log(K)=N*log(K)
};


//////////////////////////////////////////

int main()
{
	/*
	cout << boolalpha << Solution().containsNearbyAlmostDuplicate(vector<int>({ 1, 0, 1, 1 }), 1, 2) << endl; // true
	cout << boolalpha << Solution().containsNearbyAlmostDuplicate(vector<int>({ 1, 5, 9, 1, 5, 9 }), 2, 3) << endl; // false
	cout << boolalpha << Solution().containsNearbyAlmostDuplicate(vector<int>({ 2, 2 }), 3, 0) << endl; // true
	cout << boolalpha << Solution().containsNearbyAlmostDuplicate(vector<int>({ 7, 1, 3 }), 2, 3) << endl; // true
	cout << boolalpha << Solution().containsNearbyAlmostDuplicate(vector<int>({ 1, 2, 3, 1 }), 3, 0) << endl; // true
	
	cout << boolalpha << Solution().containsNearbyAlmostDuplicate(vector<int>({ 2147483647,-2147483647 }), 1, 2147483647) << endl; // false
	*/
	int v1 = -2147483648;
	cout << boolalpha << Solution().containsNearbyAlmostDuplicate(vector<int>({ v1,-2147483647 }), 3, 3) << endl; // true

    return 0;
}

