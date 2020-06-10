
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
https://leetcode.com/problems/defanging-an-ip-address/
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".



Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"


Constraints:

The given address is a valid IPv4 address.
*/

class Solution {
public:
	string defangIPaddr(string address) {
		ostringstream stream;
		size_t pos = 0;
		while (pos < address.length()) {
			size_t pos1 = address.find('.', pos);
			if (pos1 != string::npos) {
				stream << address.substr(pos, pos1 - pos) << "[.]";
				pos = pos1 + 1;
			}
			else {
				stream << address.substr(pos, pos1);
				break;
			}
		}
		return stream.str();
	}
};

int main()
{
	cout << Solution().defangIPaddr("1.1.1.1") << endl; // "1[.]1[.]1[.]1"
	cout << Solution().defangIPaddr("255.100.50.0") << endl; // "255[.]100[.]50[.]0"
    return 0;
}

