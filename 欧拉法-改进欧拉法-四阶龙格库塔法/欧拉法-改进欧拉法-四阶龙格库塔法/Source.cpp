#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double h;
	cin >> h;
	double Euler[100];
	double improve_Euler[100];
	double Ronge[100];
	Euler[0] = 0.0;
	improve_Euler[0] = 0.0;
	Ronge[0] = 0.0;

	double x = 0.0;
	cout << "Currect Answer:" << endl;
	for (double x = 0.0; x <= 1.0; x += h)
	{
		cout << "x=" << x << "\t" << x + exp(-x) - 1.0 << endl;
	}

	x = 0.0;
	cout << "Euler:" << endl;
	cout << "x=0\t" << Euler[0] << endl;
	for (int i = 1; x < 1.0-0.0001; i++)
	{
		Euler[i] = Euler[i - 1] + h*(x - Euler[i - 1]);
		cout << "x=" << x + h << "\t" << Euler[i] << endl;
		x += h;
	}

	x = 0.0;
	cout << "Improve_Euler:" << endl;
	cout << "x=0\t" << improve_Euler[0] << endl;
	for (int i = 1; x < 1.0-0.0001; i++)
	{
		double temp = improve_Euler[i - 1] + h*(x - Euler[i - 1]);
		improve_Euler[i] = improve_Euler[i-1] + h / 2 * ((x - Euler[i - 1]) + (x + h - temp));
		cout << "x=" << x + h << "\t" << improve_Euler[i] << endl;
		x += h;
	}

	x = 0.0;
	cout << "Longe:" << endl;
	cout << "x=0\t" << Ronge[0] << endl;
	for (int i = 1; x < 1.0 - 0.0001; i++)
	{
		double k1 = x - Ronge[i - 1];
		double k2 = x + h / 2 - Ronge[i - 1] - h*k1 / 2;
		double k3 = x + h / 2 - Ronge[i - 1] - h*k2 / 2;
		double k4 = x + h - Ronge[i - 1] - h*k3;
		Ronge[i] = Ronge[i - 1] + h*(k1 + 2 * k2 + 2 * k3 + k4) / 6;
		cout << "x=" << x + h << "\t" << Ronge[i] << endl;
		x += h;
	}
	system("pause");
	return 0;
}