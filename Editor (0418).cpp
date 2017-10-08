#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
	ifstream in("INPUT.TXT");
	ofstream out("OUTPUT.TXT");
	string s;
	getline(in, s);
	vector <int> v;
	v.push_back(0);
	int max = 0, count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '^')
		{
			if (count != 0)
				--count;
			else
				continue;
		}
		if (s[i] == '|')
			if (count != v.size() - 1)
				++count;
		if (s[i] == '<')
		{
			if (v[count] != 0)
				--v[count];
			else
				if (count != 0)
				{
					v.erase(v.begin() + count);
					--count;
				}
		}
		if (s[i] == '\\')
			v.insert(v.begin() + (++count), 0);
		if (s[i] != '<' &&
			s[i] != '\\' &&
			s[i] != '^' &&
			s[i] != '|')
			++v[count];
		if (max < v[count])
			max = v[count];
	}
	out << max;
}