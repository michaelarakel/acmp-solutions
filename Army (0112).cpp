#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int num = 0;

void merge (int* start1, int* end1, int * start2, int* end2, int* dest)
{
	bool usedFromSecond = false;
	vector <int> c;
	int i = 0, j = 0;
	while (start1 + i != end1 || start2 + j != end2)
	{
		if (start1 + i != end1 && start2 + j != end2)
		{
			c.push_back(min(*(start1 + i), *(start2 + j)));
			if (*(start1 + i) < *(start2 + j))
			{
				i++;
				if (usedFromSecond)
					num += j;
			}
			else
			{
				j++;
				usedFromSecond = true;
			}
		}
		else
		{ 
			if (start1 + i == end1 && start2 + j != end2)
			{
				c.push_back(*(start2 + (j++)));
			}
			if (start1 + i != end1 && start2 + j == end2)
			{
				num += j;
				c.push_back(*(start1 + (i++)));
			}
		}
	}
	for (int i = 0; i < c.size(); ++i)
		*(dest + i) = c[i];
}

void merge_sort (int* start, int* end)
{
	if (start == end)
		return;
	int* pos = start + (end - start) / 2;
	merge_sort(start, pos);
	merge_sort(pos + 1, end);
	merge(start, pos + 1, pos + 1, end + 1, start);
}

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	int n, m;
	cin >> m >> n;
	vector < vector <int> > v(n, vector <int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v[i][j];
	for (int i = 0; i < n; i++)
		merge_sort(&v[i][0], &v[i][m - 1]);
	cout << num;
}