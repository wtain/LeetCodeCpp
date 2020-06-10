
#include <iostream>
#include <iomanip>

using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) 
	{
		return num > 0 && !(num & (num - 1)) && !(num & 0xAAAAAAAA);
	}
};

int main()
{
	for (int i = 0; i <= 100; ++i)
		if (Solution().isPowerOfFour(i))
			cout << i << " ";
	cout << endl;

    return 0;
}

