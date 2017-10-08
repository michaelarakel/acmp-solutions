#include <iostream>
#include <algorithm>
using namespace std;

void subtract (double** a, int i, int j, int n)
{
	if (a[j][i] == 0)
		return;
	double temp = -a[i][i]/a[j][i];
	for (int k = i; k <= n; ++k)
		a[j][k] = a[j][k] * temp + a[i][k];
}

void round (double& x)
{
	if (x >= 0.)
		x += 0.5;
	else
		x -= 0.5;
}

int main()
{
	int n;
	cin >> n;
	double ** sle = new double* [n];
	for (int i = 0; i < n; ++i)
		sle[i] = new double [n+1];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> sle[i][j];
	double * x = new double[n];
	for (int i = 0; i < n - 1; ++i)
	{
		if (sle[i][i] == 0)
			for (int k = i+1; k < n; ++k)
				if (sle[k][i] != 0)
				{
					swap(sle[i], sle[k]);
					break;
				}
		for (int j = i + 1; j < n; ++j)
			subtract(sle, i, j, n);
	}
	for (int i = n - 1; i >= 0; --i)
	{
		double temp = sle[i][n];
		for (int j = 1; j < n - i; ++j)
			temp -= sle[i][n-j] * x[n-j];
		x[i] = temp/sle[i][i];
	}
	for (int i = 0; i < n; ++i)
		cout << x[i] << " ";
	delete[]x;
	for (int i = 0; i < n; i++)
		delete[]sle[i];

	delete[] sle;
}