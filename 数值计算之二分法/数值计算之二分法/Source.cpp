//�ö��ַ��󷽳�x5 + 3x - 1 = 0��[0, 1]�ĸ���Ҫ��׼ȷ��1 / 2��10 - 2��
//Ҫ��
//(1) �Ը�����ʹ�ö��ַ��󷽳̵����㾫��Ҫ��ĸ���ÿ����һ�Σ������������䳤�ȵ�һ����Ϊ�Ƿ���ֽ������ж�������
//(2) Ҫ�󾫶ȦŴӼ������룻
//(3) �����ַ��󷽳̸���ʵ�ֹ������㷨��ͼ����������
//(4) ���ÿһ�ζ��ֹ������õ�������˵�ak��bk�Լ������е�xk����Ϣ������ӡ������㾫��Ҫ��ķ��̸��Ľ���ֵ��

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