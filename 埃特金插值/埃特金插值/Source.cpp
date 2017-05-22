#include<iostream>
#define MAX 20
#include<iomanip>
using namespace std;
int main()
{
	int num, i, j;
	double point;
	double MATRIX[MAX][MAX];
	cout << "Input the number of DATA: ";
	cin >> num;
	cout << "INPUT xi: " << endl;
	for (i = 0; i<num; i++)
		cin >> MATRIX[i][0];
	cout << "INPUT yi: " << endl;
	for (i = 0; i<num; i++)
		cin >> MATRIX[i][1];
	cout << "Input the point to calculate: ";
	cin >> point;
	for (j = 2; j <= num; j++)
		for (i = j - 1; i <= num - 1; i++)
			MATRIX[i][j] = MATRIX[j - 2][j - 1] + (MATRIX[i][j - 1] - MATRIX[j - 2][j - 1]) / (MATRIX[i][0] -MATRIX[j - 2][0])*(point - MATRIX[j - 2][0]);
	for (i = 0; i <= num - 1; i++)
	{
		for (j = 0; j <= i + 1; j++)
			cout << setprecision(5) << MATRIX[i][j] << "   ";
		cout << endl;
	}
	system("pause");
	return 0;
}
