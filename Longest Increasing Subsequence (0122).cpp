#include <fstream>
#include <vector>

using namespace std;

int main ()
{
	ifstream cin ("INPUT.TXT");
	ofstream cout ("OUTPUT.TXT");
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	vector <int> d(n, 1);
	for (int i = 1; i < n; ++i)
	{
		int maxD = 0;
		for (int j = i - 1; j >= 0; --j)
		{
			if (maxD < d[j])
			{
				if (v[i] > v[j])
				{
					maxD = d[j];
					d[i] = d[j] + 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (ans < d[i])
			ans = d[i];
	cout << ans;
}