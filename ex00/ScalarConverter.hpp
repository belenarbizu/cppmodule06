#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <stdlib.h>

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
    std::string itsType(std::string arg);
    bool checkInt(std::string arg);
    bool checkChar(std::string arg);
    bool checkDouble(std::string arg);
    bool checkFloat(std::string arg);
    void cvtFromInt(void);
    void cvtFromChar(void);
    void cvtFromDouble(void);
    void cvtFromFloat(void);
public:
    ScalarConverter(std::string arg);
    virtual ~ScalarConverter();
    ScalarConverter(const ScalarConverter & scv);
};

#endif