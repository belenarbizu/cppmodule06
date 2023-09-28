#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Add one arg!" << std::endl;
        return 0;
    }
    ScalarConverter sc(argv[1]);
    return 0;
}