
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Solution {
public:

	list<string> split(string path)
	{
		list<string> result;
		string current;
		for (int i = 0; i < path.length(); ++i)
		{
			if (path[i] == '/')
			{
				if (!current.empty())
					result.push_back(current);
				current = "";
			}
			else
				current += path[i];
		}
		if (!current.empty())
			result.push_back(current);
		return result;
	}

	string buildPath(const list<string>& p)
	{
		string result;
		if (p.empty())
			return "/";
		for (const auto& i : p)
		{
			result += "/";
			result += i;
		}
		return result;
	}

	string simplifyPath(string path) 
	{
		auto p = split(path);
		
		auto it = begin(p);
		while (end(p) != (it = find(it, end(p), ".")))
			it = p.erase(it);

		it = begin(p);
		while (end(p) != (it = find(it, end(p), "..")))
		{
			auto it1 = it; 
			if (it != begin(p))
			{
				advance(it1, -1);
				++it;
				it = p.erase(it1, it);
			}
			else
				it = p.erase(it);
		}
		return buildPath(p);
	}
};

int main()
{
	cout << Solution().simplifyPath("/home/") << endl; // "/home"
	cout << Solution().simplifyPath("/a/./b/../../c/") << endl; // "/c"
	cout << Solution().simplifyPath("/a/../../b/../c//.//") << endl; // "/c"
	cout << Solution().simplifyPath("/a//b////c/d//././/..") << endl; // "/a/b/c"
	cout << Solution().simplifyPath("/../") << endl; // "/"
	cout << Solution().simplifyPath("/home//foo/") << endl; // "/home/foo"

    return 0;
}

