#include <fstream>
#include <vector>

using namespace std;

int main ()
{
	ifstream cin ("INPUT.TXT");
	ofstream cout ("OUTPUT.TXT");
	int n, m;
	cin >> n >> m;
	vector <int> v(n);
	for (int i = 0; i < m; ++i)
	{
		int node1, node2;
		cin >> node1 >> node2;
		++v[node1 - 1];
		++v[node2 - 1];
	}
	for (int i = 0; i < n; ++i)
		cout << v[i] << " ";
}