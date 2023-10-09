#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>

class Serializer
{
public:
    Serializer();
    ~Serializer();
    Serializer(const Serializer & srz);
    Serializer& operator=(const Serializer & srz);

    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);
};

#endif