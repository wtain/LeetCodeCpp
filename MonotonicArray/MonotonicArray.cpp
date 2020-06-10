
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMonotonic(vector<int>& A) 
	{
		int n = A.size();
		if (n <= 2)
			return true;
		int d1 = A[1] - A[0];
		for (int i = 2; i < n; ++i)
		{
			int d = A[i] - A[i - 1];
			if (!d1)
				d1 = d;
			if (d1 * d < 0)
				return false;
		}
		return true;
	}
};

int main()
{
	vector<int> v1 = { 1,2,2,3 };
	vector<int> v2 = { 6,5,4,4 };
	vector<int> v3 = { 1,3,2 };
	vector<int> v4 = { 1,2,4,5 };
	vector<int> v5 = { 1,1,1 };

	vector<int> v6 = { 1,1 };
	vector<int> v7 = { 1 };

	vector<int> v8 = { 2, 2, 2, 1, 4, 5 };

	cout << boolalpha << Solution().isMonotonic(v1) << endl; // true
	cout << boolalpha << Solution().isMonotonic(v2) << endl; // true
	cout << boolalpha << Solution().isMonotonic(v3) << endl; // false
	cout << boolalpha << Solution().isMonotonic(v4) << endl; // true
	cout << boolalpha << Solution().isMonotonic(v5) << endl; // true

	cout << boolalpha << Solution().isMonotonic(v6) << endl; // true
	cout << boolalpha << Solution().isMonotonic(v7) << endl; // true

	cout << boolalpha << Solution().isMonotonic(v8) << endl; // false

    return 0;
}

