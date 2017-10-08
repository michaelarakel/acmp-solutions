#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	int n, k, count = 0;
	cin >> n >> k;
	vector <int> v;
	for (int i = 1; i <= n; ++i)
		v.push_back(i);
	do
	{
		bool check = true;
		for (int i = 1; i < n; ++i)
			if (abs(v[i] - v[i - 1]) > k)
			{
				check = false;
				break;
			}
		if (check)
			++count;
	}
	while (next_permutation(v.begin(), v.end()));
	cout << count;
}