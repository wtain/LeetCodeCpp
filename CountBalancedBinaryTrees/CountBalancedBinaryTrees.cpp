
#include <iostream>
#include <vector>

using namespace std;

// https://www.geeksforgeeks.org/count-balanced-binary-trees-height-h/

int countBalancedBinaryTreesOfHeightH(int h)
{
	if (h <= 1)
		return 1;
	vector<int> dp(h+1);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= h; ++i)
		dp[i] = dp[i - 1] * (2 * dp[i - 2] + dp[i - 1]);
	return dp[h];
}

int main()
{
	cout << countBalancedBinaryTreesOfHeightH(0) << endl; // 1;
	cout << countBalancedBinaryTreesOfHeightH(1) << endl; // 1;
	cout << countBalancedBinaryTreesOfHeightH(2) << endl; // 3;
	cout << countBalancedBinaryTreesOfHeightH(3) << endl; // 15;
	cout << countBalancedBinaryTreesOfHeightH(4) << endl; // 315;
    return 0;
}

