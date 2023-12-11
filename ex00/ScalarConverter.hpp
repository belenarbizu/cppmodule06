#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <stdlib.h>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter & scv);
    virtual ~ScalarConverter();
    ScalarConverter(const ScalarConverter & scv);

    static std::string itsType(std::string arg);
    static bool checkInt(std::string arg);
    static bool checkChar(std::string arg);
    static bool checkDouble(std::string arg);
    static bool checkFloat(std::string arg);
    static void cvtFromInt(std::string arg);
    static void cvtFromChar(std::string arg);
    static void cvtFromDouble(std::string arg);
    static void cvtFromFloat(std::string arg);
public:
    static void converter(std::string arg);
};

#endif