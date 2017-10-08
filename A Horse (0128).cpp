#include <fstream>
#include <vector>
using namespace std;

int main ()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	int n;
	cin >> n;
	vector < vector <int> > v(n + 4, vector <int> (n + 4));
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	v[x1 + 1][y1 + 1] = 1;
	int count = 0;
	while (v[x2 + 1][y2 + 1] != 1)
	{
		for (int i = 2; i < n + 2; i++)
			for (int j = 2; j < n + 2; j++)
				if (v[i][j] == 1)
				{
					v[i][j] = 3;
					v[i - 1][j - 2] = v[i + 1][j - 2] = v[i - 1][j + 2] = v[i + 1][j + 2] = 2;
					v[i - 2][j - 1] = v[i - 2][j + 1] = v[i + 2][j - 1] = v[i + 2][j + 1] = 2;
				}
		count++;
		if (v[x2 + 1][y2 + 1] == 2)
			break;
		for (int i = 2; i < n + 2; i++)
			for (int j = 2; j < n + 2; j++)
				if (v[i][j] == 2)
					v[i][j] = 1;
	}
	cout << count;
}