#include "Base.hpp"

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
    int num = std::rand() % 3 + 1;
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
}
void Base::identify(Base *p)
{

}
void Base::identify(Base& p)
{

}