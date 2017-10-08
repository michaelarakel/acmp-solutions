#include <fstream>
using namespace std;
int main ()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	int a[100], n, i, minIndex = 0, maxIndex = 0, sum = 0; 
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[minIndex] > a[i])
			minIndex = i;
		if (a[maxIndex] < a[i])
			maxIndex = i;
		if (a[i] > 0)
			sum += a[i];
	}
	cout << sum << " ";
	int multip = 1;
	if (minIndex > maxIndex)
		for (i = maxIndex+1; i < minIndex; i++)
			multip *= a[i];
	if (maxIndex > minIndex)
		for (i = minIndex+1; i < maxIndex; i++)
			multip *= a[i];
	if (maxIndex == minIndex) multip = 0;
	cout << multip;
	return 0;
}