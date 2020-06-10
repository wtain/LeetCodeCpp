// CourseSchedule2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_set>

using namespace std;

/*

https://leetcode.com/problems/course-schedule-ii/

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

*/

class Solution {
public:

	class Course
	{
		unordered_set<int> dependencies;
		unordered_set<int> dependants;

	public:
		Course()
		{

		}

		void addDependency(int j)
		{
			dependencies.insert(j);
		}

		void addDependant(int i)
		{
			dependants.insert(i);
		}

		void removeDependency(int j)
		{
			dependencies.erase(j);
		}

		void removeDependant(int i)
		{
			dependants.erase(i);
		}

		bool hasDependencies() const
		{
			return !dependencies.empty();
		}

		const vector<int> dependantCourses() const
		{
			return{ begin(dependants), end(dependants) };
		}
	};

	class DependenciesTracker
	{
		vector<Course> courses;
		unordered_set<int> toTake;

	public:
		DependenciesTracker(int numCourses, vector<pair<int, int>>& prerequisites)
		{
			courses.resize(numCourses);
			for (const auto& d : prerequisites)
				AddDepencency(d.first, d.second);
			for (int i = 0; i < courses.size(); ++i)
				if (!courses[i].hasDependencies())
					toTake.insert(i);
		}

		void AddDepencency(int i, int j)
		{
			courses[i].addDependency(j);
			courses[j].addDependant(i);
		}

		void RemoveDepencency(int i, int j)
		{
			courses[i].removeDependency(j);
			courses[j].removeDependant(i);
			if (!courses[i].hasDependencies())
				toTake.insert(i);
		}

		int Take()
		{
			int i = *toTake.begin();
			toTake.erase(i);
			const auto dc = courses[i].dependantCourses();
			for (auto j : dc)
				RemoveDepencency(j, i);
			return i;
		}

		bool CanTake() const
		{
			return !toTake.empty();
		}
	};

	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
	{
		vector<int> result;
		
		DependenciesTracker tracker(numCourses, prerequisites);
		while (tracker.CanTake())
			result.push_back(tracker.Take());

		if (result.size() < numCourses)
			return{};

		return result;
	}
};

int main()
{
	vector<pair<int, int>> p1 = { {1,0} };
	vector<pair<int, int>> p2 = { {1,0},{2,0},{3,1},{3,2} };

	auto r1 = Solution().findOrder(2, p1);
	copy(begin(r1), end(r1), ostream_iterator<int>(cout, " "));
	cout << endl;

	auto r2 = Solution().findOrder(4, p2);
	copy(begin(r2), end(r2), ostream_iterator<int>(cout, " "));
	cout << endl;

    return 0;
}

