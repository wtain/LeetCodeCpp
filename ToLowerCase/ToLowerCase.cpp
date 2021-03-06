
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*
https://leetcode.com/problems/to-lower-case/

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"

*/

class Solution {
public:
	string toLowerCase(string str) {
		ostringstream stream;
		for (int i = 0; i < str.length(); ++i)
			stream << static_cast<char>(tolower(str[i]));
		return stream.str();
	}
};

int main()
{
	cout << Solution().toLowerCase("Hello") << endl;
	cout << Solution().toLowerCase("here") << endl;
	cout << Solution().toLowerCase("LOVELY") << endl;

    return 0;
}

