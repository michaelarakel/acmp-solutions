#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>

using namespace std;

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	int n;
	cin >> n;
	vector <vector <pair <char, bool> > > v(n + 2, vector <pair <char, bool> >(n + 2));
	pair <int, int> start, end;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j].first;
			if (v[i][j].first == 'X')
				end = make_pair(i, j);
			if (v[i][j].first == '@')
				start = make_pair(i, j);
		}
	deque <pair <int, int> > d;
	vector < vector <pair <int, int> > > pre(n + 2, vector <pair <int, int> >(n + 2));
	d.push_back(start);
	while (!d.empty())
	{
		pair <int, int> node = d[0];
		d.pop_front();
		if ((v[node.first + 1][node.second].first == '.' ||
			v[node.first + 1][node.second].first == 'X') && 
			v[node.first + 1][node.second].second == false)
		{
			v[node.first + 1][node.second].second = true;
			pre[node.first + 1][node.second] = make_pair(node.first, node.second);
			d.push_back(make_pair(node.first + 1, node.second));
		}


		if ((v[node.first - 1][node.second].first == '.' ||
			v[node.first - 1][node.second].first == 'X') &&
			v[node.first - 1][node.second].second == false)
		{
			v[node.first - 1][node.second].second = true;
			pre[node.first - 1][node.second] = make_pair(node.first, node.second);
			d.push_back(make_pair(node.first - 1, node.second));
		}


		if ((v[node.first][node.second + 1].first == '.' ||
			v[node.first][node.second + 1].first == 'X') &&
			v[node.first][node.second + 1].second == false)
		{
			v[node.first][node.second + 1].second = true;
			pre[node.first][node.second + 1] = make_pair(node.first, node.second);
			d.push_back(make_pair(node.first, node.second + 1));
		}


		if ((v[node.first][node.second - 1].first == '.' ||
			v[node.first][node.second - 1].first == 'X') &&
			v[node.first][node.second - 1].second == false)
		{
			v[node.first][node.second - 1].second = true;
			pre[node.first][node.second - 1] = make_pair(node.first, node.second);
			d.push_back(make_pair(node.first, node.second - 1));
		}
	}
	if (!v[end.first][end.second].second)
	{
		cout << "N";
		return 0;
	}
	cout << "Y" << endl;
	for (pair <int, int> i = end; i != start; i = pre[i.first][i.second])
		v[i.first][i.second].first = '+';
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << v[i][j].first;
		cout << endl;
	}
}