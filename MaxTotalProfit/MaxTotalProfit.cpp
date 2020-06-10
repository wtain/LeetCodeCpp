
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm> 

using namespace std;

class Solution {
public:

	//pair<int, size_t> maxSpread(int start, const vector<int>& prices)
	//{
	//	size_t n = prices.size();
	//	vector<int> mins(n - start);
	//	vector<int> maxes(n - start);
	//	mins[0] = prices[start];
	//	maxes[n - 1 - start] = prices[n - 1];
	//	for (size_t i = start + 1; i < n; ++i)
	//		mins[i - start] = min(prices[i], mins[i - 1 - start]);
	//	for (int i = n - 2; i >= start; --i)
	//		maxes[i - start] = max(prices[i], maxes[i + 1 - start]);
	//	int maxSpread = 0;
	//	size_t pos = n;
	//	for (int i = n-1; i >= start; --i)
	//	{
	//		int spread = maxes[i - start] - mins[i - start];
	//		if (spread > maxSpread)
	//		{
	//			maxSpread = spread;
	//			pos = i;
	//		}
	//	}
	//	return make_pair(maxSpread, pos); // wrong
	//}

	//int maxProfit(vector<int>& prices) {
	//	if (prices.empty())
	//		return 0;
	//	int profit = 0;
	//	size_t pos = 0;
	//	size_t n = prices.size();
	//	while (pos < n)
	//	{
	//		auto p = maxSpread(pos, prices);
	//		profit += p.first;
	//		pos = p.second + 1;
	//	}
	//	return profit;
	//}

	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int profit = 0;
		size_t n = prices.size();
		for (size_t i = 1; i < n; ++i)
			profit += max(prices[i] - prices[i - 1], 0);
		return profit;
	}
};

int main()
{
	std::vector<int> prices = { 1, 2, 1, 3, 4, 1, 5, 2, 4, 5, 6, 3 };
	/*	                        0  1  0  2  1  0  4  0  2  1  1  0
	                            0  1  0  0  3  0  4  0  0  0  4  0
	*/

	cout << Solution().maxProfit(prices) << endl;

    return 0;
}

