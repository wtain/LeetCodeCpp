
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/relative-ranks/

506. Relative Ranks

Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
Accepted
*/

class Solution {
public:

	struct Entry
	{
		int value;
		int index;

		Entry(int v, int i) : value(v), index(i) {}

		struct Comparator
		{
			bool operator() (const Entry& left, const Entry& right)
			{
				return left.value > right.value;
			}
		};
	};

	vector<string> findRelativeRanks(vector<int>& nums) {
		/*int min1 = nums[0];
		int min2 = numeric_limits<int>::max();
		int min3 = numeric_limits<int>::max();
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] < min1) {
				min3 = min2;
				min2 = min1;
				min1 = nums[i];
			}
			else if (nums[i] < min2) {
				min3 = min2;
				min2 = nums[i];
			}
			else if (nums[i] < min3) {
				min3 = nums[i];
			}
		}
		vector<string> result;
		result.reserve(nums.size());
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == min1)
				result.push_back("Gold Medal");
			else if (nums[i] == min2)
				result.push_back("Silver Medal");
			else if (nums[i] == min3)
				result.push_back("Bronze Medal");
			else
				result.push_back(to_string(nums[i]));
		}*/

		//vector<string> result;
		//result.reserve(nums.size());
		//sort(begin(nums), end(nums));
		//for (int i = 0; i < nums.size(); ++i) {
		//	if (i == 0)
		//		result.push_back("Gold Medal");
		//	else if (i == 1)
		//		result.push_back("Silver Medal");
		//	else if (i == 2)
		//		result.push_back("Bronze Medal");
		//	else
		//		result.push_back(to_string(i + 1));
		//}

		vector<Entry> entries;
		entries.reserve(nums.size());
		for (int i = 0; i < nums.size(); ++i)
			entries.emplace_back(nums[i], i);

		sort(begin(entries), end(entries), Entry::Comparator());

		vector<string> result;
		result.resize(nums.size());
		for (int j = 0; j < entries.size(); ++j) {
			const int i = entries[j].index;
			if (j == 0)
				result[i] = "Gold Medal";
			else if (j == 1)
				result[i] = "Silver Medal";
			else if (j == 2)
				result[i] = "Bronze Medal";
			else
				result[i] = to_string(j + 1);
		}

		return result;
	}
};

int main()
{
	{
		auto r = Solution().findRelativeRanks(vector<int>{5, 4, 3, 2, 1});
		copy(begin(r), end(r), ostream_iterator<string>(cout, " ")); // ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
		cout << endl;
	}

	{
		auto r = Solution().findRelativeRanks(vector<int>{1, 2, 3, 4, 5});
		copy(begin(r), end(r), ostream_iterator<string>(cout, " "));
		cout << endl;
	}

	{
		auto r = Solution().findRelativeRanks(vector<int>{10, 3, 8, 9, 4}); // ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
		copy(begin(r), end(r), ostream_iterator<string>(cout, " "));
		cout << endl;
	}

    return 0;
}

