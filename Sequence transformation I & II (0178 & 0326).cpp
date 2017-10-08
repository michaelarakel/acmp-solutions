#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
	ifstream in("INPUT.TXT");
	ofstream out("OUTPUT.TXT");
	int n;
	in >> n;
	vector <int> v(n);
	for (int i =0; i < n; i++)
		in >> v[i];
	vector <int> a(n);
	a = v;
	sort (a.begin(), a.end());
	int count = 1, maxCount = 1, num = a[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == a[i + 1])
		{
			count++;
			if (maxCount < count)
			{
				maxCount = count;
				num = a[i];
			}
		}
		else
			count = 1;
	}
	vector <int> b;
	for (int i = 0; i < n; i++)
		if (v[i] != num)
			b.push_back(v[i]);
	for (int i = 0; i < maxCount; i++)
		b.push_back(num);
	for (int i = 0; i < b.size(); i++)
		out << b[i] << " ";
}