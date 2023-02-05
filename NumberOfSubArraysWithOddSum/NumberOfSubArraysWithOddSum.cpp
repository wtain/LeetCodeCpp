// NumberOfSubArraysWithOddSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


/*
Runtime
160 ms
Beats
77.54%
Memory
108.1 MB
Beats
73.35%
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        constexpr auto MOD = 1000000007;
        vector<unsigned> dp(2);
        dp[arr[0] % 2] += 1;
        auto n = arr.size();
        int result = dp[1];
        for (int i = 1; i < n; ++i) {
            if (arr[i] % 2 == 0) {
                dp[0] += 1;
            }
            else {
                swap(dp[0], dp[1]);
                dp[1] ++;
            }
            dp[0] %= MOD;
            dp[1] %= MOD;
            result += dp[1];
            result %= MOD;
        }
        return result % MOD;
    }
};

int main()
{
    {
        vector<int> arr = { 1,3,5 };
        cout << Solution().numOfSubarrays(arr) << endl; // 4
    }
    {
        vector<int> arr = { 2,4,6 };
        cout << Solution().numOfSubarrays(arr) << endl; // 0
    } 
    {
        vector<int> arr = { 1,2,3,4,5,6,7 };
        cout << Solution().numOfSubarrays(arr) << endl; // 16
    }
}

// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
