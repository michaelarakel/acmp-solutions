#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <int> v1(n), v2(m);
	for (int i = 0; i < n; ++i)
		cin >> v1[i];
	for (int j = 0; j < m; ++j)
		cin >> v2[j];
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	vector <int> ans;
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(ans));
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	return 0;
}