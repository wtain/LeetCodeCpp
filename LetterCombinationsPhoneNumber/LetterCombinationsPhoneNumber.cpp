
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) 
	{
		if (digits.empty())
			return{};
		vector<string> result;
		unordered_map<char, string> tr;
		tr['2'] = "abc";
		tr['3'] = "def";
		tr['4'] = "ghi";
		tr['5'] = "jkl";
		tr['6'] = "mno";
		tr['7'] = "pqrs";
		tr['8'] = "tuv";
		tr['9'] = "wxyz";

		list<string> list1, list2;
		list1.push_back("");
		bool side = true;

		for (int i = 0; i < digits.length(); ++i)
		{
			auto& l1 = side ? list1 : list2;
			auto& l2 = side ? list2 : list1;

			string t = tr[digits[i]];
			while (!l1.empty())
			{
				auto s = l1.back(); l1.pop_back();
				for (int j = 0; j < t.length(); ++j)
					l2.push_back(s + t[j]);
			}
			side = !side;
		}

		auto& l1 = side ? list1 : list2;
		for (const auto& p : l1)
			result.push_back(p);

		return result;
	}
};

int main()
{
	auto v = Solution().letterCombinations("23");
	copy(begin(v), end(v), ostream_iterator<string>(cout, " ")); // "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"

    return 0;
}

