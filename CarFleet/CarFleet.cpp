
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/*
https://leetcode.com/problems/car-fleet/

N cars are going to the same destination along a one lane road.  The destination is target miles away.

Each car i has a constant speed speed[i] (in miles per hour), and initial position position[i] miles towards the target along the road.

A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.

The distance between these two cars is ignored - they are assumed to have the same position.

A car fleet is some non-empty set of cars driving at the same position and same speed.  Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.


How many car fleets will arrive at the destination?



Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 and 8 become a fleet, meeting each other at 12.
The car starting at 0 doesn't catch up to any other car, so it is a fleet by itself.
The cars starting at 5 and 3 become a fleet, meeting each other at 6.
Note that no other cars meet these fleets before the destination, so the answer is 3.

Note:

0 <= N <= 10 ^ 4
0 < target <= 10 ^ 6
0 < speed[i] <= 10 ^ 6
0 <= position[i] < target
All initial positions are different.

*/

namespace mine {
	//Runtime: 84 ms, faster than 75.98% of C++ online submissions for Car Fleet.
	//Memory Usage : 20 MB, less than 88.46% of C++ online submissions for Car Fleet.
	class Solution {
	public:

		struct compare {
			bool operator () (const pair<int, int>& c1, const pair<int, int>& c2) const {
				return c1.first > c2.first;
			}
		};

		int carFleet(int target, vector<int>& position, vector<int>& speed) {
			const auto n = position.size();
			if (!n)
				return 0;
			vector<pair<int, int>> cars(n);
			for (int i = 0; i < n; ++i)
				cars[i] = make_pair(position[i], speed[i]);

			sort(begin(cars), end(cars), compare());

			int cnt = 1;
			/*for (int i = 1; i < n; ++i) {
				if (cars[i].first == cars[i - 1].first)
					continue;
				if (cars[i].second < cars[i - 1].second) {
					++cnt;
					continue;
				}
				double t = static_cast<double>(cars[i].first - cars[i - 1].first) / static_cast<double>(cars[i - 1].second - cars[i].second);
				if (t < 0.0) {
					++cnt;
					continue;
				}
				double pos = cars[i].first + cars[i].second * t;
				if (pos > target) {
					++cnt;
					continue;
				}
			}*/

			for (int i = 1; i < n; ++i) {
				if (cars[i].first == cars[i - 1].first)
					continue;
				/*if (cars[i].second < cars[i - 1].second) {
					++cnt;
					continue;
				}*/

				bool found = false;
				for (int j = i - 1; j >= 0; --j) {
					double t = static_cast<double>(cars[i].first - cars[j].first) / static_cast<double>(cars[j].second - cars[i].second);
					if (t < 0.0)
						continue;
					double pos = cars[i].first + cars[i].second * t;
					if (pos > target)
						continue;
					found = true;
					break;
				}
				if (!found)
					++cnt;
			}

			return cnt;
		}
	};
}

//Runtime: 92 ms, faster than 62.60% of C++ online submissions for Car Fleet.
//Memory Usage : 20.4 MB, less than 88.46% of C++ online submissions for Car Fleet.
class Solution {
public:

	struct compare {
		bool operator () (const pair<int, double>& c1, const pair<int, double>& c2) const {
			return c1.first > c2.first;
		}
	};

	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		const auto n = position.size();
		if (!n)
			return 0;

		vector<pair<int, double>> cars(n);
		for (int i = 0; i < n; ++i)
			cars[i] = make_pair(position[i], static_cast<double>(target - position[i]) / speed[i]);

		sort(begin(cars), end(cars), compare());

		int cnt = 1;
		for (int i = 1; i < n; ++i) {
			if (cars[i].second > cars[i - 1].second)
				++cnt;
			else
				cars[i].second = cars[i - 1].second;
		}
		return cnt;
	}
};

int main()
{
	cout << Solution().carFleet(10, vector<int>{0, 4, 2}, vector<int>{2, 1, 3}) << endl; // 1
	cout << Solution().carFleet(10, vector<int>{6, 8}, vector<int>{3, 2}) << endl; // 2
	cout << Solution().carFleet(12, vector<int>{10, 8, 0, 5, 3}, vector<int>{2, 4, 1, 1, 3}) << endl; // 3

    return 0;
}

