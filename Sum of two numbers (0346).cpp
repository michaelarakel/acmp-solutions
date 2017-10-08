#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main ()
{
	ifstream i ("input.txt");
	ofstream o ("output.txt");
	string a, b;
	int C;
	i>>a>>b>>C;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	do
	{
		int A;
		istringstream m(a);
		m>>A;
		int e=C-A;
		if (e>=0)
		{
			ostringstream n;
			n<<e;
			string s=n.str();
			sort(s.begin(),s.end());
			if (s==b)
			{
				o<<"YES"<<endl<<A<<' '<<e;
				return 0;
			}
		}
	}
	while (next_permutation(a.begin(), a.end()));
	o << "NO";
}