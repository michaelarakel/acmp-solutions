#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;

int length (int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

int minlen (vector <vector <int> >& v, int x, int y)
{
	if (v[x][y] == 1)
		return 0;
	int min = 32665;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (v[i][j] == 1)
				if (min > length(x, y, i, j))
					min = length(x, y, i, j);
	return min;
}

int main ()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	cin >> n >> m;
	vector <vector <int> > v(n, vector <int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << minlen(v, i, j) << " ";
		cout << endl;
	}
}