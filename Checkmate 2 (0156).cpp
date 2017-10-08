#include <fstream>

int main ()
{
	std::ifstream e ("INPUT.TXT");
	std::ofstream o ("OUTPUT.TXT");
	int n, k;
	e >> n >> k;
	if (k > n)
		o << 0;
	else
	{
		int N = 1, K = 1, NK = 1;
		for (int i = 2; i <= n; ++i)
		{
			N *= i;
			if (i <= k)
				K = N;
			if (i <= n - k)
				NK = N;
		}
		int C = (N/K)/NK;
		o << K * C * C;
	}
}