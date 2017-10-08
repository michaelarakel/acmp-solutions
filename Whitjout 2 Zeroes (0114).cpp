#include <fstream>
#include <vector>

using namespace std;

int main ()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	int n, k;
	cin >> n >> k;
	vector <int> v;
	v.push_back(0);
	v.push_back(k - 1);
	for (int i = 2; i <= n; i++)
		v.push_back((k - 1)*(v[i - 1] + v[i - 2]));
	cout << v[n] + v[n - 1];
}