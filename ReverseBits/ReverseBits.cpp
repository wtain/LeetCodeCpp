
#include <iostream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/reverse-bits/
https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3388/
Reverse bits of a given 32 bits unsigned integer.



Example 1:

Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
Example 2:

Input: 11111111111111111111111111111101
Output: 10111111111111111111111111111111
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.


Note:

Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above the input represents the signed integer -3 and the output represents the signed integer -1073741825.


Follow up:

If this function is called many times, how would you optimize it?
*/

//Runtime: 4 ms, faster than 61.78% of C++ online submissions for Reverse Bits.
//Memory Usage : 6.2 MB, less than 21.37% of C++ online submissions for Reverse Bits.
class Solution {
	unordered_map<uint8_t, uint8_t> m_cache;

	vector<uint8_t> vals =
	{
		0, // 0000 -> 0000   0
		8, // 0001 -> 1000   1
		4, // 0010 -> 0100   2
		12, // 0011 -> 1100   3
		2, // 0100 -> 0010   4
		10, // 0101 -> 1010   5
		6, // 0110 -> 0110   6
		14, // 0111 -> 1110   7
		1, // 1000 -> 0001   8   
		9, // 1001 -> 1001   9
		5, // 1010 -> 0101  10   
		13, // 1011 -> 1101  11
		3, // 1100 -> 0011  12 
		11, // 1101 -> 1011  13
		7, // 1110 -> 0111  14 
		15  // 1111 -> 1111  15
	};

public:

	uint8_t reverseBits8(uint8_t b)
	{
		uint8_t b_in = b;
		auto it = m_cache.find(b);
		if (it != end(m_cache))
			return it->second;
		uint8_t b0 = b & 0xF;
		b >>= 4;
		uint8_t b1 = b & 0xF;

		uint8_t rv = (vals[b0] << 4) | vals[b1];
		m_cache.insert(it, make_pair(b_in, rv));
		return rv;
	}

	uint32_t reverseBits(uint32_t n) {
		uint32_t rv = 0;

		uint8_t b0 = n & 0xFF;
		n >>= 8;
		uint8_t b1 = n & 0xFF;
		n >>= 8;
		uint8_t b2 = n & 0xFF;
		n >>= 8;
		uint8_t b3 = n & 0xFF;

		rv = reverseBits8(b0);
		rv <<= 8;
		rv |= reverseBits8(b1);
		rv <<= 8;
		rv |= reverseBits8(b2);
		rv <<= 8;
		rv |= reverseBits8(b3);

		return rv;
	}
};

int main()
{
	cout << bitset<32>(Solution().reverseBits(0B00000010100101000001111010011100)).to_string() << endl; // 00111001011110000010100101000000 
	cout << bitset<32>(Solution().reverseBits(0B11111111111111111111111111111101)).to_string() << endl; // 10111111111111111111111111111111 

    return 0;
}

