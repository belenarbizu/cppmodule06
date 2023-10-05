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
    for (unsigned long i = 1; i < arg.length() - 1; i++)
    {
        if (arg[i] < 32 || arg[i] > 126)
        {
            return (false);
        }
    }
    return (true);
}

std::string ScalarConverter::itsType(std::string arg)
{
    std::string pLiterals[] = {"nan", "nanf", "-inff", "+inff", "-inf", "+inf"};

    for (int i = 0; i <= 5; i++)
    {
        if (arg == pLiterals[i])
            return pLiterals[i];
    }
    std::string dataType[] = {"int", "double", "float", "char"};
    bool (ScalarConverter::*varType[4])(std::string arg) = {&ScalarConverter::checkInt, &ScalarConverter::checkDouble, &ScalarConverter::checkFloat, &ScalarConverter::checkChar};

    for (int i = 0; i <= 3; i++)
    {
        if ((this->*varType[i])(arg))
            return (dataType[i]);
    }
    return ("none");
}

ScalarConverter::ScalarConverter(std::string arg)
{
    std::string type;
    this->_arg = arg;
    type = itsType(arg);
    if (type == "int")
    {
        this->_argInt = std::atoi(this->_arg.c_str());
        if (this->_argInt < 32 || this->_argInt > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(this->_argInt) << std::endl;
        std::cout << "int: " << this->_argInt << std::endl;
        std::cout << "float: " << static_cast<float>(this->_argInt) << std::endl;
        std::cout << "double: " << static_cast<double>(this->_argInt) << std::endl;
    }
    else if (type == "double")
    {
        this->_argDouble = std::strtod(this->_arg.c_str(), NULL);
        this->_argInt = static_cast<int>(this->_argDouble);
        if (this->_argInt < 32 || this->_argInt > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(this->_argInt) << std::endl;
        std::cout << "int: " << this->_argInt << std::endl;
        std::cout << "float: " << static_cast<float>(this->_argDouble) << "f" << std::endl;
        std::cout << "double: " << this->_argDouble << std::endl;
    }
    else if (type == "float")
    {
        this->_argFloat = std::strtof(this->_arg.c_str(), NULL);
        this->_argInt = static_cast<int>(this->_argFloat);
        if (this->_argInt < 32 || this->_argInt > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(this->_argInt) << std::endl;
        std::cout << "int: " << this->_argInt << std::endl;
        std::cout << "float: " << this->_argFloat << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(this->_argFloat) << std::endl;
    }
    else if (type == "char")
    {
        this->_argChar = this->_arg[0];
        std::cout << "char: " << this->_argChar << std::endl;
        this->_argInt = static_cast<int>(this->_argChar);
        std::cout << "int: " << this->_argInt << std::endl;
        this->_argFloat = static_cast<float>(this->_argChar);
        std::cout << "float: " << this->_argFloat << "f" << std::endl;
        this->_argDouble = static_cast<double>(this->_argDouble);
        std::cout << "double: " << this->_argDouble << std::endl;
    }
}

ScalarConverter::~ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter & scv)
{
    this->_arg = scv._arg;
    this->_argChar = scv._argChar;
    this->_argDouble = scv._argDouble;
    this->_argFloat = scv._argFloat;
    this->_argInt = scv._argInt;
}