// FizzBuzz.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/fizz-buzz/

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
"1",
"2",
"Fizz",
"4",
"Buzz",
"Fizz",
"7",
"8",
"Fizz",
"Buzz",
"11",
"Fizz",
"13",
"14",
"FizzBuzz"
]

*/

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> result;
		result.reserve(n);
		for (int i = 1; i <= n; ++i) {
			bool is3 = i % 3 == 0;
			bool is5 = i % 5 == 0;
			if (is3 && is5)
				result.push_back("FizzBuzz");
			else if (is5)
				result.push_back("Buzz");
			else if (is3)
				result.push_back("Fizz");
			else
				result.push_back(to_string(i));
		}
		return result;
	}
};

int main()
{
	auto r = Solution().fizzBuzz(15);

	for each (auto s in r)
		cout << s << endl;

	cout << endl;

    return 0;
}

