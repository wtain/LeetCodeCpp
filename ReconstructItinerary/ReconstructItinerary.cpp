
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/reconstruct-itinerary/
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
But it is larger in lexical order.
*/

// FAILS ON: {"JFK", "KUL"}, { "JFK","NRT" }, { "NRT","JFK" }
//class Solution {
//public:
//
//	map<string, set<string>> getTickets(const vector<vector<string>>& tickets) {
//		map<string, set<string>> result;
//		for (const auto& t : tickets)
//			result[t[0]].emplace(t[1]);
//		return result;
//	}
//
//	vector<string> findItinerary(vector<vector<string>>& tickets) {
//		vector<string> result;
//		result.reserve(tickets.size() + 1);
//
//		auto tmap = getTickets(tickets);
//		string current = "JFK";
//		result.push_back(current);
//		while (!tmap.empty()) {
//			auto it = tmap.find(current);
//			auto& tol = it->second;
//			auto it2 = tol.begin();
//			current = *it2;
//			result.push_back(current);
//			tol.erase(it2);
//			if (tol.empty())
//				tmap.erase(it);
//		}
//
//		return result;
//	}
//};

void print(const vector<string>& a) {
	copy(begin(a), end(a), ostream_iterator<string>(cout, " "));
	cout << endl;
}

//Runtime: 40 ms, faster than 90.78% of C++ online submissions for Reconstruct Itinerary.
//Memory Usage : 13 MB, less than 99.72% of C++ online submissions for Reconstruct Itinerary.
class Solution {
public:

	map<string, map<string, int>> getTickets(const vector<vector<string>>& tickets) {
		map<string, map<string, int>> result;
		for (const auto& t : tickets)
			result[t[0]][t[1]]++;
		return result;
	}

	bool findItineraryImpl(vector<string>& itinerary, map<string, map<string, int>>& tickets) {
		//print(itinerary);
		if (itinerary.size() == itinerary.capacity())
			return true;
		const auto& current = itinerary.back();
		auto it = tickets.find(current);
		if (it == end(tickets))
			return false;
		auto& tol = it->second;
		for (auto it2 = begin(tol); it2 != end(tol); ++it2) {
			if (!it2->second)
				continue;

			itinerary.push_back(it2->first);
			it2->second--;
			if (findItineraryImpl(itinerary, tickets))
				return true;
			it2->second++;
			itinerary.pop_back();
		}
		return false;
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<string> result;
		result.reserve(tickets.size() + 1);

		auto tmap = getTickets(tickets);
		string current = "JFK";
		result.push_back(current);

		findItineraryImpl(result, tmap);

		return result;
	}
};

int main()
{
	print(Solution().findItinerary(vector<vector<string>>{
		{"EZE", "AXA"}, { "TIA","ANU" }, { "ANU","JFK" }, { "JFK","ANU" }, { "ANU","EZE" }, { "TIA","ANU" }, { "AXA","TIA" }, { "TIA","JFK" }, { "ANU","TIA" }, { "JFK","TIA" }
	})); // ["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]

	print(Solution().findItinerary(vector<vector<string>>{
		{"JFK", "KUL"}, { "JFK","NRT" }, { "NRT","JFK" }
	})); // JFK NRT JFK KUL

	print(Solution().findItinerary(vector<vector<string>>{
		{ "MUC", "LHR" }, 
		{ "JFK", "MUC" }, 
		{ "SFO", "SJC" }, 
		{ "LHR", "SFO" }
	})); // ["JFK", "MUC", "LHR", "SFO", "SJC"]

	print(Solution().findItinerary(vector<vector<string>>{
		{ "JFK", "SFO"}, { "JFK","ATL" }, { "SFO","ATL" }, { "ATL","JFK" }, { "ATL","SFO" }
	})); // ["JFK","ATL","JFK","SFO","ATL","SFO"]
	

    return 0;
}

