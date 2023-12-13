#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter & scv)
{
    (void)scv;
    return *this;
}
bool ScalarConverter::checkInt(std::string arg)
{
    if (arg[0] != '-' && arg[0] != '+' && !isdigit(arg[0]))
        return (false);
    for (unsigned long i = 1; i < arg.length(); i++)
    {
        if (!isdigit(arg[i]))
            return (false);
    }
    return (true);
}
bool ScalarConverter::checkFloat(std::string arg)
{
    if (arg[0] != '-' && arg[0] != '+' && !isdigit(arg[0]))
        return (false);
    for (unsigned long i = 1; i < arg.length(); i++)
    {
        if (!isdigit(arg[i]))
        {
            if (i == arg.length() - 1)
                return (arg[i] == 'f');
            else if (arg[i] != '.')
                return (false);
        }
    }
    return (true);
}
bool ScalarConverter::checkDouble(std::string arg)
{
    if (arg[0] != '-' && arg[0] != '+' && !isdigit(arg[0]))
        return (false);
    for (unsigned long i = 1; i < arg.length(); i++)
    {
        if (!isdigit(arg[i]))
        {
            if (arg[i] != '.')
                return (false);
        }
    }
    return (true);
}
bool ScalarConverter::checkChar(std::string arg)
{
    if (arg.size() != 1)
        return (false);
    return (true);
}
void ScalarConverter::cvtFromInt(std::string arg)
{
    double argDouble = std::atof(arg.c_str());
    int argInt = static_cast<int>(argDouble);
    if (argInt < 0 || argInt > 255)
        std::cout << "char: overflow" << std::endl;
    else if (argInt < 32 || argInt > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(argInt) << std::endl;
    if (argDouble > INT_MAX || argDouble < INT_MIN)
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << argInt << std::endl;
    std::cout << "float: " << std::fixed << static_cast<float>(argDouble) << "f" << std::endl;
    std::cout << "double: " << std::fixed << static_cast<double>(argDouble) << std::endl;
}
void ScalarConverter::cvtFromChar(std::string arg)
{
    char argChar = arg[0];
    std::cout << "char: " << argChar << std::endl;
    int argInt = static_cast<int>(argChar);
    std::cout << "int: " << argInt << std::endl;
    float argFloat = static_cast<float>(argChar);
    std::cout << "float: " << std::fixed << argFloat << "f" << std::endl;
    std::cout << "double: " << std::fixed << static_cast<double>(argChar) << std::endl;
}
void ScalarConverter::cvtFromDouble(std::string arg)
{
    double argDouble = std::atof(arg.c_str());
    int argInt = static_cast<int>(argDouble);
    if (argInt < 0 || argInt > 255)
        std::cout << "char: overflow" << std::endl;
    else if (argInt < 32 || argInt > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(argInt) << std::endl;
    if (argDouble > INT_MAX || argDouble < INT_MIN)
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << argInt << std::endl;
    std::cout << "float: " << std::fixed << static_cast<float>(argDouble) << "f" << std::endl;
    std::cout << "double: " << std::fixed << argDouble << std::endl;
}
void ScalarConverter::cvtFromFloat(std::string arg)
{
    double argDouble = std::atof(arg.c_str());
    int argInt = static_cast<int>(argDouble);
    if (argInt < 0 || argInt > 255)
        std::cout << "char: overflow" << std::endl;
    else if (argInt < 32 || argInt > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(argInt) << std::endl;
    if (argDouble > INT_MAX || argDouble < INT_MIN)
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << argInt << std::endl;
    std::cout << "float: " << std::fixed << static_cast<float>(argDouble) << "f" << std::endl;
    std::cout << "double: " << std::fixed << argDouble << std::endl;
}

std::string ScalarConverter::itsType(std::string arg)
{
    if (arg == "nan" || arg == "nanf" || arg == "+inff" || arg == "-inff" || arg == "+inf" || arg == "-inf")
        return ("literal");
    std::string dataType[] = {"int", "double", "float", "char"};
    bool (*varType[4])(std::string arg) = {&checkInt, &checkDouble, &checkFloat, &checkChar};

    for (int i = 0; i <= 3; i++)
    {
        if ((*varType[i])(arg))
            return (dataType[i]);
    }
    return ("none");
}

void ScalarConverter::converter(std::string arg)
{
    std::string type;
    double argDouble;
    type = itsType(arg);
    if (type == "literal")
    {
        if (arg == "nan" || arg == "nanf")
        {
            argDouble = std::atof(arg.c_str());
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << static_cast<float>(argDouble) << "f" << std::endl;
            std::cout << "double: " << argDouble << std::endl;
        }
        else
        {
            argDouble = std::atof(arg.c_str());
            std::cout << "char: overflow" << std::endl;
            std::cout << "int: overflow" << std::endl;
            std::cout << "float: " << static_cast<float>(argDouble) << "f" << std::endl;
            std::cout << "double: " << argDouble << std::endl;
        }
    }
    else if (type == "none")
    {
        std::cout << "char: unknown" << std::endl;
        std::cout << "int: unknown" << std::endl;
        std::cout << "float: unknown" << std::endl;
        std::cout << "double: unknown" << std::endl;
    }
    std::string dataType[] = {"int", "double", "float", "char"};
    void (*cvtVar[4])(std::string arg) = {&cvtFromInt, &cvtFromDouble, &cvtFromFloat, &cvtFromChar};

    for (int i = 0; i <= 3; i++)
    {
        if (type == dataType[i])
            ((*cvtVar[i])(arg));
    }
}

ScalarConverter::~ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter & scv)
{
    (void)scv;
}