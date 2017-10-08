#include <fstream>
#include <string>
using namespace std;
int main ()
{
	ifstream in("input.txt");
	ofstream out("output.txt"); 
	int count = 0;
	string arrow = "";
	in >> arrow;
	int n = arrow.size();
	for (int i = 1; i < n - 1; i++)
	{
		if (arrow[i] == arrow[i+1] && //posledovatelnosti mej gtnum em "--"-ner@, qani vor nranq aveli qij en, qan ">" kam "<", dranov pordzum em aragacnel cragirs
			arrow[i] == '-') // i-n sksum enq 1ic ev verjacnum n-1-ov, vorovhetev "-"-ov sksox kam verjacox@ chi kazmum >>--> kam <--<<
		{
			if (arrow[i-2] == arrow[i-1] &&
				arrow[i-2] == arrow[i+2] &&
				arrow [i-2] == '>')
				count++;
			if (arrow[i-1] == arrow[i+2] &&
				arrow[i-1] == arrow[i+3] &&
				arrow [i-1] == '<')
				count++;
		}
	}
	out << count;
}
