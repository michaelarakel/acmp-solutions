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
	int start, end;
	cin >> start >> end;
	if (start == end)
	{
		cout << '0';
		return 0;
	}
	start -= 1;
	end -= 1;
	deque <int> d;
	d.push_back(start);
	vector <int> pre(n);
	vector <char> used(n);
	pre[start] = -1;
	used[start] = true;
	while (!d.empty())
	{
		int node = d[0];
		d.pop_front();
		for (int i = 0; i < g[node].size(); ++i)
		{
			if (!used[g[node][i]])
			{
				used[g[node][i]] = true;
				pre[g[node][i]] = node;
				d.push_back(g[node][i]);
			}
		}
	}
	if (!used[end])
	{
		cout << "-1";
		return 0;
	}
	int count = 0;
	for (int v = end; pre[v] != -1; v = pre[v])
		count++;
	cout << count;
}