
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:

	struct Node
	{
		int minIndex;
		int target;
		vector<int> path;

		Node(int minIdx, int trg)
			: minIndex(minIdx)
			, target(trg) {}
	};

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
	{
		vector<vector<int>> results;
		sort(begin(candidates), end(candidates));
		stack<Node> toVisit;
		toVisit.emplace(0, target);
		while (!toVisit.empty())
		{
			Node current = toVisit.top(); toVisit.pop();
			for (int i = current.minIndex; i < candidates.size(); ++i)
			{
				if (candidates[i] > current.target)
					break;
				Node next = current;
				next.minIndex = i;
				next.target -= candidates[i];
				next.path.push_back(candidates[i]);
				if (!next.target)
					results.push_back(next.path);
				else if (next.target > 0)
					toVisit.push(next);
			}
		}
		return results;
	}
};

int main()
{
	vector<int> c1 = { 2,3,6,7 };
	auto r1 = Solution().combinationSum(c1, 7);
	for (const auto& r : r1)
	{
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	cout << endl;

	vector<int> c2 = { 2,3,5 };
	auto r2 = Solution().combinationSum(c2, 8);
	for (const auto& r : r2)
	{
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

    return 0;
}

