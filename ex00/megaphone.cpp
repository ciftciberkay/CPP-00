#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        int i = 1;
        while (i < ac)
        {
            std::string temp = av[i];
            size_t j = 0;
            while (j < temp.length())
            {
                std::cout << (char)std::toupper(temp[j]);
                ++j;
            }
            ++i;
        }
        std::cout << std::endl;
    }
    return 0;
}
