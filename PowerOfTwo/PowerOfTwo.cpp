
#include <iostream>
#include <iomanip>

using namespace std;

/*
https://leetcode.com/problems/power-of-two/
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/
*/

//Runtime: 4 ms, faster than 37.98% of C++ online submissions for Power of Two.
//Memory Usage : 5.9 MB, less than 61.87% of C++ online submissions for Power of Two.
//class Solution {
//public:
//	bool isPowerOfTwo(int n) {
//		if (!n)
//			return false;
//		if (1 == n)
//			return true;
//
//		while (n > 1)
//		{
//			if (n & 1)
//				return false;
//			n /= 2;
//		}
//		return 1 == n;
//	}
//};

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of Two.
//Memory Usage : 5.9 MB, less than 77.19% of C++ online submissions for Power of Two.
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;
		return (1 << 31) % n == 0;
	}
};

int main()
{
	cout << boolalpha << Solution().isPowerOfTwo(1) << endl; // true
	cout << boolalpha << Solution().isPowerOfTwo(16) << endl; // true
	cout << boolalpha << Solution().isPowerOfTwo(218) << endl; // false
	cout << boolalpha << Solution().isPowerOfTwo(0) << endl; // false
	cout << boolalpha << Solution().isPowerOfTwo(-1) << endl; // false
	cout << boolalpha << Solution().isPowerOfTwo(1 << 31) << endl; // false
	cout << boolalpha << Solution().isPowerOfTwo(1 << 30) << endl; // true
	cout << boolalpha << Solution().isPowerOfTwo(-16) << endl; // false

    return 0;
}

