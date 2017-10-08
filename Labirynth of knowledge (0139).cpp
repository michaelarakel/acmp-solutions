#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

#define edge pair <int, pair <int, int> >

const int INF = 1000 * 1000 * 1000;

using namespace std;

void dfs (const vector <vector <int> >& g, vector <char>& used, const int node, vector <int>& connected)
{
	used[node] = true;
	connected.push_back(node);
	for (int i = 0; i < g[node].size(); ++i)
		if (!used[g[node][i]])
			dfs(g, used, g[node][i], connected);
}

int main ()
{
	//freopen ("INPUT.TXT", "r", stdin);
	//freopen ("OUTPUT.TXT", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <edge> g;
	vector <vector <int> > graph(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[b - 1].push_back(a - 1);
		g.push_back(make_pair(-c, make_pair(a - 1, b - 1)));
	}
	vector <int> d(n, INF);
	d[0] = 0;
	vector <int> changed;
	for (int i = 0; i < n; ++i)
	{
		bool any_change = false;
		for (int j = 0; j < m; ++j)
		{
			if (d[g[j].second.first] < INF)
			{
				if (d[g[j].second.second] > (d[g[j].second.first] + g[j].first))
				{
					d[g[j].second.second] = (d[g[j].second.first] + g[j].first);
					any_change = true;
					if (i == n - 1)
						changed.push_back(g[j].second.second);
				}
			}
		}
		if (!any_change)
			break;
		if (i == n - 1)
		{
			vector <char> used(n);
			vector <int> connected;
			dfs(graph, used, n - 1, connected);
			vector <int> end;
			sort(changed.begin(), changed.end());
			sort(connected.begin(), connected.end());
			set_intersection(changed.begin(), changed.end(), connected.begin(), connected.end(), back_inserter(end));
			if (end.size() != 0)
			{
				cout << ":)";
				return 0;
			}
		}
	}
	if (d[n - 1] == INF)
		cout << ":(";
	else
		cout << -d[n - 1];
}