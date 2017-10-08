#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

const int INF = 1000 * 1000 * 1000;

using namespace std;

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	int n, start, end;
	cin >> n >> start >> end;
	start -= 1;
	end -= 1;
	vector <vector <pair <int, int> > > g(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int num;
			cin >> num;
			if (num >= 0 && i != j)
				g[i].push_back(make_pair(j, num));
		}
	set <pair <int, int> > s;
	vector <int> dist(n, INF);
	dist[start] = 0;
	s.insert(make_pair(0, start));
	while (!s.empty())
	{
		set <pair <int, int> >::iterator it = s.begin();
		int v = (*it).second;
		s.erase(it);
		for (int i = 0; i < g[v].size(); ++i)
		{
			int to = g[v][i].first, len = g[v][i].second;
			if (dist[v] + len < dist[to])
			{
				s.erase(make_pair(dist[to], to));
				dist[to] = dist[v] + len;
				s.insert(make_pair(dist[to], to));
			}
		}
	}
	if (dist[end] != INF)
		cout << dist[end];
	else
		cout << -1;
}