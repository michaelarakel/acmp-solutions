#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <functional>

using namespace std;

const int INF = 1000 * 1000 * 1000;

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n, vector <int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> g[i][j];

	priority_queue <pair <int, pair<int, int> >, vector <pair <int, pair<int, int> > >, greater <pair <int, pair<int, int> > > > s;
	vector <vector <int> > d(n, vector <int>(m, INF)); 
	d[0][0] = g[0][0];

	const int a[] = {1, -1, 0, 0};
	const int b[] = {0, 0, -1, 1};

	s.push(make_pair(d[0][0], make_pair(0, 0)));
	while (!s.empty())
	{
		int len = s.top().first;
		pair <int, int> v = s.top().second;
		s.pop();
		if (len > d[v.first][v.second])
			continue;
		for (int i = 0; i < 4; ++i)
			if (v.first + a[i] >= 0 && v.first + a[i] < n &&
				v.second + b[i] >= 0 && v.second + b[i] < m)
				if (d[v.first + a[i]][v.second + b[i]] > len + g[v.first + a[i]][v.second + b[i]])
				{
					d[v.first + a[i]][v.second + b[i]] = len + g[v.first + a[i]][v.second + b[i]];
					s.push(make_pair(d[v.first + a[i]][v.second + b[i]], make_pair(v.first + a[i], v.second + b[i])));
				}
	}
	cout << d[n - 1][m - 1];
}