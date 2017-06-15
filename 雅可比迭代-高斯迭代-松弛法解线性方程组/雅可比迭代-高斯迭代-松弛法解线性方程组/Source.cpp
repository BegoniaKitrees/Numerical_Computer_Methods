#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
bool check(double* j,double* t, double top)
{
	bool flag = false;
	for (int i = 1; i <= 4; i++)
	{
		if (abs(j[i]-t[i]) > top)
		{
			flag = true;
		}
	}
	return flag;
}
int main()
{
	cout.precision(7);
	double top;
	cin >> top;
	cout << "Jacobi:" << endl;
	double jacobi[100] = { 0 };
	double temp[100];
	int count = 1;
	do {
		temp[1] = jacobi[1];
		temp[2] = jacobi[2];
		temp[3] = jacobi[3];
		temp[4] = jacobi[4];
		jacobi[1] = 1.0 / 4.0*(temp[2] + temp[3]);
		jacobi[2] = 1.0 / 4.0*(temp[1] + temp[4]);
		jacobi[3] = 1.0 / 4.0*(1 + temp[1] + temp[4]);
		jacobi[4] = 1.0 / 4.0*(1 + temp[2] + temp[3]);
		cout << "step: " << count << "\t\t" << jacobi[1] << "\t" << jacobi[2] << "\t" << jacobi[3] << "\t" << jacobi[4] << endl;
		count++;
	} while (check(jacobi, temp, top));

	cout << "Gauss:" << endl;
	count = 1;
	double gauss[100] = { 0 };
	do {
		temp[1] = gauss[1];
		temp[2] = gauss[2];
		temp[3] = gauss[3];
		temp[4] = gauss[4];
		gauss[1] = 1.0 / 4.0*(gauss[2] + gauss[3]);
		gauss[2] = 1.0 / 4.0*(gauss[1] + gauss[4]);
		gauss[3] = 1.0 / 4.0*(1 + gauss[1] + gauss[4]);
		gauss[4] = 1.0 / 4.0*(1 + gauss[2] + gauss[3]);
		cout << "step: " << count << "\t\t" << gauss[1] << "\t" << gauss[2] << "\t" << gauss[3] << "\t" << gauss[4] << endl;
		count++;
	} while (check(gauss, temp, top));

	cout << "Relaxation:" << endl;
	for (int i = 0; i < 3; i++)
	{
		double w;
		cin >> w;
		count = 1;
		double relaxation[100] = { 0 };
		do {
			/*temp[1] = relaxation[1];
			temp[2] = relaxation[2];
			temp[3] = relaxation[3];
			temp[4] = relaxation[4];
			relaxation[1] = 1.0 / 4.0*(relaxation[2] + relaxation[3]);
			relaxation[1] = relaxation[1] * w + temp[1] * (1 - w);
			relaxation[2] = 1.0 / 4.0*(relaxation[1] + relaxation[4]);
			relaxation[2] = relaxation[2] * w + temp[2] * (1 - w);
			relaxation[3] = 1.0 / 4.0*(1 + relaxation[1] + relaxation[4]);
			relaxation[3] = relaxation[3] * w + temp[3] * (1 - w);
			relaxation[4] = 1.0 / 4.0*(1 + relaxation[2] + relaxation[3]);
			relaxation[4] = relaxation[4] * w + temp[4] * (1 - w);*/
			temp[1] = relaxation[1];
			temp[2] = relaxation[2];
			temp[3] = relaxation[3];
			temp[4] = relaxation[4];
			relaxation[1] = relaxation[1] + w / 4.0 *(-4 * relaxation[1] + relaxation[2] + relaxation[3]);
			relaxation[2] = relaxation[2] + w / 4.0*(relaxation[1] - 4 * relaxation[2] + relaxation[4]);
			relaxation[3] = relaxation[3] + w / 4.0*(1 + relaxation[1] - 4 * relaxation[3] + relaxation[4]);
			relaxation[4] = relaxation[4] + w / 4.0*(1 + relaxation[2] + relaxation[3] - 4 * relaxation[4]);
			cout << "step: " << count << "\t\t" << relaxation[1] << "\t" << relaxation[2] << "\t" << relaxation[3] << "\t" << relaxation[4] << endl;
			count++;
		} while (check(relaxation, temp, top));
	}
	system("pause");
	return 0;
} 