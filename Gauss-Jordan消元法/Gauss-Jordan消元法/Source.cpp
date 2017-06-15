#include <stdio.h>
#include <stdlib.h>

void EnterCofficients(double *M[], int);
void ShowSystemEcuations(double *M[], int n);
void gaussJordan(double *M[], int n);

void EnterCofficients(double *M[], int n)
{
	int i, j;

	puts("\n\tEnter the coefficients.");
	for (i = 0; i<n; i++)
	{
		printf("\nEquation %d\n", i + 1);
		for (j = 0; j<n; j++) {
			printf("X%d: ", j + 1);
			scanf("%lf", &M[i][j]);
		}
	}
	puts("\n\tEnter each of the independent terms.");

	for (i = 0; i<n; i++)
	{
		printf("C%d: ", i + 1);
		scanf("%lf", &M[i][n]);
	}
}

void ShowSystemEcuations(double *M[], int n)
{
	int i, j;
	puts("\n\t\tSystem of equations: ");
	for (i = 0; i<n; i++)
	{
		printf("\t\t\t");
		for (j = 0; j<n; j++)
			printf("%c%gx%d\t", M[i][j]>0 ? '+' : 8, M[i][j], j + 1);
		printf("= %g\n", M[i][n]);
	}

	puts("\n\t\tIncreased matrix: ");
	for (i = 0; i<n; i++)
	{
		printf("\t\t\t|");
		for (j = 0; j <= n; j++)
			printf("%3g%c", M[i][j], j == n - 1 ? '|' : 0);

		printf("|\n");
	}
}

void gaussJordan(double *M[], int n)
{
	int i, j, k;
	int pivote = 0;
	double a, coef;

	for (i = 0; i<n; i++)
	{
		a = M[i][pivote];
		//Normalize
		for (j = 0; j <= n; j++)
			M[i][j] = M[i][j] / a;

		for (j = 0; j<n; j++)
		{
			if (j == i)
				continue;
			coef = M[j][pivote];
			for (k = 0; k <= n; k++)
				M[j][k] = M[j][k] - coef*M[i][k];
		}
		pivote++;
	}
}

int main()
{
	double **M;    
	int i, j, n;

	puts("Program for solving a system of simultaneous linear algebraic equations");
	puts("\t\t   By the Gauss-Jordan method");

	do
	{
		printf("\nNumber of equations [2-10]: ");
		scanf("%d", &n);
	} while (n<2 || n>10);

	M = (double**)calloc(n, sizeof(double*));

	for (i = 0; i<n; i++)
		M[i] = (double*)calloc(n + 1, sizeof(double));

	EnterCofficients(M, n);
	ShowSystemEcuations(M, n);
	gaussJordan(M, n);

	puts("\n\n\t\tIdentity Matrix");
	for (i = 0; i<n; i++)
	{
		printf("\t\t\t|");
		for (j = 0; j <= n; j++)
			printf("%5g%c", M[i][j], j == n - 1 ? '|' : 0);

		printf("|\n");
	}

	//这是从github上挖来的代码，原作者为西班牙程序员ErntDev
	//这里有bug，当xi的值恰巧为1时无法输出，但是上面显示的正确，由于最近忙以后再修复
	/*puts("\n\tSystem roots of equations: ");
	for (i = 0; i<n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (M[i][j] != 0 && M[i][j] != 1)
				printf("\tX%d = %lf\n", i + 1, M[i][j]);
		}
	}*/

	system("pause");
	return 0;
}
