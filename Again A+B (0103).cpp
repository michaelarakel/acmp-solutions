#include <fstream>
#include <string>
using namespace std;
ifstream in("INPUT.TXT");
ofstream out("OUTPUT.TXT");

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
void adding(string& c, int n)// avelacnum e 0ner stringin
{
	for (int i = 0; i < n; i++)
			c = '0' + c;
}
void add(string& c, int n)// ays funkciyan avelacnum eim uzac tiv@ stringin
{
	char temp = n + '0';
	c = temp + c;
}
string sum(string& s1, string& s2)
{
	int n = max(s1.size(), s2.size());
	if (s1.size() < n)
		adding(s1, n - s1.size());
	if (s2.size() < n)
		adding (s2, n - s2.size()); //avelacnum enq 0ner aveli karch stringin
	string summary;
	int temp;
	bool inmind = false;// inmind-i imast@ mtqum pahvac tivn e, isk gumarman jamanak dra maximal arjeq@ = 1 (9+9 = 18 mtqum pahum enq 1)
	for (int i = n-1; i >= 0; i--)
	{
		temp = (s1[i] - '0') + (s2[i] - '0');
		if (temp < 10)
		{
			
			if (inmind && temp == 9)
				add(summary, 0);
			if (!inmind)
				add(summary, temp);
			if (inmind && temp != 9)
			{
				add(summary, temp+1);
				inmind = false;
			}
			
		}
		else
		{
			if (inmind)
				add(summary, temp - 9);
			if (!inmind)
				add(summary, temp - 10);
			inmind = true;
		}
	}
	if (inmind)
		add(summary, 1);
	return summary;
}
int main ()
{
	string a, b;
	in >> a >> b;
	out << sum (a, b);
	return 0;
}