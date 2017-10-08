#include <fstream>
#include <deque>
#include <vector>

using namespace std;

void bfs (vector <vector <char> >& v, int row, int col)
{
	deque <pair <int, int> > d;
	d.push_back(make_pair(row, col));
	while (!d.empty())
	{
		pair <int, int> node = d[0];
		d.pop_front();
		const int a[] = {1, -1, 0, 0},
				  b[] = {0, 0, 1, -1};
		for (int i = 0; i < 4; ++i)
		{
			int x = node.first + a[i],
				y = node.second + b[i];
			if (x >=0 && x < v.size() &&
				y >= 0 && y < v[0].size() &&
				v[x][y] == '#')
			{
				d.push_back(make_pair(x, y));
				v[x][y] = '.';
			}
		}
	}
}

int main ()
{
	ifstream cin ("INPUT.TXT");
	ofstream cout ("OUTPUT.TXT");
	int n, m, count = 0;
	cin >> n >> m;
	vector <vector <char> > v(n, vector <char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (v[i][j] == '#')
			{
				bfs(v, i, j);
				count++;
			}
	cout << count;
}