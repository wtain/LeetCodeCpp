
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

/*
https://leetcode.com/problems/integer-replacement/

Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?
*/

class Solution {
public:

	struct Compare
	{
		bool operator() (const pair<unsigned, int>& p1, const pair<unsigned, int>& p2) const
		{
			return p1.second > p2.second;
		}
	};

	int integerReplacement(int n) 
	{
		priority_queue<pair<unsigned, int>, vector<pair<unsigned, int>>, Compare> toProcess;
		unordered_map<int, int> dist;
		toProcess.emplace(n, 0);
		while (!toProcess.empty())
		{
			auto cp = toProcess.top(); toProcess.pop();			
			unsigned c = cp.first;
			int v = cp.second;
			auto itd = dist.find(c);
			if (itd != end(dist))
				continue;
			dist.emplace_hint(itd, c, v);
			if (c == 1)
				break;
			vector<unsigned> trans;
			if (c % 2)
			{
				trans.push_back(c + 1);
				trans.push_back(c - 1);
			}
			else
				trans.push_back(c / 2);
			for (const auto cn : trans)
			{
				auto it = dist.find(cn);
				int vnew = v + 1;
				if (it == end(dist))
					toProcess.emplace(cn, vnew);
			}
		}
		return dist[1];
	}
};

int main()
{
	//cout << Solution().integerReplacement(9) << endl;
	cout << Solution().integerReplacement(2147483647) << endl;
	
    return 0;
}

