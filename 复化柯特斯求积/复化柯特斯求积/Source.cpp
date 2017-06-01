#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	double a = 1.0;
	double b = 2.0;
	double h = (b - a) / n;
	double sum = 0.0;
	for (int k = 0; k < n; k++)
	{
		sum += 32 * (1.0 / (k + 1.0 / 4 + 1));
		sum += 12 * (1.0 / (k + 1.0 / 2 + 1));
		sum += 32 * (1.0 / (k + 3.0 / 4 + 1));
		if (k >= 1) {
			sum += 14 * (1.0 / k);
		}
	}
	sum += 7.0 * (1.0 / a);
	sum += 7.0 * (1.0 / b);
	sum = sum*h / 90.0;
	cout << sum << endl;
	system("pause");
	return 0;
}