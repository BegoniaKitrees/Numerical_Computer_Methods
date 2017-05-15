//用二分法求方程x5 + 3x - 1 = 0在[0, 1]的根，要求准确到1 / 2×10 - 2。
//要求：
//(1) 对该区间使用二分法求方程的满足精度要求的根，每二分一次，用新生成区间长度的一半作为是否二分结束的判断条件；
//(2) 要求精度ε从键盘输入；
//(3) 将二分法求方程根的实现过程用算法框图进行描述；
//(4) 输出每一次二分过程所得到的区间端点ak、bk以及区间中点xk的信息，最后打印输出满足精度要求的方程根的近似值。

#include<iostream>
#include<math.h>
using namespace std;
double Operation(double x)
{
	return x*x*x*x*x + 3 * x - 1;
}
int main()
{
	double a, b, c, x;
	int count = 1;
	cin >> a >> b >> c;
	while (fabs(a - b) >= c)
	{
		cout << "Temp D-value: " << fabs(a - b) << endl;
		x = (a + b) / 2;
		if (Operation(a)*Operation(x) < 0)
		{
			b = x;
		}
		else {
			a = x;
		}
		cout << "Step:" << count << " ";
		cout << "Answer is:" << x << endl;
		count++;
	}
	cout << "Final D-value: " << fabs(a - b) << endl;
	cout << "Final answer is:" << x << endl;
	system("pause");
	return 0;
}