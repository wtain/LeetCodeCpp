
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/distant-barcodes/
In a warehouse, there is a row of barcodes, where the i-th barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal.  You may return any answer, and it is guaranteed an answer exists.



Example 1:

Input: [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,2,1,2,1]


Note:

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000
*/

//Runtime: 288 ms, faster than 49.53% of C++ online submissions for Distant Barcodes.
//Memory Usage : 41.6 MB, less than 58.97% of C++ online submissions for Distant Barcodes.
class Solution {
public:

	struct compare {
		bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) const {
			return p1.second < p2.second;
		}
	};

	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		const auto n = barcodes.size();
		vector<int> result;
		result.reserve(n);
		unordered_map<int, int> counts;
		for (const auto c : barcodes)
			counts[c]++;

		priority_queue<pair<int, int>, vector<pair<int, int>>, compare> bars;
		for (const auto& p : counts)
			bars.emplace(p.first, p.second);

		while (!bars.empty()) {
			auto p1 = bars.top();
			bars.pop();
			if (result.empty() || result.back() != p1.first) {
				result.push_back(p1.first);
				p1.second--;
				if (p1.second)
					bars.emplace(p1);
			}
			else {
				auto p2 = bars.top();
				bars.pop();
				result.push_back(p2.first);
				p2.second--;
				if (p1.second)
					bars.emplace(p1);
				if (p2.second)
					bars.emplace(p2);
			}
		}

		return result;
	}
};

void print(const vector<int>& r) {
	copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().rearrangeBarcodes(vector<int>{1, 1, 1, 2, 2, 2})); // 2,1,2,1,2,1
	print(Solution().rearrangeBarcodes(vector<int>{1, 1, 1, 1, 2, 2, 3, 3})); // 1,3,1,3,2,1,2,1

    return 0;
}

