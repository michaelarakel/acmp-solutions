#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("INPUT.TXT");
ofstream out("OUTPUT.TXT");

struct time
{
	int hour, min, sec;
};

istream& operator >> (istream& in, time& t)
{
	in >> t.hour >> t.min >> t.sec;
	return in;
}

ostream& operator << (ostream& out, const time& t)
{
	out << t.hour << " " << t.min << " " << t.sec;
	return out;
}

bool operator < (const time& t1, const time& t2)
{
	return ((3600 * t1.hour + 60 * t1.min + t1.sec) < (3600 * t2.hour + 60 * t2.min + t2.sec));
}

int main ()
{
	time t[100];
	int n;
	in >> n;
	for (int i = 0; i < n; i++)
		in >> t[i];
	sort (t, t + n);
	for (int i = 0; i < n; i++)
		out << t[i] << endl;
}