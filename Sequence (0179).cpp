#include <fstream>
#include <vector>

using namespace std;

void multip(vector <int>& big, int num)
{
   int mitq = 0;
   for (int i = 0; i < big.size(); ++i)
   {
      mitq += big[i]*num;
      big[i] = mitq % 10;
      mitq /= 10;
   }
   if (mitq > 0)
      big.push_back(mitq);
   if (big[0] - 2 < 0)
   {
	   int pos = 1;
	   while (big[pos] == 0)
		   big[pos] = 9;
	   big[pos]--;
	   big[0] += 8;
   }
   else
	   big[0] -= 2;
}

int main ()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	vector <int> v(1, 2);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		multip(v, 3);
	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i];
}