#include <fstream>
using namespace std;
int main ()
{
	ifstream in("INPUT.TXT");
	ofstream out("OUTPUT.TXT");
	int a, b, c;
	in>>a>>b>>c;
	if (a==0)
	{
		if(b==0)
		{
			if(c==0)
			{
				out<<0;
			}
			else
			{
				if (c>0)
				{
					if (c!=1)
					{
						out<<c;
					}
					out<<"y";
				}
				else
				{
					out<<"-";
					if (c!=-1)
					{
						out<<-c;
					}
					out<<"y";
				}
			}
		}
		else
		{
			if (b!=1&&b!=-1)
			{
				out<<b<<"x";
			}
			if (b==1)
			{
				out<<"x";
			}
			if (b==-1)
			{
				out<<"-x";
			}
			if (c<0)
			{
			if (c==-1)
			{
				out<<"-y";
			}
			else
			{
				out<<c<<"y";
			}
		}
		if (c>0)
		{
			out<<"+";
			if (c!=1)
			{
				out<<c;
			}
			out<<"y";
		}
	}
	}
	else
	{
		out<<a;
		if (b>0)
		{
			out<<"+";
			if (b!=1)
			{
				out<<b;
			}
			out<<"x";
		}
		if (b<0)
		{
			out<<"-";
			if (b!=-1)
			{
				out<<-b;
			}
			out<<"x";
		}
		if (c>0)
		{
			out<<"+";
			if (c!=1)
			{
				out<<c;
			}
			out<<"y";
		}
		if (c<0)
		{
			out<<"-";
			if (c!=-1)
			{
				out<<-c;
			}
			out<<"y";
		}
		}
		return 0;
		}