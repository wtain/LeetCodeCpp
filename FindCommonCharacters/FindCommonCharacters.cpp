
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/find-common-characters/

Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.



Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]


Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/


//Runtime: 40 ms, faster than 23.44% of C++ online submissions for Find Common Characters.
//Memory Usage : 12.2 MB, less than 12.83% of C++ online submissions for Find Common Characters.
//class Solution {
//public:
//
//	unordered_map<char, int> getCounts(const string& s) {
//		unordered_map<char, int> result;
//		for (auto c : s)
//			result[c]++;
//		return result;
//	}
//
//	void intersect(unordered_map<char, int>& counts, const unordered_map<char, int>& c_i) {
//		for (char c = 'a'; c <= 'z'; ++c) {
//			if (!counts[c])
//				continue;
//			auto it = c_i.find(c);
//			if (end(c_i) == it)
//				counts.erase(c);
//			else
//				counts[c] = min(counts[c], it->second);
//		}
//	}
//
//	vector<string> buildVector(const unordered_map<char, int>& counts) {
//		vector<string> result;
//		for (char c = 'a'; c <= 'z'; ++c) {
//			auto it = counts.find(c);
//			if (it == end(counts))
//				continue;
//			for (int i = 0; i < it->second; ++i)
//				result.push_back(string() + c);
//		}
//		return result;
//	}
//
//	vector<string> commonChars(vector<string>& A) {
//		const size_t n = A.size();
//		if (!n)
//			return{};
//		auto counts = getCounts(A[0]);
//		for (size_t i = 1; i < n; ++i) {
//			auto counts_i = getCounts(A[i]);
//			intersect(counts, counts_i);
//		}
//		return buildVector(counts);
//	}
//};

//Runtime: 12 ms, faster than 90.74% of C++ online submissions for Find Common Characters.
//Memory Usage : 9.4 MB, less than 70.35% of C++ online submissions for Find Common Characters.
//class Solution {
//public:
//
//	vector<int> getCounts(const string& s) {
//		vector<int> result(26);
//		for (auto c : s)
//			result[c - 'a']++;
//		return result;
//	}
//
//	void intersect(vector<int>& counts, const vector<int>& c_i) {
//		for (char c = 'a'; c <= 'z'; ++c) {
//			if (!counts[c - 'a'])
//				continue;
//			if (!c_i[c - 'a'])
//				counts[c - 'a'] = 0;
//			else
//				counts[c - 'a'] = min(counts[c - 'a'], c_i[c - 'a']);
//		}
//	}
//
//	vector<string> buildVector(const vector<int>& counts) {
//		vector<string> result;
//		for (char c = 'a'; c <= 'z'; ++c) {
//			for (int i = 0; i < counts[c - 'a']; ++i)
//				result.push_back(string() + c);
//		}
//		return result;
//	}
//
//	vector<string> commonChars(vector<string>& A) {
//		const size_t n = A.size();
//		if (!n)
//			return{};
//		auto counts = getCounts(A[0]);
//		for (size_t i = 1; i < n; ++i) {
//			auto counts_i = getCounts(A[i]);
//			intersect(counts, counts_i);
//		}
//		return buildVector(counts);
//	}
//};

//Runtime: 12 ms, faster than 90.74% of C++ online submissions for Find Common Characters.
//Memory Usage : 9.6 MB, less than 60.34% of C++ online submissions for Find Common Characters.
class Solution {
public:

	vector<int> getCounts(const string& s) {
		vector<int> result(26);
		for (auto c : s)
			result[c - 'a']++;
		return result;
	}

	void intersect(vector<int>& counts, const vector<int>& c_i) {
		for (int i = 0; i < 26; ++i)
			counts[i] = min(counts[i], c_i[i]);
	}

	vector<string> buildVector(const vector<int>& counts) {
		vector<string> result;
		for (int i = 0; i < 26; ++i) {
			char c = 'a' + i;
			for (int j = 0; j < counts[i]; ++j)
				result.push_back(string() + c);
		}
		return result;
	}

	vector<string> commonChars(vector<string>& A) {
		const size_t n = A.size();
		if (!n)
			return{};
		auto counts = getCounts(A[0]);
		for (size_t i = 1; i < n; ++i) {
			auto counts_i = getCounts(A[i]);
			intersect(counts, counts_i);
		}
		return buildVector(counts);
	}
};

void print(const vector<string>& result) {
	copy(begin(result), end(result), ostream_iterator<string>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().commonChars(vector<string>{"bella", "label", "roller"})); // e l l
	print(Solution().commonChars(vector<string>{"cool", "lock", "cook"})); // c o

    return 0;
}

