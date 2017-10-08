#include <fstream>

using namespace std;

int main ()
{
	ifstream cin ("INPUT.TXT");
	ofstream cout ("OUTPUT.TXT");
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if ( (x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) != 0)
	{
		if ( (x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2) == 0)
		{
			swap (x2, x1);
			swap (y2, y1);
		}
		else
		{
			swap (x3, x1);
			swap (y3, y1);
		}
	}
	cout << x3 + x2 - x1 << " ";
	cout << y3 + y2 - y1;
}