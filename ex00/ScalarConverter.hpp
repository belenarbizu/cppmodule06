#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>

class ScalarConverter
{
private:
    std::string _arg;
    int _argInt;
    char _argChar;
    double _argDouble;
    float _argFloat;
    ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter & scv);
public:
    ScalarConverter(std::string arg);
    virtual ~ScalarConverter();
    ScalarConverter(const ScalarConverter & scv);
};

#endif