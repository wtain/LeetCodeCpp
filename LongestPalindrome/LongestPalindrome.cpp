
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//class Solution {
//public:
//	string longestPalindrome(string s) {
//		size_t n = s.length();
//		if (!n)
//			return "";
//		for (size_t l2 = n / 2; l2 > 0; --l2)
//		{
//			for (size_t pos = l2; pos + l2 < n; ++pos)
//			{
//				bool f = true;
//				for (size_t j = 0; j <= l2; ++j)
//				{
//					if (s[pos + j] != s[pos - j])
//					{
//						f = false;
//						break;
//					}
//				}
//				if (f)
//					return s.substr(pos - l2, 2 * l2 + 1);
//			}
//
//			for (size_t pos = l2; pos + l2 <= n; ++pos)
//			{
//				bool f = true;
//				for (size_t j = 0; j <= l2; ++j)
//				{
//					if (s[pos + j - 1] != s[pos - j])
//					{
//						f = false;
//						break;
//					}
//				}
//				if (f)
//					return s.substr(pos - l2, 2 * l2);
//			}
//		}
//		string rv;
//		rv += s[0];
//		return rv;
//	}
//};

class Solution {
public:

	class Matrix
	{
		vector<int> m_data;
		int n;
	public:
		explicit Matrix(int n)
			: n(n)
			, m_data(n*n, false)
		{
			
		}

		int& operator() (int i, int j)
		{
			return m_data[i*n + j];
		}
	};

	string longestPalindrome(string s) {
		size_t n = s.length();
		if (!n)
			return "";

		Matrix p(n);
		string rv;

		for (size_t i = 0; i < n; ++i)
		{
			p(i, i) = 1;
			if (rv.length() < 1)
				rv = s[i];
			if (i < n - 1 && s[i] == s[i + 1])
			{
				p(i, i + 1) = 1;
				rv = s.substr(i, 2);
			}
		}

		for (size_t k = 3; k <= n; ++k)
		{
			for (size_t i = 0; i < n - k + 1; ++i)
			{
				size_t j = i + k - 1;
				if (p(i + 1, j - 1) && s[i] == s[j])
				{
					p(i, j) = 1;

					if (rv.length() < k)
						rv = s.substr(i, k);
				}
			}
		}

		return rv;
	}
};

int main()
{

	/*cout << Solution().longestPalindrome("babad") << endl;
	cout << Solution().longestPalindrome("bb") << endl;
	cout << Solution().longestPalindrome("b") << endl;
	cout << Solution().longestPalindrome("") << endl;

	cout << Solution().longestPalindrome("cbbd") << endl;*/

	cout << Solution().longestPalindrome("jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel") << endl;
	

    return 0;
}

