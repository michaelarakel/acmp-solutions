#include <fstream>
using namespace std;
int main ()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int matrix[100][100], rows, coloumns, n;
	in >> rows >> coloumns;
	int i, j, k;
	for (i = 0; i < rows; i++)
		for (j = 0; j < coloumns; j++)
			matrix[i][j] = 0;
	in >> n;
	int x1, y1, x2, y2;
	for (i = 0; i < n; i++)
	{
		in >> x1 >> y1 >> x2 >> y2;
		for (j = x1; j < x2; j++)
			for (k = y1; k < y2; k++)
				matrix[j][k] = 1;
	}
	int count = 0;
	for (i = 0; i < rows; i++)
		for (j = 0; j < coloumns; j++)
			if (matrix[i][j] == 0) count++;
	out << count;
	return 0;
}