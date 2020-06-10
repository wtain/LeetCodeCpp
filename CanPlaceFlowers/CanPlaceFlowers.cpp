
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/can-place-flowers/
Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.
*/

//class Solution {
//public:
//	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//		if (!n)
//			return true;
//		for (int i = 0; i < flowerbed.size(); ++i) {
//			if (flowerbed[i] == 1)
//				continue;
//			bool hasLeft = i > 0 && flowerbed[i - 1] == 1;
//			bool hasRight = i < flowerbed.size()-1 && flowerbed[i + 1] == 1;
//			if (!hasLeft && !hasRight) {
//				++i;
//				if (!--n)
//					return true;
//			}
//		}
//		return n == 0;
//	}
//};

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int cnt = 0;
		for (int i = 0; i < flowerbed.size(); ++i) {
			if (0 == flowerbed[i] && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
				flowerbed[i] = 1;
				++i;
				++cnt;
			}
			if (cnt >= n)
				return true;
		}
		return false;
	}
};

int main()
{
	cout << boolalpha << Solution().canPlaceFlowers(vector<int>({ 1,0,0,0,1 }), 1) << endl; // true
	cout << boolalpha << Solution().canPlaceFlowers(vector<int>({ 1,0,0,0,1 }), 2) << endl; // false
	cout << boolalpha << Solution().canPlaceFlowers(vector<int>({ }), 1) << endl; // false
	cout << boolalpha << Solution().canPlaceFlowers(vector<int>({ 0 }), 1) << endl; // true
	cout << boolalpha << Solution().canPlaceFlowers(vector<int>({ 0,0,0,0,0,1,0,0 }), 0) << endl; // true
	cout << boolalpha << Solution().canPlaceFlowers(vector<int>({  }), 0) << endl; // ???
    return 0;
}

