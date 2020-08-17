
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <numeric>

using namespace std;

/*
https://leetcode.com/problems/distribute-candies-to-people/
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3427/
We distribute some number of candies, to a row of n = num_people people in the following way:

We then give 1 candy to the first person, 2 candies to the second person, and so on until we give n candies to the last person.

Then, we go back to the start of the row, giving n + 1 candies to the first person, n + 2 candies to the second person, and so on until we give 2 * n candies to the last person.

This process repeats (with us giving one more candy each time, and moving to the start of the row after we reach the end) until we run out of candies.  The last person will receive all of our remaining candies (not necessarily one more than the previous gift).

Return an array (of length num_people and sum candies) that represents the final distribution of candies.



Example 1:

Input: candies = 7, num_people = 4
Output: [1,2,3,1]
Explanation:
On the first turn, ans[0] += 1, and the array is [1,0,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0,0].
On the third turn, ans[2] += 3, and the array is [1,2,3,0].
On the fourth turn, ans[3] += 1 (because there is only one candy left), and the final array is [1,2,3,1].
Example 2:

Input: candies = 10, num_people = 3
Output: [5,2,3]
Explanation:
On the first turn, ans[0] += 1, and the array is [1,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0].
On the third turn, ans[2] += 3, and the array is [1,2,3].
On the fourth turn, ans[0] += 4, and the final array is [5,2,3].


Constraints:

1 <= candies <= 10^9
1 <= num_people <= 1000
*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Distribute Candies to People.
//Memory Usage : 6.3 MB, less than 83.08% of C++ online submissions for Distribute Candies to People.
class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int> result(num_people);
		//int m = (sqrt(8 * candies + 1) - 1) / 2;
		//int rows = m / num_people;
		//int rows = (candies + num_people * num_people) / ((num_people + 1) * num_people / 2 + num_people * num_people);
		const int n = num_people;
		//const int n2 = n * n;
		const int K = candies;
		//const int S = (n + 1) * n / 2;
		//const int a = n2;
		//const int b = 2 * S - n2;
		//const int c = -2 * K;
		//const int D = b*b - 4 * a*c;
		//int rows = (sqrt(D) - b) / 2;
		int rows = floor(sqrt(static_cast<double>(1 + 8ull * K)) - 1) / (2 * n);
		//int rows = (candies + num_people * num_people) / ((num_people + 1) * num_people / 2 + num_people * num_people);
		int candies_used = 0;
		if (rows > 0) {
			for (int i = 0; i < num_people; ++i) {
				result[i] = (i + 1) * rows + (rows - 1) * num_people * rows / 2;
			}
			//candies_used = (num_people + 1) * num_people / 2 + (rows - 1) * num_people * num_people;
			candies_used = accumulate(begin(result), end(result), 0);
		}
		int rest = candies - candies_used;
		for (int i = 0; i < num_people && rest > 0; ++i) {
			int candies_i = min((i + 1) + rows * num_people, rest);
			result[i] += candies_i;
			rest -= candies_i;
		}

		return result;
	}
};

int main()
{
	{
		auto r = Solution().distributeCandies(1000000000, 1000);
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl;  // [990045,990090,990135,990180,990225,990270,990315,990360,990405,990450,990495,990540,990585,990630,990675,990720,990765,990810,990855,990900,990945,990990,991035,991080,991125,991170,991215,991260,991305,991350,991395,991440,991485,991530,991575,991620,991665,991710,991755,991800,991845,991890,991935,991980,992025,992070,992115,992160,992205,992250,992295,992340,992385,992430,992475,992520,992565,992610,992655,992700,992745,992790,992835,992880,992925,992970,993015,993060,993105,993150,993195,993240,993285,993330,993375,993420,993465,993510,993555,993600,993645,993690,993735,993780,993825,993870,993915,993960,994005,994050,994095,994140,994185,994230,994275,994320,994365,994410,994455,994500,994545,994590,994635,994680,994725,994770,994815,994860,994905,994950,994995,995040,995085,995130,995175,995220,995265,995310,995355,995400,995445,995490,995535,995580,995625,995670,995715,995760,995805,995850,995895,995940,995985,996030,996075,996120,996165,996210,996255,996300,996345,996390,99643...
	}

	{
		auto r = Solution().distributeCandies(1200, 3);
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl;  // [400,392,408]
	}

	{
		auto r = Solution().distributeCandies(7, 4);
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl; // [1,2,3,1]
	}

	{
		auto r = Solution().distributeCandies(10, 3);
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl;  // [5,2,3]
	}

	{
		auto r = Solution().distributeCandies(12, 3);
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl;  // [5,4,3]
	}

    return 0;
}

