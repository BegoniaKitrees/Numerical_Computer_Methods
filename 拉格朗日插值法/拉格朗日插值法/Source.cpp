#include<iostream>
#include<math.h>
using namespace std;
void Lagrange_interpolation(double x, int n)
{
	double xi[6] = {
		0.4,0.55,0.65,0.80,0.90,1.05
	};
	double yi[6] = {
		0.41075,0.57815,0.69675,0.88811,1.02652,1.25382
	};
	double queue[4];
	queue[0] = xi[0];
	queue[1] = xi[1];
	queue[2] = xi[2];
	queue[3] = xi[3];
	double y0 = yi[0];
	double y1 = yi[1];
	double y2 = yi[2];
	double y3 = yi[3];
	int station = 0;
	for (int i = 0; i < 6; i++)
	{
		if (x > xi[i])
		{
			station = i;
		}
	}
	if (station ==3)
	{
		queue[0] = xi[station - 1];
		queue[1] = xi[station];
		queue[2] = xi[station + 1];
		queue[3] = xi[station + 2];
	}
	if (station > 3)
	{
		queue[0] = xi[2];
		queue[1] = xi[3];
		queue[2] = xi[4];
		queue[3] = xi[5];
	}
	cout << "CHOOSED POINT: " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << queue[i] << " ";
	}
	cout << endl;
	double Fx = ((x - queue[1])*(x - queue[2])*(x - queue[3])) / ((queue[0] - queue[1])*(queue[0] - queue[2])*(queue[0] - queue[3]))*y0;
	Fx += ((x - queue[0])*(x - queue[2])*(x - queue[3])) / ((queue[1] - queue[0])*(queue[1] - queue[2])*(queue[1] - queue[3]))*y1;
	Fx += ((x - queue[0])*(x - queue[1])*(x - queue[3])) / ((queue[2] - queue[0])*(queue[2] - queue[1])*(queue[2] - queue[3]))*y2;
	Fx += ((x - queue[0])*(x - queue[1])*(x - queue[2])) / ((queue[3] - queue[0])*(queue[3] - queue[1])*(queue[3] - queue[2]))*y3;
	cout << Fx << endl;
}
int main()
{
	int n;
	double x;
	cout << "n: x: ";
	cin >> n >> x;
	Lagrange_interpolation(x, n);
	system("pause");
	return 0;
}