
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/divisor-game/

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.



Example 1:

Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:

Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.


Note:

1 <= N <= 1000
*/

//Runtime: 8 ms, faster than 11.46% of C++ online submissions for Divisor Game.
//Memory Usage : 6.2 MB, less than 17.81% of C++ online submissions for Divisor Game.
//class Solution {
//public:
//	bool divisorGame(int N) {
//		if (N <= 1)
//			return false;
//		vector<bool> f(N + 1);
//		f[2] = true;
//		for (int i = 3; i <= N; ++i) {
//			bool result = false;
//			for (int j = 1; j < i; ++j) {
//				if (i % j)
//					continue;
//				if (!f[i-j])
//					result = true;
//			}
//			f[i] = result;
//		}
//		return f[N];
//	}
//};

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divisor Game.
//Memory Usage : 6.2 MB, less than 21.24% of C++ online submissions for Divisor Game.
class Solution {
public:
	bool divisorGame(int N) {
		return N % 2 == 0;
	}
};

int main()
{
	cout << boolalpha << Solution().divisorGame(111) << endl; // false

	cout << boolalpha << Solution().divisorGame(7) << endl; // false
	cout << boolalpha << Solution().divisorGame(11) << endl; // false
	cout << boolalpha << Solution().divisorGame(13) << endl; // false
	cout << boolalpha << Solution().divisorGame(17) << endl; // false
	cout << boolalpha << Solution().divisorGame(19) << endl; // false
	cout << boolalpha << Solution().divisorGame(23) << endl; // false
	cout << boolalpha << Solution().divisorGame(1) << endl; // false
	cout << boolalpha << Solution().divisorGame(2) << endl; // true
	cout << boolalpha << Solution().divisorGame(3) << endl; // false
	cout << boolalpha << Solution().divisorGame(10) << endl; // true
	cout << boolalpha << Solution().divisorGame(100) << endl; // true
	cout << boolalpha << Solution().divisorGame(1000) << endl; // true

    return 0;
}

