#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	int n;
	cin >> n;
	vector <vector <char> > v(n, vector <char>(n));
	pair <int, int> start, end;
	bool Start = true;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == '@')
			{
				if (Start)
				{
					start = make_pair(i, j);
					Start = false;
				}
				else
				{
					v[i][j] = '*';
					end = make_pair(i, j);
				}
			}
		}
	deque <pair <int, int> > d;
	vector < vector <pair <int, int> > > pre(n, vector <pair <int, int> >(n));
	d.push_back(start);
	while (!d.empty())
	{
		pair <int, int> node = d[0];
		d.pop_front();
		const int a[] = {-1, -1, -2, -2, 1, 1, 2, 2},
				  b[] = {-2, 2, -1, 1, -2, 2, -1, 1};
		for (int i = 0; i < 8; ++i)
		{
			int x = node.first + a[i],
				y = node.second + b[i];
			if ((x >= 0 && x < n && y >= 0 && y < n) &&
				(v[x][y] == '.' || v[x][y] == '*'))
			{
				v[x][y] = 't';
				pre[x][y] = node;
				d.push_back(make_pair(x, y));
			}
		}
	}
	if (v[end.first][end.second] == '*')
	{
		cout << "Impossible";
		return 0;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n ; ++j)
			if (v[i][j] == 't')
				v[i][j] = '.';
	for (pair <int, int> i = end; i != start; i = pre[i.first][i.second])
		v[i.first][i.second] = '@';
	v[start.first][start.second] = '@';
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << v[i][j];
		cout << endl;
	}
}