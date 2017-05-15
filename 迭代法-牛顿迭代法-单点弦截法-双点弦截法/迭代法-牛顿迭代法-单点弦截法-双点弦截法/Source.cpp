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
	//�򵥵�����
	//������ʽ: x2 = e^(-x1)
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
	//ţ�ٵ�����
	//������ʽ: x2 = x1 -f(x1)/f'(x1)
	//�� x=e^(-x)----> x*e^x-1=0 -----> f(x) = x*e^x-1 ---->f'(x) = e^x + x*e^x
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
void single_secant()
{
	//�����ҽط�:��ţ�ٵ������е�f'(x)�滻Ϊ�̶���x0�Ͷ���x1֮��ĸ���б��
	//������ʽ: x2 = x1 - f(x1)*(x1 - x0) / (f(x1) - f(x0))
	double x1 = 0.6;
	double x2 = 0.0;
	double temp = 0.0;
	int count = 0;
	cout << "Secant:" << endl;
	while (abs(x1 - temp) > 0.5e-5)
	{
		x2 = x1 - (x1 - exp(-x1))*(x1 - 0.5) / (x1 - 0.5 - exp(-x1) + exp(-0.5));
		count++;
		temp = x1;
		x1 = x2;
		cout << "Step :" << count << " " << x2 << endl;
		cout << "D-value :" << abs(x1 - temp) << endl;
	}
	cout << "Final Answer: " << setprecision(5) << x2 << endl;
}
void double_secant()
{
	//˫���ҽط�: �������ҽط��еĹ̶���x0��Ϊǰһ�μ������x1
	//������ʽ: x2 = x1 - f(x1)*(x1 - x0) / (f(x1) - f(x0))
	double x1 = 0.5;
	double x2 = 0.0;
	double temp = 0.0;
	int count = 0;
	cout << "Secant:" << endl;
	while (abs(x1 - temp) > 0.5e-5)
	{
		x2 = x1 - (x1 - exp(-x1))*(x1 - temp) / (x1 - temp - exp(-x1) + exp(-temp));
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
	single_secant();
	double_secant();
	system("pause");
	return 0;
}