#include <fstream>
#include <string>
using namespace std;

int main ()
{
	ifstream in("INPUT.TXT");
	ofstream out("OUTPUT.TXT");
	const string keys = "qwertyuiopasdfghjklzxcvbnm";
	char letter;
	in >> letter;
	int i = 0;
	while (letter != keys[i])
		i++;
	out << keys[(i+1)%26];
}