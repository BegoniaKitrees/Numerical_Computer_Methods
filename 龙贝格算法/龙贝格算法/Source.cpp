#include<iostream>
#include<math.h>
using namespace std;
double fun(double x)
{
	return pow(x, 1.5);
}
int main()
{
	double T[6];
	double S[6];
	double C[6];
	double R[6];
	double a = 1.0;
	double b = 2.0;
	double h = b - a;
	cout << "h: " << h << endl;
	T[1] = h / 2 * (fun(a) + fun(b));
	double sum = 0;
	system("pause");
	return 0;
}