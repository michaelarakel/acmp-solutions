#include <fstream>
using namespace std;

bool spareArea(int i, int j, char** a)
{
	if ( (int) (a[i][j-1] + a[i][j+1] + a[i-1][j] + a[i+1][j])  == 184)// '.' - i ASCII kod@ 46a u qani vor mutqum menak 
																	  //'.' u '*' im karciqov aveli heshta senc stugel
		return true;
	return false;
}

int main ()
{
	ifstream in ("INPUT.TXT");
	ofstream out ("OUTPUT.TXT");
	int n, m;
	in >> n >> m;
	char ** field = new char* [n+2];
	for (int i = 0; i < n+2; ++i)
		field[i] = new char [m+2];
	for (int i = 0; i < n+2; ++i)
		for (int j = 0; j < m+2; ++j)
			field[i][j] = '.';
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			in >> field[i][j];
	int count = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (field[i][j] == '.')
				if (spareArea(i, j, field))
					count++;
	out << count;
	for (int i = 0; i < n+2; ++i)
		delete []field[i];
	delete []field;
}