
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/553/week-5-august-29th-august-31st/3442/
https://leetcode.com/problems/largest-component-size-by-common-factor/

Given a non-empty array of unique positive integers A, consider the following graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.



Example 1:

Input: [4,6,15,35]
Output: 4

Example 2:

Input: [20,50,9,63]
Output: 2

Example 3:

Input: [2,3,6,7,4,12,21,39]
Output: 8

Note:

1 <= A.length <= 20000
1 <= A[i] <= 100000

*/

/*
n = 20000
m = 100000
divisors count = d = sqrt(m) =~ 500
d * n = 20000 * 500 = 10 000 000

*/

//class Solution {
//public:
//
//	int getRoot(const unordered_map<int, int>& eq, int label) {
//		unordered_map<int, int>::const_iterator it;
//		while ((it = eq.find(label)) != end(eq) && label != it->second) {
//			label = it->second;
//		}
//		return label;
//	}
//
//	int largestComponentSize(vector<int>& A) {
//		const int n = A.size();
//		const int m = 100000;
//		const int ms = sqrt(m) + 1;
//		/*vector<unordered_set<int>> divisors(n);
//		for (int i = 0; i < n; ++i) {
//			const int sAi = sqrt(A[i]);
//			for (int j = 2; j <= sAi; ++j) {
//				if (A[i] % j == 0)
//					divisors[i].emplace(j);
//			}
//		}*/
//		vector<int> labels(n);
//
//		for (int i = 0; i < n; ++i)
//			labels[i] = i;
//
//		unordered_map<int, int> eq;
//
//		for (int j = 2; j <= ms; ++j) {
//			unordered_set<int> t;
//			int minCluster = n;
//			for (int i = 0; i < n; ++i) {
//				if (A[i] % j == 0) {
//					t.emplace(i);
//					int label = getRoot(eq, labels[i]);
//					minCluster = min(minCluster, label);
//				}
//			}
//			if (minCluster < n) {
//				//minCluster = getRoot(eq, minCluster);
//				for (auto idx : t) {
//					eq[labels[idx]] = minCluster;
//					labels[idx] = minCluster;
//				}
//			}
//		}
//		//unordered_set<int> clusters;
//		vector<int> sizes(n);
//		int maxSize = 0;
//		for (int i = 0; i < n; ++i) {
//			int label = getRoot(eq, labels[i]);
//			//clusters.emplace(label);
//			
//			sizes[label]++;
//			maxSize = max(maxSize, sizes[label]);
//		}
//		//return clusters.size();
//		return maxSize;
//	}
//};

//class Solution {
//public:
//
//	int getRoot(const unordered_map<int, int>& eq, int label) {
//		unordered_map<int, int>::const_iterator it;
//		while ((it = eq.find(label)) != end(eq) && label != it->second) {
//			label = it->second;
//		}
//		return label;
//	}
//
//	int largestComponentSize(vector<int>& A) {
//		const int n = A.size();
//		const int m = 100000;
//		const int ms = sqrt(m);
//		vector<int> labels(n);
//
//		for (int i = 0; i < n; ++i)
//			labels[i] = i;
//
//		unordered_map<int, int> eq;
//
//		for (int j = 2; j <= ms; ++j) {
//			unordered_set<int> t;
//			int minCluster = n;
//			for (int i = 0; i < n; ++i) {
//				if (A[i] % j == 0) {
//					t.emplace(i);
//					int label = getRoot(eq, labels[i]);
//					minCluster = min(minCluster, label);
//				}
//			}
//			for (auto idx : t) {
//				eq[labels[idx]] = minCluster;
//				labels[idx] = minCluster;
//			}
//		}
//		vector<int> sizes(n);
//		int maxSize = 0;
//		for (int i = 0; i < n; ++i) {
//			int label = getRoot(eq, labels[i]);
//
//			sizes[label]++;
//			maxSize = max(maxSize, sizes[label]);
//		}
//		return maxSize;
//	}
//};

