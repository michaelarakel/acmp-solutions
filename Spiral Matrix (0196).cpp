#include <fstream>
using namespace std;
int main ()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int matrix[100][100];
	int n;
	in >> n;
	int i = 0, j = 0, k, angle = 0;
	bool MoveUp = false, MoveDown = false, MoveLeft = false, MoveRight = true;
	matrix[0][0] = 1;
	for (k = 2; k <= n*n; k++)
	{
		if ((MoveRight || MoveLeft || MoveUp || MoveDown) && k == n*n) break;
		if (MoveRight)
		{
			j++;
			matrix[i][j] = k;
			if (j == n-angle-1)
			{
				MoveRight = false;
				MoveDown = true;
				k++;
			}
		}
		if (MoveDown)
		{
			i++;
			matrix[i][j] = k;
			if (i == n-angle-1)
			{
				MoveDown = false;
				MoveLeft = true;
				k++;
			}

		}
		if (MoveLeft)
		{
			j--;
			matrix[i][j] = k;
			if (k == n*n) break;
			if (j == angle)
			{
				MoveLeft = false;
				MoveUp = true;
				k++;
				angle++;
			}
		}
		if (MoveUp)
		{
			i--;
			matrix[i][j] = k;
			if (i == angle)
			{
				MoveUp = false;
				MoveRight = true;
			}
		}
	}
	if (n%2 ==1)
	{
		matrix[n/2][n/2] = n*n;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			out << matrix[i][j] << " ";
		out << "\n";
	}
}

		