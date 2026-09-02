#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
using namespace std;

struct point
{
	double x, y;
};

class polygon
{
	private:
	point *A;
	int N;
	public:
	polygon();
	polygon(int n);
	polygon(const polygon&);
	~polygon();
	polygon& operator=(const polygon&);
	point& operator[] (int);
	const point& operator[] (int) const;
	int size() const { return N; }
	friend ostream& operator<<(ostream&, const polygon&);
	polygon operator*(const polygon&);
	void push(double, double, int);

};

#endif
