
class Solution {
public:
	int getSumImpl(int a, int b) {
		int mask = 1;
		int carry = 0;
		int r = 0;
		do
		{
			int ai = a & mask;
			int bi = b & mask;
			int ri = ai ^ bi ^ carry;
			r |= ri;
			carry = ai & bi | ai & carry | bi & carry;
			mask <<= 1;
			carry <<= 1;
		} while (carry || (b >= mask) || (a >= mask));
		return r;
	}

	int negate(int a)
	{
		return getSumImpl(~a, 1);
	}

	int getSum(int a, int b)
	{
		int c;
		__asm
		{
			mov     eax, a;
			add     eax, b;
			mov		c, eax;
		}
		return c;
	}
};

int main()
{
	Solution().getSum(2, 3);

    return 0;
}

