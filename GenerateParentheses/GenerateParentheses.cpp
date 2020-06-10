
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution 
{
public:

	vector<string> generateParenthesis(int n) 
	{
		const int targetLength = 2 * n;
		vector<string> result;
		vector<pair<string, pair<int, int>>> toProcess;
		toProcess.emplace_back("(", make_pair(1, 1)); // balanse, total open
		while (!toProcess.empty())
		{
			auto p = toProcess.back();
			toProcess.pop_back();
			if (p.first.length() == targetLength)
			{
				result.push_back(p.first);
				continue;
			}
			if (p.second.second < n)
				toProcess.emplace_back(p.first + "(", make_pair(p.second.first + 1, p.second.second + 1));
			if (p.second.first > 0)
				toProcess.emplace_back(p.first + ")", make_pair(p.second.first - 1, p.second.second));
		}

		return result;
	}
};

int main()
{
	auto result = Solution().generateParenthesis(4);

	copy(begin(result), end(result), ostream_iterator<string>(cout, "\n"));
	cout << endl;

    return 0;
}

