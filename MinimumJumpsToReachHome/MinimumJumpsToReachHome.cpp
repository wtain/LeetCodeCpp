
// MinimumJumpsToReachHome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>
#include <limits>
#include <stack>

using namespace std;


/*
Runtime
83 ms
Beats
47.90%
Memory
28.3 MB
Beats
48.88%
*/
class Solution {
public:

    struct hashFunction
    {
        size_t operator()(const pair<int,
            int>& x) const
        {
            return (6001 * x.first) ^ x.second;
        }
    };

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        vector<pair<int, int>> level;
        unordered_set<int> restrictions(begin(forbidden), end(forbidden));
        unordered_set<pair<int, int>, hashFunction> visited;
        level.push_back(make_pair(0, 0));
        visited.insert(make_pair(0, 0));
        const auto M = 6001;
        int jumps = 0;
        while (!level.empty()) {
            decltype(level) next_level;

            for (auto [current, negative_jumps] : level) {
                if (current == x) {
                    return jumps;
                }

                auto next_negative = make_pair(current - b, negative_jumps + 1);
                auto next = make_pair(current + a, 0);

                if (!negative_jumps && current - b >= 0 && 
                    !restrictions.count(current - b) && 
                    !visited.count(next_negative)) {
                    visited.insert(next_negative);
                    next_level.push_back(next_negative);
                }

                if (!restrictions.count(current + a) &&
                    current + a <= M &&
                    !visited.count(next)) {
                    visited.insert(next);
                    next_level.push_back(next);
                }
            }

            swap(level, next_level);
            jumps ++;
        }
        return -1;
    }
};

int main()
{
    {
        vector<int> forbidden = { 14,4,18,1,15 };
        cout << Solution().minimumJumps(forbidden, 3, 15, 9) << endl; // 3
    }
    {
        vector<int> forbidden = { 8,3,16,6,12,20 };
        cout << Solution().minimumJumps(forbidden, 15, 13, 1) << endl; // -1
    }
    {
        vector<int> forbidden = { 1,6,2,14,5,17,4 };
        cout << Solution().minimumJumps(forbidden, 16, 9, 7) << endl; // 2
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
