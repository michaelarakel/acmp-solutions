#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int INF = 1000 * 1000 * 1000;

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	int n, start, end;
	cin >> n >> start >> end;
	vector <vector <pair <int, int> > > g(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int num;
			cin >> num;
			if (num >= 0 && i != j)
				g[i].push_back(make_pair(j, num));
		}
	start -= 1;
	end -= 1;
	vector <char> used(n);
	vector <int> dist(n, INF);
	dist[start] = 0;
	for (int i = 0; i < n; ++i)
	{
		int v = -1;
		for (int j = 0; j < n; ++j)
		{
			if (!used[j] && (v == -1 || dist[j] < dist[v]))
				v = j;
		}
		used[v] = true;
		for (int j = 0; j < g[v].size(); ++j)
		{
			int end = g[v][j].first, len = g[v][j].second;
			dist[end] = min(dist[end], dist[v] + len);
		}
	}
	if (dist[end] != INF)
		cout << dist[end];
	else
		cout << -1;
}