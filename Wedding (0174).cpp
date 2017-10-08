#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;
int main ()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	in >> n;
	int husbandMoney[40], i;
	for (i = 0; i < n; i++)
		in >> husbandMoney[i];
	double GorgonaMoney;
	in >> GorgonaMoney;
	sort (husbandMoney, husbandMoney + n);
	for (i = 0; i < n; i++)
		if (husbandMoney[i] > GorgonaMoney)
			GorgonaMoney = (GorgonaMoney + husbandMoney[i])/2;
	out << fixed << setprecision(6) << GorgonaMoney;
	return 0;
}