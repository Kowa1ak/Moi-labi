#include <iostream>
#include <ctime>
#include <math.h>
#include <iomanip>
using namespace std;





int main(){

	int t;
	cout << "enter accuracy: ";
	cin >> t;
	double x,h,an, sum ,step=pow(10, -t);
	
	cout << fixed << setprecision(t) ;
	cout << "enter accuracy: ";
	cin >> t;
	srand(time(null));
	x = rand() - (rand_max / 2);
	x /= rand_max;
	
	sum = +x;
	an = x;

	int m = 2;

	while (abs(an) >= 2 * step){

		h = (x * x - 2 * m * x * x) / (2 * m + 1);
		an *= (-1)*(h);
		sum += h;
		m++;
		
	}
	cout << "function: "  << atan(x) <<  endl;
	cout << "taylor: "  << sum;
	return 0;
}



 // x=-(2m+1)/(2x*x*m-x*x)
// atan(X)
//pow (x, y)
//double sum = x;
//double current = x;
//do {
	//i++;
	//current *= x; y= y*x
	//current *= -1; 
	//sum += current / i;

//} while (abs(current / i) >= N);
//cout << log(x + 1) << "and" << sum;


//double x = 1;// ((-1)^0)/0! = 1 : первое слагаемое
//double sum = 1;// При любой точности сумма начинается с первого члена
//for (int i = 1; abs(x) > E; i++) { // Цикл подсчета суммы пока слагаемое больше точности
//	x = -x / i; // С каждым действием знак меняется на противоположный
//	sum += x;
//}











