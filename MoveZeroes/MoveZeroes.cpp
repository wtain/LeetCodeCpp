
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		vector<int>::iterator r = nums.begin(), w = nums.begin();
		while (r != nums.end())
		{
			if (*r)
				*w++ = *r++;
			else
				++r;
		}
		while (w != nums.end())
			*w++ = 0;
	}
};

int main()
{
	std::vector<int> v = { 0, 1, 0, 3, 12 };
	Solution().moveZeroes(v);
	
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));

    return 0;
}

