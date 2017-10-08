#include <iostream>
#include <cstdio>

using namespace std;

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	int x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	if (((x1 - r1 < x2 - r2 && x2 + r2 < x1 + r1) &&
		(y1 - r1 < y2 - r2 && y2 + r2 < y1 + r1)) ||
		((x2 - r2 < x1 - r1 && x1 + r1 < x2 + r2) &&
		(y2 - r2 < y1 - r1 && y1 + r1 < y2 + r2)) ||
		(x1 + r1 < x2 - r2) || (x2 + r2 < x1 - r1) ||
		(y1 + r1 < y2 - r2) || (y2 + r2 < y1 - r1))
		cout << "NO";
	else
		cout << "YES";
}