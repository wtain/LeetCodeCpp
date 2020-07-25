
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

/*
https://leetcode.com/problems/subdomain-visit-count/

A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".

We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.

Example 1:
Input:
["9001 discuss.leetcode.com"]
Output:
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
Explanation:
We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.

Example 2:
Input:
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
Output:
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
Explanation:
We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.

Notes:

The length of cpdomains will not exceed 100.
The length of each domain name will not exceed 100.
Each address will have either 1 or 2 "." characters.
The input count in any count-paired domain will not exceed 10000.
The answer output can be returned in any order.

*/

//Runtime: 32 ms, faster than 53.24% of C++ online submissions for Subdomain Visit Count.
//Memory Usage : 12.9 MB, less than 23.36% of C++ online submissions for Subdomain Visit Count.
class Solution {
public:

	struct Node {
		string domain;
		int cnt;
		unordered_map<string, Node*> children;

		Node() : cnt(0) {}

		Node(const string& s) : cnt(0), domain(s) {}

		void add(const string& fullName, int cnt) {
			this->cnt += cnt;
			const auto p = fullName.rfind('.');
			const auto domain = p != string::npos ? fullName.substr(p+1) : fullName;

			if (children.find(domain) == end(children))
				children[domain] = new Node(domain);

			if (p != string::npos) {
				auto tail = fullName.substr(0, p);
				children[domain]->add(tail, cnt);
			}
			else {
				children[domain]->cnt += cnt;
			}
		}

		void traverseImpl(vector<string>& results, const string& domain) {
			if (!domain.empty())
				results.push_back(to_string(cnt) + " " + domain);
			for (const auto& p : children)
				p.second->traverseImpl(results, p.first + (!domain.empty() ? ("." + domain) : ""));
		}

		vector<string> traverse() {
			vector<string> result;
			traverseImpl(result, "");
			return result;
		}
	};

	pair<string, int> parsePair(const string& s) {
		const auto p = s.find(' ');
		return{ s.substr(p + 1), stoi(s.substr(0, p)) };
	}

	vector<string> subdomainVisits(vector<string>& cpdomains) {
		Node root;
		for (const auto& vd : cpdomains) {
			auto p = parsePair(vd);
			root.add(p.first, p.second);
		}
		return root.traverse();
	}
};

void print(const vector<string>& sol) {
	copy(begin(sol), end(sol), ostream_iterator<string>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().subdomainVisits(vector<string>{"9001 discuss.leetcode.com"})); // ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
	print(Solution().subdomainVisits(vector<string>{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"})); // ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]

    return 0;
}

