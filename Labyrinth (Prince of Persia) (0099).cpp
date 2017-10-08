#include <fstream>
#include <vector>
#include <deque>
using namespace std;

struct node 
{
	int matrNum;
	int x;
	int y;
};

bool operator != (const node& a, const node& b)
{
	return (a.matrNum != b.matrNum) || (a.x != b.x) || (a.y != b.y);
}

bool check (int a, int b, int c, int n, int m, int p)
{
	return (a >= 0 && a < n) && (b >= 0 && b < m) && (c >= 0 && c < p); 
}

int main ()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	int n, m, p;
	cin >> p >> n >> m;
	vector < vector < vector <char> > > lab (p, vector < vector <char> >(n, vector <char> (m)));
	node start, end;
	for (int i = 0; i < p; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				cin >> lab[i][j][k];
				if (lab[i][j][k] == '1')
				{
					start.matrNum = i;
					start.x = j;
					start.y = k;
				}
				if (lab[i][j][k] == '2')
				{
					end.matrNum = i;
					end.x = j;
					end.y = k;
				}
			}
	vector < vector < vector <bool> > > used(p, vector <vector <bool> >(n, vector <bool>(m)));
	used[start.matrNum][start.x][start.y] = true;
	deque <node> d;
	d.push_back(start);
	vector < vector < vector <node> > > pre(p, vector <vector <node> >(n, vector <node> (m)));
	while (!used[end.matrNum][end.x][end.y])
	{
		const int a[] = {0, 0, 1, -1, 0};
		const int b[] = {-1, 1, 0, 0, 0};
		const int c[] = {0, 0, 0, 0, 1};
		for (int i = 0; i < 5; i++)
		{
			int x = d[0].x + a[i], y = d[0].y + b[i], z = d[0].matrNum + c[i];
			if (check(x, y, z, n, m, p))
				if(!used[z][x][y])
					if (lab[z][x][y] != 'o')
						{
							used[z][x][y] = true;
							node temp;
							temp.x = x;
							temp.matrNum = z;
							temp.y = y;
							d.push_back(temp);
							pre[z][x][y] = d[0];
						}
		}
		d.pop_front();
	}
	int count = 0;
	node i = end;
	while (i != start)
	{
		i = pre[i.matrNum][i.x][i.y];
		count++;
	}
	cout << 5 * count;
}