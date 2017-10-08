#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

vector < pair <double, double> > v;
int n;

double length (double x1, double y1, double x2, double y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void dfs (vector <char>& used, const double& len, int node)
{
	used[node] = true;
	for (int i = 0; i < n; ++i)
	{
		if (i == node)
			continue;
		if (!used[i] && (length(v[node].first, v[node].second, v[i].first, v[i].second)  - len < 1e-9))
			dfs(used, len, i);
	}
}

int main ()
{
	ifstream cin ("INPUT.TXT");
	ofstream cout ("OUTPUT.TXT");
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		double n, m;
		cin >> n >> m;
		v.push_back(make_pair(n, m));
	}
	double start = 0.0, end = length(-10000., 10000., 10000., -10000.);
	while (end - start > 1e-9)
	{
		double mid = (start + end)/2;
		vector <char> used(n);
		dfs(used, mid, 0);
		bool connected = true;
		for (int i = 0; i < n; ++i)
			if (!used[i])
			{
				connected = false;
				break;
			}
		if (connected)
			end = mid;
		else
			start = mid;
	}
	cout << fixed << setprecision(2) << sqrt(start) + 0.001;
}