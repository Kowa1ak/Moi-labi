
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n = 1, a, b, d, c;
	while (n < 99999)
	{
		if (n % 10 )
		{
			a = 0;
			c = 1;
			d = 0;
			b = n;
			while (b >= 1)
			{
				a += (b % 10);
				b /= 10;
			}
			while (n > d)
			{
				d *= a;
			}
			if (d == n)
			{
				cout << n << endl;
			}
		}

		++n;
	}
	return 0;
}