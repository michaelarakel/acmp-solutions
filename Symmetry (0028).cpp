#include <fstream>

using namespace std;

int main ()
{
   ifstream cin ("input.txt");
   ofstream cout ("output.txt");
   int x1, y1, x2, y2, xa, ya;
   cin >> x1 >> y1 >> x2 >> y2 >> xa >> ya;
   bool Ox, Oy, check;
   Ox = Oy = check = false;
   if (x1 == x2)
	   Ox = true;
   if (y1 == y2)
	   Oy = true;
    if ( (Ox && xa == x1) ||
         (Oy && ya == y1) )
        check = true;
     if (check)
		 cout << xa << ' ' << ya;
	 else
	 {
		 if (Ox)
			 cout <<  2 * x1 - xa << ' ' << ya;
		 else
			 cout << xa << ' ' << 2 * y1 - ya;
	 }
} 
