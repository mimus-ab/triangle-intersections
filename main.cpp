#include "polygon.h"
#include "SVG.h"

int main()
{
	polygon k, l, m, n(3), z(3), o(3), j(3);
	k = polygon(3);
	l = polygon(3);
	m = polygon(3);
	k[0].x = 1;
	k[0].y = 1;
	k[1].x = 3;
	k[1].y = 1;
	k[2].x = 2;
	k[2].y = 2;

	l[0].x = 4;
	l[0].y = 1;
	l[1].x = 6;
	l[1].y = 1;
	l[2].x = 5;
	l[2].y = 2;

	n[0].x = 1.6;
	n[0].y = 1.5;
	n[1].x = 3.6;
	n[1].y = 1.5;
	n[2].x = 2.6;
	n[2].y = 2.5;

	z[0].x = 1.3;
	z[0].y = 1.7;
	z[1].x = 2.7;
	z[1].y = 1.7;
	z[2].x = 2;
	z[2].y = 0.7;

	m[0].x = 2.6;
	m[0].y = 1.2;
	m[1].x = 3.3;
	m[1].y = 1.2;
	m[2].x = 2.9;
	m[2].y = 0.7;

	o[0].x = 1.5;
	o[0].y = 1.2;
	o[1].x = 2.5;
	o[1].y = 1.2;
	o[2].x = 2;
	o[2].y = 1.6;

	j[0].x = 1.5;
	j[0].y = 1.8;
	j[1].x = 2.5;
	j[1].y = 1.8;
	j[2].x = 2;
	j[2].y = 1.5;

	cout << endl << endl;
	cout << n*k << endl;
    PolyToSVG(n,j,n*j,"inter.svg");

}
