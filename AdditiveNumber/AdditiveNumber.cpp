
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.



Example 1:

Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true
Explanation: The additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199


Constraints:

num consists only of digits '0'-'9'.
1 <= num.length <= 35
Follow up:
How would you handle overflow for very large input integers?
*/

//class Solution {
//public:
//
//	bool isAdditiveNumberImpl(const string& num, vector<int>& numbers, size_t i) {
//		int v12 = -1;
//		if (numbers.size() >= 3)
//			v12 = numbers[numbers.size() - 2] + numbers[numbers.size() - 1];
//
//		int v = 0;
//		for (size_t j = i+1; j < num.length(); ++j) {
//			v *= 10;
//			v += num[j] - '0';
//			if (v12 != -1) {
//				if (v > v12)
//					break;
//				if (v < v12)
//					continue;
//				numbers.push_back(v);
//				if (isAdditiveNumberImpl(num, numbers, j + 1))
//					return true;
//				numbers.pop_back();
//			}
//			
//		}
//		return false;
//	}
//
//	bool isAdditiveNumber(string num) {
//		vector<int> numbers;
//		return isAdditiveNumberImpl(num, numbers, 0);
//	}
//};

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Additive Number.
//Memory Usage : 6.1 MB, less than 100.00% of C++ online submissions for Additive Number.
class Solution {
public:

	typedef unsigned long long Integer;

	bool isAdditiveNumberImpl(const string& num, const size_t i30, const size_t n, const Integer v1, const Integer v2) {
		Integer v12 = v1 + v2;

		Integer v3 = 0;
		for (size_t i3 = i30; i3 < n; ++i3) {
			if (!v3 && i3 > i30)
				return false;
			v3 *= 10;
			v3 += num[i3] - '0';
			if (v3 < v12)
				continue;
			if (v3 > v12)
				break;
			if (i3 == n - 1)
				return true;
			return isAdditiveNumberImpl(num, i3 + 1, n, v2, v3);
		}
		return false;
	}

	bool isAdditiveNumber(string num) {
		const size_t n = num.length();
		const size_t n3 = n / 2;
		Integer v1 = 0;
		for (size_t i1 = 0; i1 < n3; ++i1) {
			v1 *= 10;
			v1 += num[i1] - '0';
			Integer v2 = 0;
			const size_t m2 = i1 + 1 + n3;
			for (size_t i2 = i1 + 1; i2 < m2; ++i2) {
				v2 *= 10;
				v2 += num[i2] - '0';
				if (num[i1 + 1] == '0' && i2 > i1+1)
					break;
				if (isAdditiveNumberImpl(num, i2 + 1, n, v1, v2))
					return true;
			}
			if (!v1)
				return false;
		}
		return false;
	}
};

int main()
{
	cout << boolalpha << Solution().isAdditiveNumber("99999999999999999999999999999999999") << endl; // false
	cout << boolalpha << Solution().isAdditiveNumber("11235813213455890144") << endl; // false

	cout << boolalpha << Solution().isAdditiveNumber("1023") << endl; // false

	cout << boolalpha << Solution().isAdditiveNumber("198019823962") << endl; // true
	cout << boolalpha << Solution().isAdditiveNumber("199111992") << endl; // true

	cout << boolalpha << Solution().isAdditiveNumber("000") << endl; // true

	cout << boolalpha << Solution().isAdditiveNumber("101") << endl; // true

	cout << boolalpha << Solution().isAdditiveNumber("1203") << endl; // false

	cout << boolalpha << Solution().isAdditiveNumber("112358") << endl; // true
	cout << boolalpha << Solution().isAdditiveNumber("199100199") << endl; // true

    return 0;
}

