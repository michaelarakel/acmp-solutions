#include <iostream>
#include <string>

using namespace std;

char col (int i, int j)
{
	char c;
	if (i%2 == j%2)
		c = 'w';
	else
		c = 'b';
	return c;
}

int main ()
{
	//ifstream cin ("INPUT.TXT");
	//ofstream cout ("OUTPUT.TXT");
	const int f1[] = {-2, -2, -1, -1, 1, 1, 2, 2},
			  f2[] = {-1, 1, -2, 2, -2, 2, -1, 1};
	string a, b;
	cin >> a >> b;
	char color[2];
	color[0] = col(a[0] - 'a', a[1] - '1');
	color[1] = col(b[0] - 'a', b[1] - '1');
	int rowDiff = a[0] - b[0], colDiff = a[1] - b[1];
	if (color[0] != color[1])
	{
		for (int i = 0; i < 8; ++i)
		{
			if (rowDiff == f1[i] && colDiff == f2[i])
			{
				cout << 1;
				return 0;
			}
		}
		cout << "NO";
	}
	else
	{
		for (int i = 0; i < 8; ++i)
			for (int j = i; j < 8; ++j)
				if (f1[i] + f1[j] == rowDiff && f2[i] + f2[j] == colDiff)
				{
					cout << 2;
					return 0;
				}
		cout << "NO";
	}
	return 0;
}