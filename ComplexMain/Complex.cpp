#include "HComplex.h"

int main()
{
	TComplex <double> a(10, 3), d(5, 5), c;
	a *= d;
	cout << a;
	a += d;
	cout << a ;
	a -= d;
	cout << a;
	a /= d;
	cout << a;
	c = d;
	cout << c;
	cout << (c == d) << endl;
	c = a - d;
	cout << c;
	return 0;
}