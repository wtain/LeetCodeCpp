
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/utf-8-validation/

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
This is how the UTF-8 encoding would work:

Char. number range  |        UTF-8 octet sequence
(hexadecimal)    |              (binary)
--------------------+---------------------------------------------
0000 0000-0000 007F | 0xxxxxxx
0000 0080-0000 07FF | 110xxxxx 10xxxxxx
0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.

*/

//Runtime: 32 ms, faster than 10.20% of C++ online submissions for UTF - 8 Validation.
//Memory Usage : 14.1 MB, less than 12.50% of C++ online submissions for UTF - 8 Validation.
//class Solution {
//	static constexpr int bit7 = 1 << 7;
//	static constexpr int bit6 = 1 << 6;
//	static constexpr int bit5 = 1 << 5;
//	static constexpr int bit4 = 1 << 4;
//	static constexpr int bit3 = 1 << 3;
//	static constexpr int mask76 = bit7 | bit6;
//	static constexpr int mask765 = mask76 | bit5;
//	static constexpr int mask7654 = mask765 | bit4;
//	static constexpr int mask76543 = mask7654 | bit3;
//
//public:
//
//	bool checkByte(const vector<int>& data, int &i, int n) {
//		if (++i >= n)
//			return false;
//		return (data[i] & mask76) == bit7;
//	}
//
//	bool validUtf8(vector<int>& data) {
//		
//		const int n = data.size();
//		for (int i = 0; i < n; ++i) {
//			if (!(data[i] & bit7))
//				continue; // 1-byte character => ok
//			if ((data[i] & mask765) == mask76) { // 2-byte, checking
//				if (!checkByte(data, i, n))
//					return false;
//			}
//			else if ((data[i] & mask7654) == mask765) { // 3-byte, checking
//				if (!checkByte(data, i, n) || !checkByte(data, i, n))
//					return false;
//			}
//			else if ((data[i] & mask76543) == mask7654) { // 4-byte, checking
//				if (!checkByte(data, i, n) || !checkByte(data, i, n) || !checkByte(data, i, n))
//					return false;
//			}
//			else
//				return false;
//		}
//		return true;
//	}
//};

//Runtime: 36 ms, faster than 8.91% of C++ online submissions for UTF - 8 Validation.
//Memory Usage : 14 MB, less than 12.50% of C++ online submissions for UTF - 8 Validation.
class Solution {
	static constexpr int bit7 = 1 << 7;
	static constexpr int bit6 = 1 << 6;
	static constexpr int bit5 = 1 << 5;
	static constexpr int bit4 = 1 << 4;
	static constexpr int bit3 = 1 << 3;
	static constexpr int mask76 = bit7 | bit6;
	static constexpr int mask765 = mask76 | bit5;
	static constexpr int mask7654 = mask765 | bit4;
	static constexpr int mask76543 = mask7654 | bit3;

public:

	bool validUtf8(vector<int>& data) {
		int nBytesToCheck = 0;
		const int n = data.size();
		for (int i = 0; i < n; ++i) {
			if (nBytesToCheck > 0) {
				if ((data[i] & mask76) != bit7)
					return false;
				--nBytesToCheck;
				continue;
			}
			if (!(data[i] & bit7))
				continue; // 1-byte character => ok
			if ((data[i] & mask765) == mask76) { // 2-byte, checking
				nBytesToCheck = 1;
			}
			else if ((data[i] & mask7654) == mask765) { // 3-byte, checking
				nBytesToCheck = 2;
			}
			else if ((data[i] & mask76543) == mask7654) { // 4-byte, checking
				nBytesToCheck = 3;
			}
			else
				return false;
		}
		return 0 == nBytesToCheck;
	}
};

int main()
{
	cout << boolalpha << Solution().validUtf8(vector<int>{197, 130, 1}) << endl; // true
	cout << boolalpha << Solution().validUtf8(vector<int>{235, 140, 4}) << endl; // false

    return 0;
}

