// MaximumAbsoluteSumOfAnySubarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

using namespace std;

/*
Runtime
70 ms
Beats
66.81%
Memory
41.5 MB
Beats
8.79%
*/
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ps = 0, ns = 0;
        int max_abs_sum = 0;
        for (auto v : nums) {
            ps = max(v, ps + v);
            ns = min(v, ns + v);

            max_abs_sum = max(max_abs_sum, ps);
            max_abs_sum = max(max_abs_sum, -ns);
        }
        return max_abs_sum;
    }
};

int main()
{
    {
        vector<int> nums = { 1, -3, 2, 3, -4 };
        cout << Solution().maxAbsoluteSum(nums) << endl; // 5
    }
    {
        vector<int> nums = { 2,-5,1,-4,3,-2 };
        cout << Solution().maxAbsoluteSum(nums) << endl; // 8
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
