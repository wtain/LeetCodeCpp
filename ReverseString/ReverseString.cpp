
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3350/
https://leetcode.com/problems/reverse-string/

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.



Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]


OLD
class Solution {
public:
string reverseString(string s) {
string rv;
for (size_t i = 0; i < s.size(); ++i)
{
rv += s[s.size()-1-i];
}
return rv;
}
};

*/

//Runtime: 52 ms, faster than 67.70% of C++ online submissions for Reverse String.
//Memory Usage : 23.2 MB, less than 6.10% of C++ online submissions for Reverse String.
//class Solution {
//public:
//	void reverseString(vector<char>& s) {
//		const size_t n = s.size();
//		const size_t n2 = n >> 1;
//		for (size_t i = 0; i < n2; ++i)
//			swap(s[i], s[n - 1 - i]);
//	}
//};

//Runtime: 44 ms, faster than 92.88% of C++ online submissions for Reverse String.
//Memory Usage : 23.3 MB, less than 6.10% of C++ online submissions for Reverse String.
class Solution {
public:
	void reverseString(vector<char>& s) {
		if (s.empty())
			return;
		char* p1 = &s[0];
		char* p2 = &s[s.size()-1];
		while (p1 < p2)
			swap(*p1++, *p2--);
	}
};

void print(const vector<char>& v) {
	copy(begin(v), end(v), ostream_iterator<char>(cout, ""));
	cout << endl;
}


int main()
{
	{
		vector<char> v = { 'h','e','l','l','o' }; // ["o","l","l","e","h"]
		Solution().reverseString(v);
		print(v);
	}
	{
		vector<char> v = { 'H','a','n','n','a','h' }; // ["h","a","n","n","a","H"]
		Solution().reverseString(v);
		print(v);
	}

	{
		vector<char> v;
		Solution().reverseString(v);
		print(v);
	}

	{
		vector<char> v = { 'a' };
		Solution().reverseString(v);
		print(v);
	}

    return 0;
}

