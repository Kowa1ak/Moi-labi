#include <iostream>
#include <ctime>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    double x, res1, ans, ansN, n;
    cout << "First";
    cin >> n;
    cout << "second:" << fixed << setprecision(n) << pow(10, -n);
    srand(time(NULL));
    x = rand() - (RAND_MAX / 2);
    x /= RAND_MAX;


    double prelog = x + sqrt(1 + x * x);
    res1 = log(prelog);

    ansN = (-1) * x * 9 / 20 * x * x;
    ans = x + ansN;

    double i = 2;
    while (fabs(ansN) >= 2 * pow(10, -n)) {
        ansN = (-1) * ansN * (((2 * i + 1) * (2 * i + 1)) / (4 * i * i + 10 * i + 6)) * x * x;
        ans += ansN;
        i++;
    }
    cout << " Teilor" << setprecision(n) << ans;
    cout << "standart " << setprecision(n) << res1;
    
    return 0;
}


