#include <fstream>

int main ()
{
	std::ifstream i ("input.txt");
	std::ofstream o ("output.txt");
	int n;
	i >> n;
	o << n * (n + 1)/2 + 1;
}