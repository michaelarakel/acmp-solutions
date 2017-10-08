#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct point
{
	int x;
	int y;
};

struct line
{
	long long a;
	long long b;
	long long c;
};

istream& operator >> (istream& input, point& a)
{
	input >> a.x >> a.y;
	return input;
}

bool operator || (const line&a, const line& b)
{
	return (a.a * b.b == a.b * b.a);
}

bool operator == (const line&a, const line& b)
{
	return ((a || b) && (a.a * b.c == b.a * a.c) && (a.b * b.c == b.a * a.c));
}

line make_line (point a, point b)
{
	line result;
	result.a = a.y - b.y;
	result.b = b.x - a.x;
	result.c = a.x * 1ll * b.y - a.y * 1ll * b.x;
	return result;
}

int main ()
{
	const double EPS = 0.001;
	int cases;
	cin >> cases;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	for (int itnum = 0; itnum < cases; ++itnum)
	{
		point a, b, c, d;
		cin >> a >> b >> c >> d;
		line l1, l2;
		l1 = make_line(a, b);
		l2 = make_line(c, d);
		if (l1 == l2)
			cout << "LINE";
		else if (l1 || l2)
			cout << "NONE";
		else
		{
			double x, y;
			double det = 1. * l1.a * l2.b - 1. * l1.b * l2.a;
			x = (-1. * l1.c * l2.b + l2.c * l1.b )/ (det);//using Cramer's method (if we create a sle of our equations)
			y = (-1. * l2.c * l1.a + l1.c * l2.a)/ (det);
			cout << "POINT " << x << " " << y;
		}
		cout << endl;
	}
	cout << "END OF OUTPUT" << endl;
}