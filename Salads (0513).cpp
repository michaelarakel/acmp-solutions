#include <fstream>

int main ()
{
	std::ifstream i ("input.txt");
	std::ofstream o ("output.txt");
	int n;
	i >> n;
	o << (1 << n) - n - 1;
}