#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct tunnel
{
	int x1;
	int y1;
	int x2;
	int y2;
};

istream& operator >> (istream& input, tunnel& a)
{
	input >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	--a.x1;
	--a.x2;
	--a.y1;
	--a.y2;
	return input;
}

void print (const vector <vector <char> >& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
}

void bfs(vector <vector <char> >& v, const pair <int, int> start, const vector <tunnel>& t)
{
	queue <pair <int, int> > q;
	q.push(start);
	const int a[] = {1, -1, 0, 0},
			  b[] = {0, 0, 1, -1};
	vector < vector <pair<int, int> > > pre(v.size(), vector < pair <int, int> >(v[0].size()));
	vector < vector <char> > used (v.size(), vector <char>(v[0].size()));
	pre[start.first][start.second] = make_pair(-1, -1);
	used[start.first][start.second] = true;
	while (!q.empty())
	{
		pair <int, int> curr = q.front();
		q.pop();
		if (v[curr.first][curr.second] == '*')
		{
			vector <pair <int, int> > path;
			for (pair <int, int> k = make_pair(curr.first, curr.second); k != pre[start.first][start.second]; k = pre[k.first][k.second])
				path.push_back(k);
			cout << path.size() << endl;
			reverse(path.begin(), path.end());
			for (int j = 0; j < path.size(); ++j)
				cout << path[j].first + 1 << ' ' << path[j].second + 1 << endl;
			return;
		}
		for (int i = 0; i < 4; ++i)
		{
			int x = curr.first + a[i],
				y = curr.second + b[i];
			if (x >= 0 && x < v.size() && y >= 0 && y < v[0].size() && !used [x][y] && v[x][y] != '1')
			{
				q.push(make_pair(x, y));
				used[x][y] = true;
				pre[x][y] = make_pair(curr.first, curr.second);
			}
		}
		if (v[curr.first][curr.second] == 't')
		{
			for (int j = 0; j < t.size(); ++j)
			{
				if (t[j].x1 == curr.first && t[j].y1 == curr.second)
				{
					if (!used[t[j].x2][t[j].y2])
					{
						q.push(make_pair(t[j].x2, t[j].y2));
						used[t[j].x2][t[j].y2] = true;
						pre[t[j].x2][t[j].y2] = make_pair(t[j].x1, t[j].y1);
					}
					break;
				}
			}
		}
	}
	cout << "Impossible";
}

int main ()
{
	//freopen ("INPUT.TXT", "r", stdin);
	//freopen ("OUTPUT.TXT", "w", stdout);
	int n, m;
	cin >> n >> m;
	pair <int, int> start;
	cin >> start.first >> start.second;
	--start.first;
	--start.second;
	vector <vector <char> > g(n, vector <char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> g[i][j];
	int tunnel_num;
	cin >> tunnel_num;
	vector <tunnel> tunnels(tunnel_num);
	for (int i = 0; i < tunnel_num; ++i)
	{
		cin >> tunnels[i];
		g[tunnels[i].x1][tunnels[i].y1] = 't';
	}
	int end_num;
	cin >> end_num;
	for (int i = 0; i < end_num; ++i)
	{
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		g[x][y] = '*';
	}
	//print(g);
	bfs(g, start, tunnels);
}