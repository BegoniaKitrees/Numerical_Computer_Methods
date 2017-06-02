#include<iostream>
using namespace std;
double fun(double x)
{
	if (x != 0) {
		return 1.0 / x;
	}
}
int main()
{
	int n;
	cin >> n;
	double a = 1.0;
	double b = 2.0;
	double h = (double)(b - a) / n;
	cout << "h: " << h << endl;
	double sum = 0.0;
	double k = a;
	for (int i = 0; i <= n - 1; i++)
	{
		cout << "K: " << k << endl;
		sum += 32 * fun(k + 0.25*h);
		sum += 12 * fun(k + 0.5*h);
		sum += 32 * fun(k + 0.75*h);
		if (k > a) {
			sum += 14 * fun(k);
		}
		k += h;
	}
	sum = sum + (7.0 * (1.0 / a));
	sum = sum + (7.0 * (1.0 / b));
	sum = sum*h;
	sum = sum / 90;
	cout << sum << endl;
	system("pause");
	return 0;
}