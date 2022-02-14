
#include <iostream>
using namespace std;
int main()
{
	int b = 100;


	int* a = new int[b + 1];

	for (int i = 0; i <= b; i++)
	{
		a[i] = i;
	}


	for (int i = 2; i * i <= b; i++)
	{
		if (a[i])

			for (int x = i * i; x <= b; x += i)

				a[x] = 0;
	}


	for (int i = 2; i < b; i++)
	{
		if (a[i + 2] - a[i] == 2)
		{
			cout << "(" << a[i] << ';' << a[i + 2] << ")" << endl;
		}
	}
	delete[] a;
	return 0;
}