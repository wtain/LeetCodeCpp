
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
	vector<string> codes = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
public:

	string mapChar(char c)
	{
		return codes[c - 'a'];
	}

	string mapString(const string& s)
	{
		string r;
		for (int i = 0; i < s.length(); ++i)
			r += mapChar(s[i]);
		return r;
	}

	int uniqueMorseRepresentations(vector<string>& words) 
	{
		unordered_set<string> codes;
		for (const auto& w : words)
			codes.insert(mapString(w));
		return codes.size();
	}
};


int main()
{
	vector<string> words = { "gin", "zen", "gig", "msg" };
	cout << Solution().uniqueMorseRepresentations(words) << endl; // 2
    return 0;
}

