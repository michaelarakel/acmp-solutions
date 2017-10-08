#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>

using namespace std;


int rev (int n)
{
	if (n == 1)
		return 2;
	if (n == 2)
		return 1;
}
int main ()
{
	freopen("INPUT.TXT", "r", stdin);
	freopen("OUTPUT.TXT", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n);
	for (int i = 0; i < m; ++i)
	{
		int node1, node2;
		cin >> node1 >> node2;
		g[node1 - 1].push_back(node2 - 1);
		g[node2 - 1].push_back(node1 - 1);
	}
	deque <int> d;
	d.push_back(0);
	vector <char> used(n);
	vector <int> color(n);
	color[0] = 1;
	used[0] = true;
	while (!d.empty())
	{
		int node = d[0];
		int currColor = rev(color[node]);
		d.pop_front();
		for (int i = 0; i < g[node].size(); ++i)
		{
			int currNode = g[node][i];
			if (!used[currNode])
			{
				used[currNode] = true;
				color[currNode] = currColor;
				d.push_back(currNode);
				continue;
			}
			else
			{
				if (currColor != color[currNode])
				{
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES";
}