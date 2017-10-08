#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void bfs (const vector <vector <int> >& v, vector <char>& used)
{
	deque <int> d(1, 0);
	used[0] = true;
	while (!d.empty())
	{
		int node = d[0];
		d.pop_front();
		for (int i = 0; i < v[node].size(); i++)
			if (!used[v[node][i]])
			{
				d.push_back(v[node][i]);
				used[v[node][i]] = true;
			}
	}
}

int main ()
{
	int n, m;
	cin >> n >> m;
	if (n - 1 != m)
	{
		cout << "No";
		return 0;
	}
	vector <vector <int> > g(n, vector <int>(0));
	for (int i = 0 ; i < m; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		g[node1 - 1].push_back(node2 - 1);
		g[node2 - 1].push_back(node1 - 1);
	}
	vector <char> used(n);
	bfs(g, used);
	for (int i = 0; i < n; i++)
		if (!used[i])
		{
			cout << "No";
			return 0;
		}
		cout << "Yes";
}