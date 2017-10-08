#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	int n, m;
	cin >> n ;
	m = n;
	vector < vector <int> > dp(n, vector <int>(m));
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); ++j)
			dp[i][j] = (int) (s[j] - '0');
	}
	for (int i = 1; i < dp.size(); ++i)
	for (int j = 1; j < dp[i].size(); ++j)
		if (dp[i][j] != 0)
			dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;

	int ans = 0;
	for (int i = 0; i < dp.size(); ++i)
	for (int j = 0; j < dp.size(); ++j)
	if (ans < dp[i][j])
		ans = dp[i][j];
	cout << ans * ans;
}