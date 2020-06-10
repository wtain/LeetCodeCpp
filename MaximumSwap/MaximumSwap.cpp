
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

// Brute Force
//class Solution {
//public:
//
//	vector<int> toDigits(int num)
//	{
//		vector<int> result;
//		while (num)
//		{
//			result.push_back(num % 10);
//			num /= 10;
//		}
//		return result;
//	}
//
//	int fromDigits(const vector<int>& d)
//	{
//		int result = 0;
//		for (int i = 0; i < d.size(); ++i)
//			result = result * 10 + d[i];
//		return result;
//	}
//
//	bool isAscending(const vector<int>& d)
//	{
//		int n = d.size();
//		for (int i = 1; i < n; ++i)
//		{
//			if (d[i] < d[i - 1])
//				return false;
//		}
//		return true;
//	}
//
//	int maximumSwap(int num) 
//	{		
//		auto v = toDigits(num);
//		if (isAscending(v))
//			return num;
//
//		int n = v.size();
//
//		vector<int> powers(10);
//		powers[0] = 1;
//		for (int i = 1; i < 10; ++i)
//			powers[i] = powers[i - 1] * 10;
//
//		int maxVal = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			int i_pow = powers[i];
//			for (int j = i + 1; j < n; ++j)
//			{
//				if (v[i] <= v[j])
//					continue;
//				int value = i_pow * (powers[j - i] - 1) * (v[i] - v[j]);
//				maxVal = max(maxVal, value);
//			}
//		}
//
//		return num + maxVal;
//	}
//};

// Greedy
class Solution {
public:

	vector<int> toDigits(int num)
	{
		ostringstream stream;
		stream << num;
		string s = stream.str();
		vector<int> result(s.length());
		for (int i = 0; i < s.length(); ++i)
			result[i] = s[i] - '0';
		return result;
	}

	int fromDigits(const vector<int>& d)
	{
		int result = 0;
		for (int i = 0; i < d.size(); ++i)
			result = 10 * result + d[i];
		return result;
	}

	int maximumSwap(int num)
	{
		auto v = toDigits(num);
		vector<int> last(10);
		for (int i = 0; i < v.size(); ++i)
			last[v[i]] = i;
		
		for (int i = 0; i < v.size(); ++i)
		{
			for (int d = 9; d > v[i]; --d)
			{
				if (last[d] > i)
				{
					swap(v[i], v[last[d]]);
					return fromDigits(v);
				}
			}
		}

		return num;
	}
};

int main()
{
	cout << Solution().maximumSwap(2736) << endl; // 7236
	cout << Solution().maximumSwap(9973) << endl; // 9973
	cout << Solution().maximumSwap(12) << endl; // 21
	cout << Solution().maximumSwap(21) << endl; // 21

    return 0;
}

