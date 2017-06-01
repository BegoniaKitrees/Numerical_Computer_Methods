#include<iostream>
#include<math.h>
float f(float x)
{	
	float y;
	y = exp(-x*x);
	return(y);
}
int main()
{
	float a, b, h, x, R, eps, S, T[20];
	int i, j, m = 2, g;
	printf("\ninput a,b,eps:\n");
	scanf("%f,%f,%f", &a, &b, &eps);
	printf("a=%f,b=%f,eps=%f\n", a, b, eps);
	h = b - a;
	T[1] = h*(f(a) + f(b)) / 2;
	T[2] = (T[1] + h*f(a + h / 2)) / 2;
	T[1] = (4 * T[2] - T[1]) / 3;
	for (i = 2; i <= 3; i++)
	{
		S = 0;
		for (j = 1; j <= 2 * m - 1; j = j + 2)
		{
			x = a + j*h / m / 2;
			S = S + f(x);
		}
		T[i + 1] = (T[i] + h*S / m) / 2;
		g = 1;
		for (j = i; j >= 1; j--)
		{
			g = 4 * g;
			T[j] = (T[j + 1] * g - T[j]) / (g - 1);
		}
		m = 2 * m;
	}
	R = T[1];
	for (i = 4; ; i++)
	{
		S = 0;
		for (j = 1; j <= 2 * m - 1; j = j + 2)
		{
			x = a + j*h / m / 2;
			S = S + f(x);
		}
		T[i + 1] = (T[i] + h*S / m) / 2;
		g = 1;
		for (j = i; j >= i - 2; j--)
		{
			g = 4 * g;
			T[j] = (T[j + 1] * g - T[j]) / (g - 1);
		}
		if (fabs(T[i - 2] - R)<eps)break;
		m = 2 * m;
		R = T[i - 2];
	}
	printf("I=%f\n", T[i - 2]);
}