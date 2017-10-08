#include <fstream>

using namespace std;

long long gcd (long long a, long long b)
{
	if (a == 0)
		return b;
	gcd(b%a, a);
}

int main ()
{
	ifstream cin ("input.txt");
	ofstream cout ("output.txt");
	long long x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x2 = abs(x1 - x2) ;
	y2 = abs(y1 - y2);
	cout << gcd(x2, y2) + 1 << endl;
}