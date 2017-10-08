#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main ()
{
	freopen("INPUT.TXT", "r", stdin);
	freopen("OUTPUT.TXT", "w", stdout);
	int n;
	cin >> n;
	vector <vector <int> > g(n, vector <int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> g[i][j];
	int min = 100000, num = 0;
	for (int k = 0; k < g.size(); ++k)
	{
		for (int i = k + 1; i < g[k].size(); ++i)
		{
			num = g[k][i];
			for (int j = i + 1; j < g[i].size(); ++j)
			{
				num += g[i][j] + g[j][k];
				if (min > num)
					min = num;
				num = g[k][i];
			}
		}
	}
	cout << min;
}