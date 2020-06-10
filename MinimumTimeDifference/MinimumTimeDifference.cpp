
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:

	static int c2i(const char c)
	{
		return c - '0';
	}

	static int getMinutes(const string& t)
	{
		int h = c2i(t[0]) * 10 + c2i(t[1]);
		int m = c2i(t[3]) * 10 + c2i(t[4]);
		return 60 * h + m;
	}

	int findMinDifference(vector<string>& timePoints) 
	{
		static const int MinutesInDay = 24 * 60;
		vector<int> times;
		transform(begin(timePoints), end(timePoints), back_inserter(times), &getMinutes);
		sort(begin(times), end(times));
		int minDiff = MinutesInDay;
		for (int i = 0; i < times.size(); ++i)
		{
			int i2 = (i + 1);
			int diff = 0;
			if (i2 == times.size())
				diff = MinutesInDay + times[0] - times[i];
			else
				diff = times[i2] - times[i];
			minDiff = min(minDiff, diff);
		}
		return minDiff;
	}
};

int main()
{
	vector<string> timePoints = { "23:59", "00:00" };
	cout << Solution().findMinDifference(timePoints) << endl;
    return 0;
}

