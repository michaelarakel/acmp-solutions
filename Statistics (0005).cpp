#include <fstream>
using namespace std;
int main ()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int a[100], n, i, numofUneven = 0;
	bool b = true;
	in >> n;
	for (i = 0; i < n; i++)
		in >> a[i];
	for (i = 0; i < n; i++)
	{
		if (b)
		{
			if (a[i]%2 == 1)
			{
				out << a[i] << " ";
				numofUneven++;
			}
			if (i == n-1)
			{
				i = 0;
				b = false;
				out << "\n";
			}
		}
		if (!b)
			if (a[i]%2 == 0)
			{
				out << a[i] << " ";
				numofUneven--;
			}
	}
	if (numofUneven > 0)
		out << "NO";
	else
		out << "YES";
	return 0;
}