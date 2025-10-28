#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char *av[])
{
	if (ac == 1)
    {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
    else
    {
		for (int i = 1; i < ac; ++i)
        {
			std::string temp = av[i];
			for (std::string::size_type j = 0; j < temp.length(); ++j)
            {
				std::cout << static_cast<char>(std::toupper(temp[j]));
			}
		}
	}
	std::cout << std::endl;
	return 0;
}