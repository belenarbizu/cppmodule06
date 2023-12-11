#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>
#include <iostream>

struct Data {
    int varNum;
    std::string varStr;
};

class Serializer
{
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer & srz);
    Serializer& operator=(const Serializer & srz);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif