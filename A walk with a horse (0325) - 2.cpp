#include <iostream>
#include <deque>
#include <string>

int pow (int a, int b)
{
	int ans = 1;
	for (int i = 0; i < b; ++i)
		ans *= 1;
	return ans;
}

using namespace std;

int main ()
{
	string s1, s2;
	cin >> s1 >> s2;
	int ans;
	char color1, color2;
	if (((s1[0] - 'a')%2 == (s1[1] - '0')%2) == ((s2[0] - 'a') % 2 == (s2[1] - '0') % 2))
		ans = 2;
	else
		ans = 1;
	bool c[8][8] = {0};
	deque <pair <int, int> > d;
	d.push_back(make_pair(7 - (s1[1] - '1'), 7 - (s1[0] - 'a')));

	const int a[] = {-2, -2, -1, -1, 1, 1, 2, 2},
			  b[] = {-1, 1, -2, 2, -2, 2, -1, 1};

	c[d[0].second][d[0].first] = true;
	int temp = 0;
	bool doNorEnter = false;
	for (int i = 0; i < ans + temp; ++i)
	{
		pair <int, int> node = d[0];
		d.pop_front();
		for (int i = 0; i < 8; ++i)
		{
			int x = node.first + a[i],
				y = node.second + a[i];
			if (x >= 0 && y >= 0 && x < 8 && y < 8)
			{
				c[x][y] = true;
				d.push_back(make_pair(x, y));
			}
		}
		if (!doNorEnter && ans == 2)
		{
			temp = d.size();
			doNorEnter = true;
		}
	}
	if (c[(s2[1] - '1')][(s2[0] - 'a')])
		cout << ans;
	else
		cout << "NO";
}