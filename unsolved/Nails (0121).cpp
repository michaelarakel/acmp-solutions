#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
	//ifstream cin ("INPUT.TXT");
	//ofstream cout ("OUTPUT.TXT");
	int n;
	cin >> n;
	vector <char> used(n);
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort (v.begin(), v.end());
	int count = v[1] - v[0];
	used[0] = used[1] = true;
	for (int i = 2; i < n - 2; ++i)
		if (!used[i])
		{
			int temp1 = v[i] - v[i - 1], temp2 = v[i + 1] - v[i];
			count += min (temp1, temp2);
			used[i] = true;
			if (temp2 <= temp1)
				used[i + 1] = true;
		}
	count += min (
	cout << count;
}