
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/reorganize-string/

Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].

*/

//Runtime: 8 ms, faster than 33.01% of C++ online submissions for Reorganize String.
//Memory Usage : 6.3 MB, less than 70.78% of C++ online submissions for Reorganize String.
class Solution {
public:
	
	unordered_map<char, int> countChars(const string& S) {
		unordered_map<char, int> result;
		for (const auto c : S)
			result[c] ++;
		return result;
	}

	struct Less {

		bool operator() (const pair<char, int>& l, const pair<char, int>& r) const {
			return l.second < r.second;
		}

	};

	priority_queue<pair<char, int>, vector<pair<char, int>>, Less> buildQueue(const unordered_map<char, int>& counts) {
		priority_queue<pair<char, int>, vector<pair<char, int>>, Less> result;
		for (const auto& p : counts)
			result.push(p);
		return result;
	}

	string reorganizeString(string S) {
		const auto counts = countChars(S);
		auto q = buildQueue(counts);
		string result;
		while (!q.empty()) {
			auto top1 = q.top();
			q.pop();
			if (result.empty() || result.back() != top1.first) {
				result += top1.first;
				if (--top1.second)
					q.push(top1);
			}
			else {
				if (q.empty())
					return "";
				auto top2 = q.top();
				q.pop();
				result += top2.first;
				if (--top2.second)
					q.push(top2);
				q.push(top1);
			}
		}
		return result;
	}
};

int main()
{
	cout << Solution().reorganizeString("aab") << endl; // aba
	cout << Solution().reorganizeString("aaab") << endl; // 

    return 0;
}

