#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-6;

struct point 
{
	int x;
	int y;
};

istream& operator >> (istream& input, point& a)
{
	input >> a.x >> a.y;
	return input;
}

point make_point (int x, int y)
{
	point result;
	result.x = x;
	result.y = y;
	return result;
}

double cos_between_vector (const point& v1, const point& v2)
{
	if ( (v1.x == 0 && v1.y == 0) ||
		(v2.x == 0 && v2.y == 0) )
		return -1;
	return (1. * v1.x * v2.x + 1. * v1.y * v2.y) / ( sqrt(v1.x * 1. * v1.x + v1.y * 1. * v1.y) * sqrt(v2.x * 1. * v2.x + v2.y * 1. * v2.y) );
}

struct line 
{
	long long a;
	long long b;
	long long c;
};

line make_line (const point& a, const point& b)
{
	line result;
	result.b = b.x - a.x;
	result.a = a.y - b.y;
	result.c = 1ll * a.x * b.y - 1ll * a.y * b.x;
	return result;
}

int put_in_line (const line& l, const point& p)
{
	long long ans = l.a * p.x + l.b * p.y + l.c;
	if (ans)
		ans /= (abs(ans));
	return ans;
}

struct segment
{
	point A;
	point B;
};

istream& operator >> (istream& input, segment& s)
{
	input >> s.A >> s.B;
	return input;
}

segment make_segment (const point& a, const point& b)
{
	segment result;
	result.A = a;
	result.B = b;
	return result;
}

bool segment_on_line_intersection (const segment& a, const segment& b)
{
	return (fabs(cos_between_vector(make_point(a.A.x - b.A.x,a.A.x - b.A.y), make_point(b.B.x - a.A.x, b.B.y - a.A.y)) + 1) < EPS) ||
		   (fabs(cos_between_vector(make_point(a.B.x - b.A.x,a.B.x - b.A.y), make_point(b.B.x - a.B.x, b.B.y - a.B.y)) + 1) < EPS) ||
		   (fabs(cos_between_vector(make_point(b.A.x - a.A.x,b.A.x - a.A.y), make_point(a.B.x - b.A.x, a.B.y - b.A.y)) + 1) < EPS) ||
		   (fabs(cos_between_vector(make_point(b.B.x - a.A.x,b.B.x - a.A.y), make_point(a.B.x - b.B.x, a.B.y - b.B.y)) + 1) < EPS);
}

bool intersects (const segment& a, const segment& b)
{
	line first = make_line(a.A, a.B),
		second = make_line(b.A, b.B);
	int check_first = put_in_line(first, b.A) * put_in_line(first, b.B),
		check_second = put_in_line(second, a.A) * put_in_line(second, a.B);
	if (check_first > 0 || check_second > 0)
		return false;
	if (check_first == 0 && check_second == 0)
	{
		//if a point C is on segment AB, then angle between vectors CA and BC == 180 deg => cos == -1
		return segment_on_line_intersection(a, b);
	}
	return true;
}

struct rectangle
{
	point bottom_left;
	point bottom_right;
	point top_left;
	point top_right;
};

istream& operator >> (istream& input, rectangle& a)
{
	input >> a.bottom_right >> a.top_left;
	if (a.bottom_right.x > a.top_left.x)
		swap(a.bottom_right, a.top_left);
	a.bottom_left = make_point(a.top_left.x,a.bottom_right.y);
	a.top_right = make_point(a.bottom_right.x, a.top_left.y);
	return input;
}

bool segment_inside_rectangle (const rectangle& r, const segment& s)
{
	segment Ox, Oy, s_Ox, s_Oy;
	Ox = make_segment( make_point( min(r.bottom_left.x, r.bottom_right.x), 0), make_point(max(r.bottom_left.x, r.bottom_right.x), 0) );
	Oy = make_segment( make_point(0, min(r.bottom_left.y, r.top_left.y)), make_point(0, max(r.bottom_left.y, r.top_left.y)) );
	s_Ox = make_segment(make_point(min(s.A.x, s.B.x), 0), make_point(max(s.B.x, s.A.x), 0));
	s_Oy = make_segment(make_point(0, min(s.A.y, s.B.y)), make_point(0, max(s.A.y, s.B.y)));
	return segment_on_line_intersection(Ox, s_Ox) && 
		   segment_on_line_intersection(Oy, s_Oy);
}

int main ()
{
	int case_num;
	cin >> case_num;
	for (int itnum = 0; itnum < case_num; ++itnum)
	{
		segment s;
		rectangle r;
		cin >> s >> r;
		if ( /*intersects(s, make_segment(r.bottom_left, r.top_left)) ||
			 intersects(s, make_segment(r.bottom_left, r.bottom_right)) ||
			 intersects(s, make_segment(r.bottom_right, r.top_right)) ||
			 intersects(s, make_segment(r.top_left, r.top_right)) ||*/
			 segment_inside_rectangle (r, s) )
			 cout << 'T';
		else
			cout << 'F';
		if (itnum != case_num - 1)
			cout << endl;
	}
}