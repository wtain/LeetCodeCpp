
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
https://leetcode.com/problems/two-city-scheduling/

There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.



Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation:
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.


Note:

1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000

*/

//Runtime: 8 ms
//Memory Usage : 8 MB
//6575 %
class Solution {
public:

	struct Compare {

		bool operator() (const vector<int>& l, const vector<int>& r) const {
			return (l[0] - l[1]) < (r[0] - r[1]);
		}

	};

	int twoCitySchedCost(vector<vector<int>>& costs) {
		const size_t nn = costs.size();
		const size_t n = nn >> 1;
		sort(begin(costs), end(costs), Compare());
		return accumulate(begin(costs), end(costs), 0, [](auto v, auto ci) { return v + ci[1];  }) +
			   accumulate(begin(costs), begin(costs) + n, 0, [](auto v, auto ci) { return v + ci[0] - ci[1];  });
	}
};

int main()
{
	cout << Solution().twoCitySchedCost(vector<vector<int>>{ {10, 20}, { 30, 200 }, { 400, 50 }, { 30, 20 } }) << endl; // 110
	cout << Solution().twoCitySchedCost(vector<vector<int>>{ {20, 10}, { 200, 30 }, { 50, 400 }, { 20, 30 } }) << endl; // 110

    return 0;
}

