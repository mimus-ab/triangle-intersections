#include "polygon.h"
#include <conio.h>
#include <math.h>
#define EPS 0.001

void polygon::push(double x, double y, int NN)
{
	A[NN].x = x;
	A[NN].y = y;
}

polygon::polygon()
{
	A=NULL;
	N=0;
}

polygon::polygon(int n)
{
	A = new point[n];
	N=n;
}

polygon::~polygon()
{
	if (A != NULL) delete[] A;
}

polygon::polygon(const polygon& v)
{
	if (v.A == NULL)
	{
		N=0;
		A=NULL;
		return;
	}
	N = v.N;
	A = new point [N];
	for (int i = 0; i < N; i++) A[i] = v.A[i];
}

polygon& polygon::operator=(const polygon& v)
{
	if (this == &v) return *this;
	if (A != NULL) delete[] A;
	N = v.N;
	A = new point[N];
	for (int i = 0; i < N; i++) A[i] = v.A[i];
	return *this;
}

point& polygon::operator[](int NN)
{
	return A[NN];
}

const point& polygon::operator[](int NN) const
{
	return A[NN];
}

ostream& operator<<(ostream& os, const polygon& v)
{
	if (v.A != NULL)
	{
		for (int i=0; i<v.N;i++)
		{
			os << v.A[i].x << " " << v.A[i].y << endl;
		}
	}
	else os << "polygon does not exist" << endl;
	return os;
}

polygon polygon::operator*(const polygon& v)
{
	cout << endl<< "Start"<< endl;
	polygon z(6);
	double x, y;
	int NN = 0;
	if (N != 3 or v.N !=3) return polygon();

	for (int i1=0; i1<3; i1++)
	{
	for (int i2=0; i2<3; i2++)
	{
	double l1x = A[(i2+1)%3].x - A[i2].x;
	double l1y = A[(i2+1)%3].y - A[i2].y;
	double l2x = v.A[(i1+1)%3].x - v.A[i1].x;
	double l2y= v.A[(i1+1)%3].y - v.A[i1].y;
	double n1x = l1y;
	double n1y = -l1x;
	double n2x = l2y;
	double n2y = -l2x;
	const double d1 = - (A[i2].x*n1x+A[i2].y*n1y);
	const double d2 = - (v.A[i1].x*n2x+v.A[i1].y*n2y);
	const double t1 = n1x*n2y - n1y*n2x;
	if ( fabs ( t1 ) < EPS )
	{
		x = NULL;
		y = NULL;
	}
	else
	{
		double det = t1;
		x = (d2*n1y - d1*n2y)/det;
		y = (d1*n2x - d2*n1x)/det;
		if (!(((min( v.A[i1].x, v.A[(i1+1)%3].x )-EPS) <= x) && (x <= (max( v.A[i1].x, v.A[(i1+1)%3].x )+EPS)) && (min( v.A[i1].y, v.A[(i1+1)%3].y )-EPS) <= y && y <= (max( v.A[i1].y, v.A[(i1+1)%3].y )+EPS)
		&&
			(min( A[i2].x, A[(i2+1)%3].x )-EPS) <= x && (x <= (max( A[i2].x, A[(i2+1)%3].x )+EPS)) && (min( A[i2].y, A[(i2+1)%3].y )-EPS) <= y && y <= (max( A[i2].y, A[(i2+1)%3].y )+EPS)))
		{
			x = NULL;
			y = NULL;
		}
	}
		if (x!=NULL)
	{
		z.push(x,y,NN);
		cout << z;
		NN++;
	}

	}

	}

	int n = 3;

	for (int i3 = 0; i3 < n; i3++)
	{
	int c = 0;
	for ( int i = 0, j = n - 1; i < n; j = i++ )
	 {
		 if ((((v.A[i].y <= A[i3].y) && (A[i3].y < v.A[j].y)) ||
		 ((v.A[j].y <= A[i3].y) && (A[i3].y <v.A[i].y))) &&
		 (A[i3].x < (v.A[j].x - v.A[i].x)*(A[i3].y - v.A[i].y)/
		 (v.A[j].y - v.A[i].y)+v.A[i].x))
		 c = !c;
	 }


	if (c!=0)
	{

		x = A[i3].x;
		y = A[i3].y;
		cout << x << endl;
		cout << y << endl;
	}
	else
	{
		x = NULL;
		y = NULL;
	}

	if (x!=NULL)
	{
		z.push(x,y,NN);
		cout << z;
		NN++;
	}

	}


	for (int i3 = 0; i3 < n; i3++)
	{
	int c = 0;
	for ( int i = 0, j = n - 1; i < n; j = i++ )
	 {
		 if ((((A[i].y <= v.A[i3].y) && (v.A[i3].y < A[j].y)) ||
		 ((A[j].y <= v.A[i3].y) && (v.A[i3].y <A[i].y))) &&
		 (v.A[i3].x < (A[j].x - A[i].x)*(v.A[i3].y - A[i].y)/
		 (A[j].y - A[i].y)+A[i].x))
		 c = !c;
	 }


	if (c!=0)
	{

		x = v.A[i3].x;
		y = v.A[i3].y;
		cout << x << endl;
		cout << y << endl;
	}
	else
	{
		x = NULL;
		y = NULL;
	}

	if (x!=NULL)
	{
		z.push(x,y,NN);
		cout << z;
		NN++;
	}

	}

	cout << "End" << endl;
	return z;
}
