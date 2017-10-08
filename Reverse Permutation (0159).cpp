#include <fstream>

int main ()
{
	std::ifstream e("input.txt");
	std::ofstream o("output.txt");
	int n, a[20001], i, b;
	e >> n;
	for (i = 0; i < n; ++i)
	{
		e >> b;
		a[b - 1] = i + 1;
	}
	for (i = 0; i < n; ++i)
		o << a[i] << ' ';
}