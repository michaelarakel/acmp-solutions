#include <fstream>
using namespace std;

ifstream in("INPUT.TXT");
ofstream out("OUTPUT.TXT");

void sweep(char a[202][202])
{
	for (int i = 0; i < 201; i++)
		for (int j = 0; j < 201; j++)
			a[i][j] = '0';
}

void coordinates(char a[][], int i, int j)
{
	if (a[i][j] == '*')
		return;
	a[i][j] = '*';
	for (int l = -1; l <= 1; l++)
		for (int k = -1; k <= 1; k++)
		{
			if (i+l == i && j+k == j)
				continue;
			if (a[i+l][j+k] != '*')
				a[i+l][j+k] += 1;
		}
}

void from0toDot (char a[202][202], int n, int m)
{
	for (int i = 1; i < n+1; i++)
		for (int j = 1; j < m+1; j++)
			if (a[i][j] == '0')
				a[i][j] = '.';
}

void print (char a[202][202], int n, int m)
{
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
			out << a[i][j];
		out << "\n";
	}
}

int main ()
{
	int n, m, k;
	in >> n >> m >> k;
	char space[202][202];
	sweep(space);
	int x, y;
	for (int Index = 0; Index < k; Index++)
	{
		in >> x >> y;
		coordinates(space, x, y);
	}
	from0toDot(space, n, m);
	print(space, n, m);
}