//class Solution {
//public:
//
//	int getRoot(const vector<int>& labels, int label) {
//		while (labels[label] != label)
//			label = labels[label];
//		return label;
//	}
//
//	int largestComponentSize(vector<int>& A) {
//		const int n = A.size();
//		vector<int> labels(n), rank(n);
//
//		//const int m = 100000;
//		//const int ms = sqrt(m);
//
//		int m = 0;
//		for (int i = 0; i < n; ++i) {
//			labels[i] = i;
//			//rank[i] = 0;
//			m = max(m, A[i]);
//		}
//		//const int ms = sqrt(m);
//		//const int ms = m / 2;
//		const int ms = m;
//
//		for (int j = 2; j <= ms; ++j) {
//			unordered_set<int> t;
//			int minCluster = n;
//			int maxRank = -1;
//			for (int i = 0; i < n; ++i) {
//				if (A[i] % j == 0) {
//					t.emplace(i);
//					int label = getRoot(labels, labels[i]);
//					//minCluster = min(minCluster, label);
//
//					if (rank[label] > maxRank) {
//						maxRank = rank[label];
//						minCluster = label;
//					}
//
//					/*if (minCluster == n)
//						minCluster = label;
//					else {
//						if (rank[minCluster] > rank[label])
//							labels[label] = minCluster;
//						else {
//							labels[minCluster] = label;
//							if (rank[minCluster] == rank[label])
//								rank[label]++;
//						}
//					}*/
//				}
//			}
//			++maxRank;
//			for (auto idx : t) {
//				labels[idx] = minCluster;
//				rank[idx] = maxRank;
//			}
//		}
//		vector<int> sizes(n);
//		int maxSize = 0;
//		for (int i = 0; i < n; ++i) {
//			int label = getRoot(labels, labels[i]);
//
//			sizes[label]++;
//			maxSize = max(maxSize, sizes[label]);
//		}
//		return maxSize;
//	}
//};

// Runtime: 992 ms, faster than 11.92% of C++ online submissions for Largest Component Size by Common Factor.
// Memory Usage : 44.6 MB, less than 46.93% of C++ online submissions for Largest Component Size by Common Factor.
class Solution {
public:

	int getRoot(unordered_map<int, int>& roots, int label) {

		auto it = roots.find(label);
		if (it == end(roots))
			roots[label] = label;

		while (roots[label] != label)
			label = roots[label];
		return label;
	}

	void doUnion(unordered_map<int, int>& roots, int n, int f) {
		int r1 = getRoot(roots, n);
		int r2 = getRoot(roots, f);
		if (r1 < r2)
			roots[r2] = r1;
		else
			roots[r1] = r2;
	}

	int largestComponentSize(vector<int>& A) {
		const int n = A.size();
		
		unordered_map<int, int> roots;

		for (int i = 0; i < n; ++i) {
			for (int j = 2; j*j <= A[i]; ++j) {
				if (A[i] % j == 0) {
					doUnion(roots, A[i], j);
					int res = A[i] / j;
					if (res != j)
						doUnion(roots, A[i], res);
				}
			}
		}
		unordered_map<int, int> sizes;
		int maxSize = 0;
		for (int i = 0; i < n; ++i) {
			int root = getRoot(roots, A[i]);

			sizes[root]++;
			maxSize = max(maxSize, sizes[root]);
		}
		return maxSize;
	}
};

// https://leetcode.com/problems/largest-component-size-by-common-factor/discuss/820610/JAVA-Union-and-Find-Technique-Maintain-ParentMap
// Runtime: 1096 ms, faster than 9.75% of C++ online submissions for Largest Component Size by Common Factor.
// Memory Usage : 44.7 MB, less than 45.85% of C++ online submissions for Largest Component Size by Common Factor.
//class Solution {
//public:
//
//	int getRoot(unordered_map<int, int>& parents, int label) {
//		auto it = parents.find(label);
//		if (it == end(parents))
//			parents.emplace_hint(it, label, label);
//
//		while (label != parents[label])
//			label = parents[label];
//
//		return label;
//	}
//
//	void doUnion(int num, int factor, unordered_map<int, int>& parents) {
//		int numParent = getRoot(parents, num);
//		int factorParent = getRoot(parents, factor);
//
//		if (numParent < factorParent) {
//			parents[factorParent] = numParent;
//		}
//		else {
//			parents[numParent] = factorParent;
//		}
//	}
//
//	int largestComponentSize(vector<int>& A) {
//		const int n = A.size();
//		unordered_map<int, int> parents;
//
//		for (int num: A) {
//			for (int factor = 2; factor*factor <= num; ++factor) {
//				if (num % factor == 0) {
//					doUnion(num, factor, parents);
//					if (num / factor != factor) {
//						doUnion(num, num / factor, parents);
//					}
//				}
//			}
//		}
//
//		unordered_map<int, int> cc;
//		int maxComp = 0;
//		for (auto num : A) {
//			int pk = getRoot(parents, num);
//			auto it = cc.find(pk);
//			cc[pk] = (it == end(cc) ? 0 : it->second) + 1;
//			maxComp = max(maxComp, cc[pk]);
//		}
//		return maxComp;
//	}
//};

