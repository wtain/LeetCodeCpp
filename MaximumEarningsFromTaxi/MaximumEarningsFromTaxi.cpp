// MaximumEarningsFromTaxi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

/*
Runtime
571 ms
Beats
83.64%
Memory
100.3 MB
Beats
83.3%
*/
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        sort(begin(rides), end(rides), 
            [](const auto& left, const auto& right) {
                return left[0] < right[0];
            });

        long long mx = 0;
        priority_queue<tuple<long long, long long>> queue;
        for (const vector<int>& ride : rides) {
            int ride_start = ride[0];
            int ride_end = ride[1];
            int ride_tip = ride[2];
            int ride_profit = ride_end - ride_start + ride_tip;

            while (!queue.empty() && ride_start >= -get<0>(queue.top())) {
                auto prev_ride = queue.top();
                queue.pop();
                mx = max<long long>(mx, get<1>(prev_ride));
            }
            queue.push(make_tuple(-ride_end, ride_profit + mx));
        }

        while (!queue.empty()) {
            auto prev_ride = queue.top();
            queue.pop();
            mx = max<long long>(mx, get<1>(prev_ride));
        }

        return mx;
    }
};


int main()
{
    {
        vector<vector<int>> rides{ {2,3,6},{8,9,8},{5,9,7},{8,9,1},{2,9,2},{9,10,6},{7,10,10},{6,7,9},{4,9,7},{2,3,1} };
        cout << Solution().maxTaxiEarnings(10, rides) << endl; // 33
    }
    {
        vector<vector<int>> rides{ {2, 5, 4}, { 1, 5, 1 } };
        cout << Solution().maxTaxiEarnings(5, rides) << endl; // 7
    }

    {
        vector<vector<int>> rides{ {1, 6, 1},{3, 10, 2},{10, 12, 3},{11, 12, 2},{12, 15, 2},{13, 18, 1} };
        cout << Solution().maxTaxiEarnings(20, rides) << endl; // 20
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
