#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter & scv)
{
    (void)scv;
    return *this;
}
ScalarConverter::ScalarConverter(std::string arg)
{
    this->_arg = arg;
    std::stringstream ss(arg);
    ss >> this->_argChar;
    std::cout << "char: " << this->_argChar << std::endl;
    ss.clear();
    ss.str("");
    ss.str(arg);
    ss >> this->_argDouble;
    std::cout << "double: " << this->_argDouble << std::endl;
    ss.clear();
    ss.str("");
    ss.str(arg);
    ss >> this->_argInt;
    std::cout << "int: " << this->_argInt << std::endl;
    ss.clear();
    ss.str("");
    ss.str(arg);
    ss >> this->_argFloat;
    std::cout << "float: " << this->_argFloat << std::endl;
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