int main()
{
	cout << Solution().largestComponentSize(vector<int>{77, 11, 6, 8, 10, 70}) << endl; // 6

	cout << Solution().largestComponentSize(vector<int>{99, 68, 70, 77, 35, 52, 25, 62}) << endl; // 8

	cout << Solution().largestComponentSize(vector<int>{99, 68, 70, 77, 35, 52, 53, 25, 62}) << endl; // 8

	cout << Solution().largestComponentSize(vector<int>{79, 432, 449, 457, 463, 926, 966}) << endl; // 4
	
	cout << Solution().largestComponentSize(vector<int>{79, 432, 449, 457, 463, 926, 966, 981, 985}) << endl; // 5
	cout << Solution().largestComponentSize(vector<int>{79, 432, 449, 457, 463, 926, 960, 963, 966, 981, 985}) << endl; // 8
	
	cout << Solution().largestComponentSize(vector<int>{432, 926, 959, 960, 449, 963, 966, 929, 457, 463, 981, 985, 79}) << endl; // 9
	
	cout << Solution().largestComponentSize(vector<int>{405, 406, 407, 414, 416, 417, 425, 938, 429, 432, 926, 959, 960, 449, 963, 966, 929, 457, 463, 981, 985, 79, 487, 1000, 494, 508}) << endl; // 21
		
	cout << Solution().largestComponentSize(vector<int>{757, 770, 260, 778, 270, 272, 785, 274, 290, 291, 292, 296, 810, 816, 314, 829, 833, 841, 349, 880, 369, 147, 897, 387, 390, 905, 405, 406, 407, 414, 416, 417, 425, 938, 429, 432, 926, 959, 960, 449, 963, 966, 929, 457, 463, 981, 985, 79, 487, 1000, 494, 508}) << endl; // 44
	
	cout << Solution().largestComponentSize(vector<int>{2, 7, 522, 526, 535, 26, 944, 35, 519, 45, 48, 567, 266, 68, 74, 591, 81, 86, 602, 93, 610, 621, 111, 114, 629, 641, 131, 651, 142, 659, 669, 161, 674, 163, 180, 187, 190, 194, 195, 206, 207, 218, 737, 229, 240, 757, 770, 260, 778, 270, 272, 785, 274, 290, 291, 292, 296, 810, 816, 314, 829, 833, 841, 349, 880, 369, 147, 897, 387, 390, 905, 405, 406, 407, 414, 416, 417, 425, 938, 429, 432, 926, 959, 960, 449, 963, 966, 929, 457, 463, 981, 985, 79, 487, 1000, 494, 508}) << endl; // 84
	cout << Solution().largestComponentSize(vector<int>{84, 171, 548, 709, 455, 967, 328, 779, 79, 16, 168, 675, 276, 473, 697, 26, 731, 668, 634, 607}) << endl; // 16

	cout << Solution().largestComponentSize(vector<int>{99, 38, 73, 74, 44, 19, 25, 24, 57}) << endl; // 7

	cout << Solution().largestComponentSize(vector<int>{4, 6, 15, 35}) << endl; // 4
	cout << Solution().largestComponentSize(vector<int>{20, 50, 9, 63}) << endl; // 2
	cout << Solution().largestComponentSize(vector<int>{2, 3, 6, 7, 4, 12, 21, 39}) << endl; // 8

    return 0;
}

