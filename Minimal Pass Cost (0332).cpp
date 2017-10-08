#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	const int INF = 1000 * 1000 * 1000;
	int n;
	cin >> n;
	int temp = n;
	vector <vector <pair <int, int> > > g(n + 1);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < temp; ++j)
		{
			int num;
			cin >> num;
			g[i].push_back(make_pair(i + j + 1, num));
		}
		--temp;
	}
	vector <int> dist(n + 1, INF);
	dist[0] = 0;
	set <pair <int, int> > s;
	s.insert(make_pair(0, 0));
	while (!s.empty())
	{
		set <pair <int, int> >::iterator it = s.begin();
		int v = it->second;
		s.erase(it);
		for (int i = 0; i < g[v].size(); ++i)
		{
			int to = g[v][i].first, len = g[v][i].second;
			if (dist[to] > dist[v] + len)
			{
				s.erase(make_pair(dist[to], to));
				dist[to] = dist[v] + len;
				s.insert(make_pair(dist[to], to));
			}
		}
	}
	cout << dist[n];
}