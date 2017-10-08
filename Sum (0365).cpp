#include <fstream>
#include <vector>

using namespace std;

ifstream cin ("INPUT.TXT");
ofstream cout ("OUTPUT.TXT");

void print (const vector <int>& v)
{
	if (v.size() == 1)
		return;
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i];
		if (i != v.size() - 1)
			cout  << '+';
	}
	cout << endl;
}

void rec(vector <int>& ans, int n, int num, int pos)
{
	if (num > n)
		return;
	if (num == n)
	{
		print(ans);
		return;
	}
	for (int i = pos; i <= n; ++i)
	{
		ans.push_back(i);
		rec(ans, n, num + i, i);
		ans.pop_back();
	}
}

int main ()
{
	int n;
	cin >> n;
	vector <int> ans;
	rec(ans, n, 0, 1);
}