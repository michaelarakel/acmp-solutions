#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	vector <int> v;
	int n;
	while (cin >> n)
		v.push_back(n);
	sort(v.begin(), v.end());
	int d = v[1] - v[0];
	for (int i = 2; i < v.size(); i++)
		if (v[i] - v[i - 1] != d)
		{
			cout << "No";
			return 0;
		}
	cout << "Yes";
}