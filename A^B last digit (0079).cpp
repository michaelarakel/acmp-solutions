#include <iostream>

using namespace std;

int binary_pow (int n, int k)
{
	if (k == 0)
		return 1;
	if (k & 1)
		return ((n % 10) * (binary_pow(n, k - 1) % 10)) % 10;
	int temp = binary_pow(n, k/2) % 10;
	return (temp * temp) % 10;
}

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	int n, p;
	cin >> n >> p;
	cout << binary_pow(n, p);
}