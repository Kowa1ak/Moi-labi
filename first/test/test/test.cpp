
#include <iostream>
using namespace std;
int main()
{
	int b = 100;


	int* a = new int[b + 1];

	for (int i = 0; i <= b; i++)
		a[i] = i;


	for (int i = 2; i * i <= b; i++)
	{
		if (a[i])

			for (int x = i * i; x <= b; x += i)

				a[x] = 0;
	}


	for (int i = 2; i < b; i++)
	{
		if (a[i+2]-a[i]==2)
		{
			cout << "(" << a[i] << ';' << a[i + 2] << ")" << endl;
		}
	}
	return 0;
}





#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


vector<unsigned> getPrimes(unsigned from, unsigned to) {
    vector<unsigned> chislo;
    bool* isprime = new bool[to + 1];
    memset(isprime, 0xFF, to);
    unsigned a = 2;
    for (; a * a <= to; a++) {
        if (isprime[a]) {
            for (unsigned i = a * a; i <= to; i += a) {
                isprime[i] = false;
            }

            if (a > from) {
                chislo.push_back(a);
            }
        }
    }

    a = max(a, from);
    for (; a <= to; a++) {
        if (isprime[a]) {
            chislo.push_back(a);
        }
    }

    return chislo;
}

int main() {
    int diff = 2;
    auto chislo = getPrimes(1, 74);
    for (unsigned i = 0; i < chislo.size() - 1; i++) {
        if (chislo[i + 1] - chislo[i] == 2) {
            cout << "(" << chislo[i] << " ; " << chislo[i + 1] << ")" << endl;
        }
    }

    return 0;
}