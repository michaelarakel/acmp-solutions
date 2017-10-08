#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	int n;
	cin >> n;
	int count1 = 1, count2 = 1,
		ans = 1;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	for (int i = 1; i < n; ++i)
	{
		if (i%2 == 0)
		{
			if (v[i] < v[i - 1])
			{
				++count1;
				count2 = 1;
			}
			if (v[i] > v[i - 1])
			{
				count1 = 1;
				++count2;
			}
		}
		else
		{
			if (v[i] > v[i - 1])
			{
				++count1;
				count2 = 1;
			}
			if (v[i] < v[i - 1])
			{
				count1 = 1;
				++count2;
			}
		}
		ans = max(max(ans, count1), count2);
	}
	cout << ans;
}