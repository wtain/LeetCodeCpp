
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:

	void splitArr(const vector<int>& v, vector<int>& l, vector<int>& r, int mask)
	{
		for (const auto vi : v)
		{
			if (vi & mask)
				r.push_back(vi);
			else
				l.push_back(vi);
		}
	}

	int findMaximumXORImpl(const vector<int>& l, const vector<int>& r, int bit)
	{
		if (l.size() == 1 && r.size() == 1) return l[0] ^ r[0];
		if (l.size() == 1 && r.size() == 0) return 0;
		if (l.size() == 0 && r.size() == 1) return 0;
		if (l.size() == 0 && r.size() == 0) return 0;

		int mask = (1 << bit);

		if (!l.empty() && !r.empty())
		{
			vector<int> ll, lr, rl, rr;

			splitArr(l, ll, lr, mask);
			splitArr(r, rl, rr, mask);

			if (lr.empty() && rr.empty() ||
				ll.empty() && rl.empty())
				return findMaximumXORImpl(l, r, bit - 1);

			return max(findMaximumXORImpl(lr, rl, bit - 1),
				findMaximumXORImpl(ll, rr, bit - 1));
		}

		const vector<int>& v = l.empty() ? r : l;
		vector<int> vl, vr;
		splitArr(v, vl, vr, mask);

		return findMaximumXORImpl(vl, vr, bit - 1);
	}

	int findMaximumXOR(vector<int>& nums) 
	{
		vector<int> l, r;
		unordered_set<int> seen;
		for (const auto n : nums)
		{
			auto it = seen.find(n);
			if (it != end(seen))
				continue;
			seen.insert(it, n);
			l.push_back(n);
		}
		return findMaximumXORImpl(l, r, 31);
	}
};

int main()
{
	vector<int> arr = { 3, 10, 5, 25, 2, 8 };
	cout << Solution().findMaximumXOR(arr) << endl; // 28

    return 0;
}

