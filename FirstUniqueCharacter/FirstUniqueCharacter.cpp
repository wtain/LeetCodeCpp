
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:

	class SeenCharacterTracker
	{
		unordered_map<char, int> index;
	public:
		SeenCharacterTracker()
		{

		}

		bool contains(char c)
		{
			return end(index) != index.find(c);
		}

		void add(int i, char c)
		{
			index.emplace(c, i);
		}

		void remove(char c)
		{
			index.erase(c);
		}

		int minIndex() const
		{
			if (index.empty())
				return -1;
			int idx = begin(index)->second;
			for (auto it = begin(index); it != end(index); ++it)
			{
				if (it->second < idx)
					idx = it->second;
			}
			return idx;
		}
	};


	int firstUniqChar(string s)
	{
		SeenCharacterTracker tracker;
		unordered_set<char> seen;
		for (int i = 0; i < s.size(); ++i)
		{
			auto it2 = seen.find(s[i]);
			if (it2 != end(seen))
				continue;
			if (!tracker.contains(s[i]))
				tracker.add(i, s[i]);
			else
			{
				tracker.remove(s[i]);
				seen.insert(s[i]);
			}
		}
		return tracker.minIndex();
	}
};

int main()
{
	cout << Solution().firstUniqChar("leetcode") << endl; // 0
	cout << Solution().firstUniqChar("loveleetcode") << endl; // 2
	cout << Solution().firstUniqChar("") << endl; // -1
	cout << Solution().firstUniqChar("aa") << endl; // -1
	cout << Solution().firstUniqChar("aabb") << endl; // -1
	cout << Solution().firstUniqChar("abab") << endl; // -1
    return 0;
}

