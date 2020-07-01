
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/unique-email-addresses/

Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails?



Example 1:

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails


Note:

1 <= emails[i].length <= 100
1 <= emails.length <= 100
Each emails[i] contains exactly one '@' character.
All local and domain names are non-empty.
Local names do not start with a '+' character.

*/

//Runtime: 48 ms, faster than 78.84% of C++ online submissions for Unique Email Addresses.
//Memory Usage : 14.9 MB, less than 34.79% of C++ online submissions for Unique Email Addresses.
class Solution {
public:

	static string canonizeEmail(const string& email) {
		auto p = email.find('@');
		auto name = email.substr(0, p);
		auto domain = email.substr(p+1);

		auto pp = name.find('+');
		if (pp != string::npos)
			name = name.substr(0, pp);

		name.erase(remove(begin(name), end(name), '.'), end(name));

		return name + "@" + domain;
	}

	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> unique;

		transform(begin(emails), end(emails), inserter(unique, end(unique)), [](const auto& email) { return canonizeEmail(email); });

		return unique.size();
	}
};

int main()
{
	cout << Solution().numUniqueEmails(vector<string>{ "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com" }) << endl; // 2

    return 0;
}

