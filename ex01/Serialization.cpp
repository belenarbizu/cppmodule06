#include "Serialization.hpp"

Serializer::Serializer()
{
}
Serializer::~Serializer()
{
}
Serializer::Serializer(const Serializer & srz)
{
    (void)srz;
}
Serializer& Serializer::operator=(const Serializer & srz)
{
    (void)srz;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}