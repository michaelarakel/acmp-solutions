#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	do 
		cout << s << '\n';
	while (next_permutation(s.begin(), s.end()));
}