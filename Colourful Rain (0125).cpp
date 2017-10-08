#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	//ifstream cin ("INPUT.TXT");
	//ofstream cout ("OUTPUT.TXT");
	int n;
	cin >> n;
	vector <vector <int> > v(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int num;
			cin >> num;
			if (num == 1)
				v[i].push_back(j);
		}
	vector <int> color(n);
	for (int i = 0; i < n; ++i)
		cin >> color[i];
	int count = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < v[i].size(); ++j)
			if (color[i] != color[v[i][j]])
				++count;
	cout << count/2;
}