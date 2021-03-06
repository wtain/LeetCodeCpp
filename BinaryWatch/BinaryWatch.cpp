
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

/*

https://leetcode.com/problems/binary-watch/

A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

*/

class Solution {
public:

	string intToStr2(int i, bool full)
	{
		int d1 = i / 10;
		int d2 = i % 10;
		string rv;
		if (d1 || full)
			rv += '0' + d1;
		rv += '0' + d2;
		return rv;
	}

	string decode(int current)
	{
		int hour = current & 15;
		if (hour >= 12)
			return "";
		int minutes = (current >> 4) & 63;
		if (minutes >= 60)
			return "";
		return intToStr2(hour, false) + ":" + intToStr2(minutes, true);
	}

	void readBinaryWatchImpl(vector<string>& result, int num, int current, int mask)
	{
		if (!num)
		{
			auto r = decode(current);
			if (!r.empty())
				result.push_back(r);
			return;
		}
		const int maskMax = (1 << 9);
		while (mask <= maskMax)
		{
			readBinaryWatchImpl(result, num-1, current | mask, mask << 1);
			mask <<= 1;
		}
	}

	vector<string> readBinaryWatch(int num) {
		vector<string> result;
		readBinaryWatchImpl(result, num, 0, 1);
		return result;
	}
};

int main()
{
	//auto r = Solution().readBinaryWatch(1); // ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
	//auto r = Solution().readBinaryWatch(2);
	/*
	out: ["1:00","3:00","5:00","9:00","1:01","1:02","1:04","1:08","1:16","1:32","2:00","6:00","10:00","2:01","2:02","2:04","2:08","2:16","2:32","4:00","12:00","4:01","4:02","4:04","4:08","4:16","4:32","8:00","8:01","8:02","8:04","8:08","8:16","8:32","0:01","0:03","0:05","0:09","0:17","0:33","0:02","0:06","0:10","0:18","0:34","0:04","0:12","0:20","0:36","0:08","0:24","0:40","0:16","0:48","0:32"]
	     [ 3:00,  5:00,  9:00,  1:01,  1:02,  1:04,  1:08,  1:16,  1:32,  6:00,  10:00,  2:01,  2:02,  2:04,  2:08,  2:16,  2:32, 12:00,  4:01,  4:02,  4:04,  4:08,  4:16,  4:32,  8:01,  8:02,  8:04,  8:08,  8:16,  8:32,  0:03,  0:05,  0:09,  0:17,  0:33,  0:06,  0:10,  0:18,  0:34,  0:12,  0:20,  0:36,  0:24,   0:40, 0:48]
	exp: ["0:03","0:05","0:06","0:09","0:10","0:12","0:17","0:18","0:20","0:24", "0:33","0:34","0:36","0:40","0:48","1:01","1:02","1:04","1:08","1:16","1:32","2:01","2:02","2:04","2:08","2:16","2:32","3:00","4:01","4:02","4:04","4:08","4:16","4:32","5:00","6:00","8:01","8:02","8:04","8:08","8:16","8:32","9:00","10:00"]
	*/

	auto r = Solution().readBinaryWatch(4);
	/*
	["7:01","7:02","7:04","7:08","7:16","7:32","11:01","11:02","11:04","11:08","11:16","11:32","3:03","3:05","3:09","3:17","3:33","3:06","3:10","3:18","3:34","3:12","3:20","3:36","3:24","3:40","3:48","5:03","5:05","5:09","5:17","5:33","5:06","5:10","5:18","5:34","5:12","5:20","5:36","5:24","5:40","5:48","9:03","9:05","9:09","9:17","9:33","9:06","9:10","9:18","9:34","9:12","9:20","9:36","9:24","9:40","9:48","1:07","1:11","1:19","1:35","1:13","1:21","1:37","1:25","1:41","1:49","1:14","1:22","1:38","1:26","1:42","1:50","1:28","1:44","1:52","1:56","6:03","6:05","6:09","6:17","6:33","6:06","6:10","6:18","6:34","6:12","6:20","6:36","6:24","6:40","6:48","10:03","10:05","10:09","10:17","10:33","10:06","10:10","10:18","10:34","10:12","10:20","10:36","10:24","10:40","10:48","2:07","2:11","2:19","2:35","2:13","2:21","2:37","2:25","2:41","2:49","2:14","2:22","2:38","2:26","2:42","2:50","2:28","2:44","2:52","2:56","4:07","4:11","4:19","4:35","4:13","4:21","4:37","4:25","4:41","4:49","4:14","4:22","4:38...
	
	["0:15","0:23","0:27","0:29","0:30","0:39","0:43","0:45","0:46","0:51","0:53","0:54","0:57","0:58","1:07","1:11","1:13","1:14","1:19","1:21","1:22","1:25","1:26","1:28","1:35","1:37","1:38","1:41","1:42","1:44","1:49","1:50","1:52","1:56","2:07","2:11","2:13","2:14","2:19","2:21","2:22","2:25","2:26","2:28","2:35","2:37","2:38","2:41","2:42","2:44","2:49","2:50","2:52","2:56","3:03","3:05","3:06","3:09","3:10","3:12","3:17","3:18","3:20","3:24","3:33","3:34","3:36","3:40","3:48","4:07","4:11","4:13","4:14","4:19","4:21","4:22","4:25","4:26","4:28","4:35","4:37","4:38","4:41","4:42","4:44","4:49","4:50","4:52","4:56","5:03","5:05","5:06","5:09","5:10","5:12","5:17","5:18","5:20","5:24","5:33","5:34","5:36","5:40","5:48","6:03","6:05","6:06","6:09","6:10","6:12","6:17","6:18","6:20","6:24","6:33","6:34","6:36","6:40","6:48","7:01","7:02","7:04","7:08","7:16","7:32","8:07","8:11","8:13","8:14","8:19","8:21","8:22","8:25","8:26","8:28","8:35","8:37","8:38","8:41","8:42","8:44","8:49","8:50...
	*/

	copy(begin(r), end(r), ostream_iterator<string>(cout, ", "));
	cout << endl;

    return 0;
}

