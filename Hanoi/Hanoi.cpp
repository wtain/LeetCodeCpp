
#include <iostream>

int Move(int i1, int i2)
{
	std::cout << i1 << " -> " << i2 << std::endl;
	return 1;
}

int MoveTower(int N, int i1, int i2, int i3)
{
	if (N == 1)
		return Move(i1, i3);
	int n = MoveTower(N - 1, i1, i3, i2);
	n += Move(i1, i3);
	n += MoveTower(N - 1, i2, i1, i3);
	return n;
}

int SolveHanoi(int N)
{
	return MoveTower(N, 1, 2, 3);
}

int main()
{
	int n = SolveHanoi(15);
	std::cout << "Total: " << n << std::endl;
    return 0;
}

