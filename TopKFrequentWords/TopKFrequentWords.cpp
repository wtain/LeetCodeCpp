
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:

	struct Record
	{
		string word;
		int freq;

		Record(const string& w, int f)
			: word(w), freq(f) {}
	};

	struct Compare
	{
		bool operator() (const Record& l, const Record& r)
		{
			if (l.freq == r.freq)
				return l.word > r.word;
			return l.freq < r.freq;
		}
	};

	vector<string> topKFrequent(vector<string>& words, int k) 
	{
		unordered_map<string, int> h;
		for (const auto& w : words)
		{
			int c = h[w];
			h[w] = c + 1;
		}
		priority_queue<Record, vector<Record>, Compare> pq;
		for (const auto& p : h)
			pq.emplace(Record(p.first, p.second));

		vector<string> result;
		for (int i = 0; i < k; ++i)
		{
			result.push_back(pq.top().word);
			pq.pop();
		}
		return result;
	}
};

int main()
{
	vector<string> v1 = { "i", "love", "leetcode", "i", "love", "coding" };
	auto w1 = Solution().topKFrequent(v1, 2);
	copy(begin(w1), end(w1), ostream_iterator<string>(cout, " ")); // 	["i", "love"]

	cout << endl;

	vector<string> v2 = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
	auto w2 = Solution().topKFrequent(v2, 4);
	copy(begin(w2), end(w2), ostream_iterator<string>(cout, " ")); // 	 ["the", "is", "sunny", "day"]

	cout << endl;

    return 0;
}

