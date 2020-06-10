
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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
	cout << Solution().reverseBits(1) << endl;

    return 0;
}

