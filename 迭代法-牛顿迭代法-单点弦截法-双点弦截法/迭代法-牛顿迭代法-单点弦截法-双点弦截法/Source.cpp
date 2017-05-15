//�õ�������ţ�ٵ������������ҽط���˫���ҽط���ⷽ��x = e^-x��x = 0.5������һ������Ҫ��ȷ��С�������λ��
//(1) ��ͬһ���������潫�����㷨���ʵ�֣�
//(2) ���Ȧ�Ҫ��Ӽ������룻
//(3) �������㷨��ÿһ��������������ӡ��������������㾫��Ҫ��ķ��̵ĸ���
//(4) ���ݼ�����̣��Ƚ������㷨�������ٶȡ�
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
void iteration()
{
	//������ʽ x2 = e^(-x1)
	double x1 = 0.5;
	double x2 = 0.0;
	double temp = 0.0;
	int count = 0;
	cout << "Easy Iteration:" << endl;
	while (abs(x1 - temp) > 0.5e-5)
	{
		x2 = exp(-x1);
		count++;
		temp = x1;
		x1 = x2;
		cout << "Step :" << count <<" "<< x2 << endl;
		cout << "D-value :" << abs(x1 - temp) << endl;
	}
	cout << "Final Answer: " << setprecision(5) << x2 << endl;
}
void Newton_iteration()
{
	//������ʽ���� x=e^(-x)----> x*e^x-1=0 -----> f(x) = x*e^x-1 ---->f'(x) = e^x + x*e^x
	//x2 = x1 - (x1 - exp(-x1)) / (1 + x1)
	double x1 = 0.5;
	double x2 = 0.0;
	double temp = 0.0;
	int count = 0;
	cout << "Newton's Iteration:" << endl;
	while (abs(x1 - temp) > 0.5e-5)
	{
		x2 = x1 - (x1 - exp(-x1)) / (1 + x1);
		count++;
		temp = x1;
		x1 = x2;
		cout << "Step :" << count << " " << x2 << endl;
		cout << "D-value :" << abs(x1 - temp) << endl;
	}
	cout << "Final Answer: " << setprecision(5) << x2 << endl;
}
int main()
{
	iteration();
	Newton_iteration();
	system("pause");
	return 0;
}