#include <fstream>
#include <string>
using namespace std;

ifstream in("INPUT.TXT");
ofstream out("OUTPUT.TXT");

void degree(string& s, int n)
{
	if (n > 0)
		for (int i = 0; i < n; i++)
			out << s;
	if (n < 0)
	{
		n *= -1;
		if (s.size()%n != 0)
		{
			out << "NO SOLUTION";
			return;
		}
		int substrlen = s.size()/n;
		for (int i = 0; i < s.size()-substrlen; i += substrlen)
		{
			if (s.substr(0, substrlen) != s.substr(i+substrlen, substrlen))
			{
				out << "NO SOLUTION";
				return;
			}
		}
		s.erase(substrlen, s.size() - substrlen);
		out << s;
	}
}
int main ()
{
	string str;
	int deg;
	in >> str >> deg;
	degree(str, deg);
	return 0;
}