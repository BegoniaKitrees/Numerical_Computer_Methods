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
	for (i = 0; i < num; i++)
		cin >> MATRIX[i][0];
	cout << "INPUT yi: " << endl;
	for (i = 0; i < num; i++)
		cin >> MATRIX[i][1];
	cout << "Input the point to calculate: " << endl;
	cin >> point;
	double t1 = MATRIX[0][0];
	double t2 = MATRIX[1][0];
	double t3 = MATRIX[2][0];
	double y1 = MATRIX[0][1];
	double y2 = MATRIX[1][1];
	double y3 = MATRIX[2][1];
	//确定插值点
	for (i = 1; i <= num - 2; i++)
	{
		if (point > MATRIX[i][0])
		{
			if (abs(point - MATRIX[i][0]) < abs(point - MATRIX[i + 1][0]))
			{
				t1 = MATRIX[i - 1][0];
				t2 = MATRIX[i][0];
				t3 = MATRIX[i + 1][0];
				y1 = MATRIX[i - 1][1];
				y2 = MATRIX[i][1];
				y3 = MATRIX[i + 1][1];
			}
			else
			{
				t1 = MATRIX[i][0];
				t2 = MATRIX[i + 1][0];
				t3 = MATRIX[i + 2][0];
				y1 = MATRIX[i][1];
				y2 = MATRIX[i + 1][1];
				y3 = MATRIX[i + 2][1];
			}
		}
	}
	cout << "Insert Point One: " << t1 << " " << y1 << endl;
	cout << "Insert Point Two: " << t2 << " " << y2 << endl;
	cout << "Insert Point Three: " << t3 << " " << y3 << endl;
	//函数计算
	double answer = ((point - t2)*(point - t3)*y1) / ((t1 - t2) * (t1 - t3))
		+ ((point - t1)*(point - t3)*y2) / ((t2 - t1) * (t2 - t3))
		+ ((point - t1)*(point - t2)*y3) / ((t3 - t1) * (t3 - t2));
	cout << "Answer is: " << answer << endl;
	system("pause");
	return 0;
}
