#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	//ifstream cin ("INPUT.TXT");
	//ofstream cout ("OUTPUT.TXT");
	int n, m;
	cin >> n;
	m = n;
	vector <vector <int> > v(n, vector <int> (m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int num;
			cin >> num;
			v[i][j] = num;
			if (j > 0)
				v[i][j] += v[i][j - 1];
		}
	}
	int max = v[0][0];
	for (int len = 0; len < m; ++len)
	{
		for (int row = 0; row < n; ++row)
		{
			for (int j = len; j < m ; ++j)
			{
				int sum = 0;
				for (int i = row; i < n; ++i)
				{
					if (len == 0)
						sum += v[i][j];
					else
						sum += v[i][j] - v[i][j - len]; 
					if (max < sum)
						max = sum;
				}
			}
		}
	}
	cout << max;
}