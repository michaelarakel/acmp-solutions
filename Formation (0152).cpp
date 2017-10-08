#include <fstream>
#include <vector>

using namespace std;

bool dfs (const vector <vector <int> >& g, vector <int>& color, int node)
{
	color[node] = 1;
	for (int i = 0; i < g[node].size(); ++i)
	{
		int currNode = g[node][i];
		if (!color[currNode])
			if (dfs(g, color, currNode))
				return true;
		if (color[currNode] == 1)
			return true;
	}
	color[node] = 2;
	return false;
}

int main ()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
	}
	vector <int> color(n);
	for (int i = 0; i < n; ++i)
	{
		if (!color[i])
			if (dfs(g, color, i))
			{
				cout << "No";
				return 0;
			}
	}
	cout << "Yes";
}