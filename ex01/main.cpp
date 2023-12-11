#include "Serialization.hpp"

int main(void)
{
    Data Test;
    uintptr_t retPtr;
    Data *retTest;

    Test.varNum = 5;
    Test.varStr = "Serialization";

    std::cout << "Original:" << std::endl;
    std::cout << "Num: " << Test.varNum << std::endl;
    std::cout << "Str: " << Test.varStr << std::endl;

    retPtr = Serializer::serialize(&Test);
    retTest = Serializer::deserialize(retPtr);

    std::cout << "After serialization:" << std::endl;
    std::cout << "Num: " << retTest->varNum << std::endl;
    std::cout << "Str: " << retTest->varStr << std::endl;
}