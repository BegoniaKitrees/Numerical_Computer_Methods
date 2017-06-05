#include<iostream>
using namespace std;
void Ronge(double h) {
	double y1 = 1, y2 = 1;
	double i = h;
	double k1, k2, k3, k4;
	double l1, l2, l3, l4;
	while (i <= 2.0+0.0001) {
		k1 = 1 / (y2 - (i - h));
		l1 = -1 / y1 + 1;
		k2 = 1 / (y2 + l1*h / 2 - (i - h + h / 2));
		l2 = -1 / (y1 + k1*h / 2) + 1;
		k3 = 1 / (y2 + l2*h / 2 - (i - h + h / 2));
		l3 = -1 / (y1 + k2*h / 2) + 1;
		k4 = 1 / (y2 + l3*h - (i - h + h));
		l4 = -1 / (y1 + k3*h) + 1;
		y1 = y1 + h*(k1 + 2 * k2 + 2 * k3 + k4) / 6;
		y2 = y2 + h*(l1 + 2 * l2 + 2 * l3 + l4) / 6;
		cout << i << "\t" << y1 << "\t" << y2 << endl;
		i = i + h;
	}
}
int main() {
	double h;
	cin >> h;
	Ronge(h);
	system("pause");
	return 0;
}