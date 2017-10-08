#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main ()
{
	//ifstream cin ("INPUT.TXT");
	//ofstream cout ("OUTPUT.TXT");
	const int INF = 1000 * 1000 * 1000;
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int m;
	cin >> m;
	vector <vector <int> > g(n);
	for (int i = 0; i < m; ++i)
	{
		int node1, node2;
		cin >> node1 >> node2;
		g[node1 - 1].push_back(node2 - 1);
		g[node2 - 1].push_back(node1 - 1);
	}
	vector <int> dist(n, INF);
	dist[0] = v[0];
	set <pair <int, int> > s;
	s.insert(make_pair(v[0], 0));
	while (!s.empty())
	{
		set <pair <int, int> >::iterator it = s.begin();
		int node = it->second;
		s.erase(it);
		for (int i = 0; i < g[node].size(); ++i)
		{
			int curr = g[node][i], len = dist[node] + v[curr];
			if (dist[curr] > len)
			{
				s.erase(make_pair(dist[curr], curr));
				dist[curr] = len;
				s.insert(make_pair(dist[curr], curr));
			}
		}
	}
	if (dist[n - 1] == INF)
		cout << -1;
	else
		cout << dist[n - 1] - v[n - 1];
}