#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	int n, node;
	cin >> n >> node;
	node -= 1;
	vector <vector <int> > g(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			if (num == 1)
				g[i].push_back(j);
		}
	}
	int count = 0;
	deque <int> d;
	d.push_back(node);
	vector <char> used(n);
	used[node] = true;
	while (!d.empty())
	{
		int curr = d[0];
		d.pop_front();
		for (int i = 0; i < g[curr].size(); ++i)
		{
			if (!used[g[curr][i]])
			{
				count++;
				d.push_back(g[curr][i]);
				used[g[curr][i]] = true;
			}
		}
	}
	cout << count;
}