#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < n/2 + 1; i++)
		sum += v[i]/2 + 1;
	cout << sum;
}