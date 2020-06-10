
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {
		size_t i = 0, dest = 0;
		while (i < chars.size())
		{
			chars[dest++] = chars[i];
			size_t j = i;
			while (j < chars.size() && chars[j] == chars[i])
				++j;
			size_t num = j - i;
			if (num > 1)
			{
				size_t d = 1000;
				bool f = false;
				while (d >= 1)
				{
					size_t v = num / d;
					num %= d;
					d /= 10;
					if (v || f)
					{
						chars[dest++] = '0' + v;
						f = true;
					}
				}
			}
			i = j;
		}
		return dest;
	}
};

int main()
{
	vector<char> v1 = { 'a','a','b','b','c','c','c' };
	cout << Solution().compress(v1) << endl; // 6

	vector<char> v2 = { 'a' };
	cout << Solution().compress(v2) << endl; // 1

	vector<char> v3 = { 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
	cout << Solution().compress(v3) << endl; // 4

	return 0;
}

