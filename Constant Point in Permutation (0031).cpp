#include <fstream>
#include <algorithm>

using namespace std;

int main ()
{
	ifstream cin ("INPUT.TXT");
	ofstream cout ("OUTPUT.TXT");
	int n, k, count = 0, a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cin >> n >> k;
	do
	{
		int currCount = 0;
		for (int i = 0; i < n; ++i)
			if (a[i] == i + 1)
				currCount++;
		if (currCount == k)
			++count;
	}
	while (next_permutation(a, a + n));
	cout << count;
}