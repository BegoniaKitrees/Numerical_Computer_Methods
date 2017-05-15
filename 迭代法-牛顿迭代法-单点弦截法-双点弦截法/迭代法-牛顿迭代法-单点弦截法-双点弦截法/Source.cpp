//用迭代法、牛顿迭代法、单点弦截法和双点弦截法求解方程x = e^-x在x = 0.5附近的一个根，要求精确到小数点后五位。
//(1) 在同一个程序里面将四种算法编程实现；
//(2) 精度ε要求从键盘输入；
//(3) 将四种算法的每一步迭代计算结果打印输出，最后输出满足精度要求的方程的根；
//(4) 根据计算过程，比较四种算法的收敛速度。
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
void iteration()
{
	//迭代公式 x2 = e^(-x1)
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
	//迭代公式：由 x=e^(-x)----> x*e^x-1=0 -----> f(x) = x*e^x-1 ---->f'(x) = e^x + x*e^x
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