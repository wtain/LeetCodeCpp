// ClosestDessertCost.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
Runtime
3 ms
Beats
100%
Memory
50.3 MB
Beats
14.50%
*/
class Solution {
public:

    void impl(int i, int s, int& maxi, int& diff1, vector<vector<int>>& dp, const int target, const vector<int>& toppingCosts) {
        if (abs(target - s) < diff1) {
            maxi = s;
            diff1 = abs(target - s);
        }
        else if (abs(target - s) == diff1) {
            maxi = min(maxi, s);
        }

        if (s > target) {
            return;
        }

        if (i >= toppingCosts.size()) {
            return;
        }

        if (dp[i][s] != -1) {
            return;
        }

        impl(i+1, s, maxi, diff1, dp, target, toppingCosts);
        impl(i+1, s +   toppingCosts[i], maxi, diff1, dp, target, toppingCosts);
        impl(i+1, s + 2*toppingCosts[i], maxi, diff1, dp, target, toppingCosts);

        dp[i][s] = 1;
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int result = 0, diff = numeric_limits<int>::max();

        for (auto cost : baseCosts) {
            vector<vector<int>> dp(toppingCosts.size(), vector<int>(target + 1, -1));
            int maxi = 0, diff1 = numeric_limits<int>::max();
            impl(0, cost, maxi, diff1, dp, target, toppingCosts);

            if (abs(target - maxi) < diff) {
                result = maxi;
                diff = abs(target - maxi);
            }
            else if (abs(target - maxi) == diff) {
                result = min(result, maxi);
            }
        }

        return result;
    }
};

int main()
{
    {
        vector<int> baseCosts = { 1, 7 }, toppingCosts = {3, 4};
        int target = 10;
        cout << Solution().closestCost(baseCosts, toppingCosts, target) << endl; // 10
    }
    {
        vector<int> baseCosts = { 2, 3 }, toppingCosts = { 4, 5, 100 };
        int target = 18;
        cout << Solution().closestCost(baseCosts, toppingCosts, target) << endl; // 17
    }
    {
        vector<int> baseCosts = { 3, 10 }, toppingCosts = { 2, 5 };
        int target = 9;
        cout << Solution().closestCost(baseCosts, toppingCosts, target) << endl; // 8
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
