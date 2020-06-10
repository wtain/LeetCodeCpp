
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:

	struct Node
	{
		int Id;
		int Distance;

		Node(int id, int dist)
			: Id(id), Distance(dist) {}

		struct Compare
		{
			bool operator() (const Node& l, const Node& r)
			{
				return l.Distance > r.Distance;
			}
		};
	};

	struct Edge : pair<int, int>
	{
		int TargetId() const { return first; }
		int Time() const { return second; }

		Edge(int targetId, int time)
			: pair<int, int>(targetId, time) {}

		bool operator== (const Edge& other) const
		{
			return TargetId() == other.TargetId() && Time() == other.Time();
		}
	};

	struct EdgeEq
	{
		bool operator() (const Edge& l, const Edge& r) const
		{
			return l == r;
		}
	};

	struct EdgeHash {
	public:
		int operator()(const Edge &x) const
		{
			return hash<int>()(x.first) ^ hash<int>()(x.second);
		}
	};

	int networkDelayTime(vector<vector<int>>& times, int N, int K) 
	{
		unordered_map<int, unordered_set<Edge, EdgeHash, EdgeEq>> transitions;
		for (const auto& e : times)
		{
			auto it = transitions.find(e[0]);
			if (it == end(transitions))
				it = transitions.emplace_hint(it, make_pair(e[0], unordered_set<Edge, EdgeHash, EdgeEq>()));
			it->second.emplace(Edge(e[1], e[2]));
		}
		
		unordered_map<int, int> dist;
		//dist[K] = 0;

		priority_queue<Node, vector<Node>, Node::Compare> toVisit;

		toVisit.push(Node(K, 0));
		while (!toVisit.empty())
		{
			auto current = toVisit.top();
			toVisit.pop();
			auto it = dist.find(current.Id);
			if (it != end(dist))
				continue;
			dist.emplace_hint(it, make_pair(current.Id, current.Distance));
			auto itt = transitions.find(current.Id);
			if (itt != end(transitions))
			{
				const auto& t = itt->second;
				for (const auto& n : t)
				{
					auto it1 = dist.find(n.TargetId());
					if (it1 == end(dist))
					{
						toVisit.emplace(Node(n.TargetId(), n.Time()+current.Distance));
					}
				}
			}
		}
		
		if (dist.size() != N)
			return -1;

		int mx = -1;
		for (const auto& d : dist)
		{
			if (mx < d.second)
				mx = d.second;
		}

		return mx;

		/*
		
		
		vector<bool> visited(N, false), vector<bool> toVisitF(N, false);;
		int unvisitedCnt = N;

		
		toVisitF[K] = true;
		while (!toVisit.empty())
		//while (unvisitedCnt > 0)
		{
			const auto node = toVisit.top(); toVisit.pop();
			visited[node.Id] = true;
			for (int i = 0; i < N; ++i)
			{
				if (i == K)
					continue;
				if (!times[node.Id][i])
					continue;
				if (visited[i])
					continue;
				int d = node.Distance + times[node.Id][i];
				if (dist[i] > d)
				{
					dist[i] = d;	
					if (toVisitF[i])
					{
						toVisitF[i] = false;
						toVisit
					}
				}
				if (!toVisitF[i])
				{
					toVisitF[i] = true;
					toVisit.push(Node(i, dist[i]));
				}
			}
		}
		*/

		return 0;
	}
};


int main()
{
	vector<vector<int>> nodes = 
	{ 
		{ 1, 2, 7 },
		{ 1, 3, 9 },
		{ 1, 6, 14 },
		
		{ 2, 1, 7 },
		{ 3, 1, 9 },
		{ 6, 1, 14 },


		{ 2, 3, 10 },
		{ 2, 4, 15 },

		{ 3, 2, 10 },
		{ 4, 2, 15 },

		{ 3, 4, 11 },
		{ 3, 6, 2 },

		{ 4, 3, 11 },
		{ 6, 3, 2 },

		{ 6, 5, 9 },

		{ 5, 6, 9 },

		{ 5, 4, 6 },

		{ 4, 5, 6 },
	};
	cout << Solution().networkDelayTime(nodes, 6, 1) << endl;

    return 0;
}

