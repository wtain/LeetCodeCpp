
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/employee-importance/

You are given a data structure of employee information, which includes the employee's unique id, his importance value and his direct subordinates' id.

For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.

Example 1:

Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
Output: 11
Explanation:
Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.


Note:

One employee has at most one direct leader and may have several subordinates.
The maximum number of employees won't exceed 2000.

*/

// Definition for Employee.
class Employee {
public:
int id;
int importance;
vector<int> subordinates;
};

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		unordered_map<int, Employee*> map;
		for (const auto& pE : employees)
			map[pE->id] = pE;
		int sum = 0;
		stack<int> toVisit;
		toVisit.emplace(id);
		while (!toVisit.empty()) {
			int i = toVisit.top(); toVisit.pop();
			sum += map[i]->importance;
			for (const auto j : map[i]->subordinates)
				toVisit.emplace(j);
		}
		return sum;
	}
};

Employee* createEmployee(int id, int importance, vector<int> subs) {
	Employee* e = new Employee();
	e->id = id;
	e->importance = importance;
	e->subordinates = subs;
	return e;
}

int main()
{
	{
		Employee* e1 = createEmployee(1, 5, {2,3});
		Employee* e2 = createEmployee(2, 3, {});
		Employee* e3 = createEmployee(3, 3, {});
		cout << Solution().getImportance({ e1,e2,e3 }, 1) << endl; // 11;
	}

    return 0;
}

