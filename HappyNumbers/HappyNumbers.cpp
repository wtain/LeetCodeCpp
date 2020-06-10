
#include <iostream>
#include <iomanip>
#include <unordered_set>

using namespace std;

/*
https://leetcode.com/problems/happy-number/

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the 
number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.
*/
class Solution 
{
public:
	bool isHappy(int n) 
	{
		unordered_set<int> seen;
		while (n != 1)
		{
			auto it = seen.find(n);
			if (it != seen.end())
				return false;
			seen.insert(it, n);
			int n1 = 0;
			while (n)
			{
				int d = n % 10;
				n /= 10;
				n1 += d * d;
			}
			n = n1;
			//cout << n << " ";
		}
		return true;
	}
};

int main()
{
	for (int i = 1; i <= 20; ++i)
	{
		cout << i << ": " << boolalpha << Solution().isHappy(i) << endl;
	}
    return 0;
}

