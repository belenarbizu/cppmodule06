#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{
    std::cout << "Base constructor called" << std::endl;
}

Base::~Base()
{
    std::cout << "Base destructor called" << std::endl;
}

Base* Base::generate(void)
{
    int num = 1 + std::rand() % (4 - 1);
    if (num == 1)
    {
        return (new A());
    }
    else if (num == 2)
    {
        return (new B());
    }
    else if (num == 3)
    {
        return (new C());
    }
    return (NULL);
}
void Base::identify(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
    }
}
void Base::identify(Base& p)
{
    if (dynamic_cast<A *>(&p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(&p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(&p))
    {
        std::cout << "C" << std::endl;
    }
}