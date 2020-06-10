
#include <iostream>
#include <vector>
#include <string>

int SeekString(const std::vector<std::string>& strings, int idx, int delta = 1)
{
	while (idx < strings.size()-1 && idx > 0 && strings[idx].empty())
		idx += delta;
	return idx;
}

int FindString(const std::vector<std::string>& strings, const std::string& str)
{
	int l = 0, r = strings.size() - 1;
	l = SeekString(strings, l);
	r = SeekString(strings, r, -1);
	while (l <= r)
	{
		int m = (l + r) / 2;
		m = SeekString(strings, m);
		if (m > r)
			m = r;
		if (strings[m] < str)
			l = m + 1;
		else if (strings[m] >= str)
			r = m - 1;
	}
	if (strings[l] == str)
		return l;
	return -1;
}

int main()
{
	std::vector<std::string> strings = { "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", "" };

	std::cout << FindString(strings, "ball") << std::endl;
	std::cout << FindString(strings, "ballcar") << std::endl;

    return 0;
}

