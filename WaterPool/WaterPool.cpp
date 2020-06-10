
#include <iostream>

#include <vector>

int GetVolume(const std::vector<int>& h)
{
	size_t l = 0, r = h.size() - 1;
	int lmax = 0, rmax = 0;

	int v = 0;
	
	while (l < r)
	{
		if (h[l] > lmax)
			lmax = h[l];
		if (h[r] > rmax)
			rmax = h[r];
		if (lmax >= rmax)
		{
			v += rmax - h[r];
			r--;
		}
		if (rmax >= lmax)
		{
			v += lmax - h[l];
			l++;
		}
	}
	return v;
}

int main()
{
	std::vector<int> h = {1, 2, 3, 2, 1, 3, 4, 5, 1, 2, 3, 4, 1, 2, 3, 4};

	std::cout << GetVolume(h) << std::endl;

    return 0;
}

