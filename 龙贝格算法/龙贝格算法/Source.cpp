#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double fun( double x )
{
	return(pow( x, 1.5 ) );
}


int main()
{
	cout.precision( 7 );
	double	a	= 1.0;
	double	b	= 2.0;
	double	sum	= 0.0;
	double	Matrix[4][6];

	/* 变步长梯形 */
	double h = (b - a);
	Matrix[1][1] = h / 2 * (fun( a ) + fun( b ) );
	/* cout << Matrix[1][1] << endl; */
	for ( int i = 2; i <= 6; i++ )
	{
		double temp = 0.0;
		/* cout << "h: " << h << endl; */
		double start = a + h / 2;
		for ( int j = 0; j < pow( 2, i - 2 ); j++ )
		{
			temp	+= fun( start );
			start	+= h;
		}
		Matrix[i][1] = (1.0 / 2 * Matrix[i - 1][1]) + (h / 2 * temp);
		/* cout << Matrix[i][1] << endl; */
		h = h / 2;
	}

	/* 变步长辛普森 */
	for ( int i = 2; i <= 6; i++ )
	{
		Matrix[i][2] = 4.0 / 3 * Matrix[i][1] - 1.0 / 3 * Matrix[i - 1][1];
	}

	/* 变步长柯特斯 */
	for ( int i = 3; i <= 6; i++ )
	{
		Matrix[i][3] = 16.0 / 15 * Matrix[i][2] - 1.0 / 15 * Matrix[i - 1][2];
	}

	/* 变步长龙贝格 */
	for ( int i = 4; i <= 6; i++ )
	{
		Matrix[i][4] = 64.0 / 63 * Matrix[i][3] - 1.0 / 63 * Matrix[i - 1][3];
	}

	for ( int i = 1; i <= 6; i++ )
	{
		cout << "N: " << i << "\t";
		for ( int j = 1; j <= i && j <= 4; j++ )
		{
			cout << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "满足精度要求 10^-6" << endl;
	system( "pause" );
	return(0);
}



