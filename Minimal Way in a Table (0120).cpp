#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream cin("INPUT.TXT");
    ofstream cout("OUTPUT.TXT");
    int n, m;
    cin >> n >> m;
    vector <vector <int> > v(n + 2, vector <int> (m + 2, 3000));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;
            v[i][j] += min (v[i - 1][j], v[i][j - 1]);
        }
    cout << v[n][m];
} 