#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000 * 1000 * 1000;

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
    int n;
    cin >> n;
    vector <vector <int> > g(n, vector <int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
		{
            cin >> g[i][j];
			if (g[i][j] == 0)
				g[i][j] = INF;
		}
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
				if (g[i][k] < INF && g[k][j] < INF)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	// for 135, 136
	/*for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << g[i][j] << ' ';
		cout << endl;
	}
	*/
	// for 137
	/*for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				if (g[i][k] < INF && g[k][k] < 0 && g[k][j] < INF)
					g[i][j] = -INF;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
		{
			if (g[i][j] == -INF)
				cout << 2;
			else if (g[i][j] == INF && i != j)
				cout << 0;
			else
				cout << 1;
			cout << ' ';
		}
		cout << endl;
	}*/

} 