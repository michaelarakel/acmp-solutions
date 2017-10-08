#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool ans = false;

const char c[] = "+-";



vector <char> act;
vector <int> v;

int n, m;

void rec (int num, int pos)
{
	if (!ans)
	{
		if (pos == m)
		{
			if (num == n)
			{
				for (int i = 0; i < m - 1; ++i)
					cout << v[i] << act[i];
				cout << v[v.size() - 1] << '=' << n;
				ans = true;
			}
			return;
		}
	}
	for (int i = 0; i < 2; ++i)
	{
		if (!ans)
		{
			int temp = num;
			switch(c[i])
			{
				case '+':
					num += v[pos];
					break;
				case '-':
					num-= v[pos];
					break;
			}
			act.push_back(c[i]);
			rec(num, pos + 1);
			act.pop_back();
			num = temp;
		}
	}
}

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	int num = v[0];
	rec(num, 1);
	if (!ans)
		cout << "No solution";
}