#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("INPUT.TXT");
ofstream out("OUTPUT.TXT");

struct frac
{
	double num;
	int den;
};

ostream& operator << (ostream& out, const frac& a)
{
	out << a.num << '/' << a.den;
	return out;
}

bool operator < (const frac& a, const frac& b)
{
	return ((a.num/a.den) < (b.num/b.den));
}

int GCD(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a > b)
		return GCD(a % b, b);
	if (a < b)
		return GCD (a, b % a);
}

int main ()
{
	int n, k = 0;
	in >> n;
	frac fractions[20000];
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (GCD (i, j) == 1)
			{
				fractions[k].den = i;
				fractions[k].num = j;
				++k;
			}
	sort (fractions, fractions + k);
	for (int i = 0; i < k; i++)
		out << fractions[i] << endl;
}