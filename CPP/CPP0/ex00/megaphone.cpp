
#include "iostream"
#include <cctype>

int main (int ac, char **av)
{
	int i;
	char ch;

	i = 0;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	else
		for (int i = 1; i < ac; i++) {
			for (int i2 = 0; i2 < (int)strlen(av[i]); i2++) {
				ch = std::toupper((unsigned char)av[i][i2]);
				std::cout << ch;
			}
		}
	std:: cout << std::endl;
	return 0;
}
