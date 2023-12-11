#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
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
void identify(Base *p)
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
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception & e)
    {}
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::exception & e)
    {}
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::exception & e)
    {}
}

int main(void)
{
    std::srand(std::time(0));
    Base *Zacarias = new Base();
    Base *Alejandro = NULL;
    Base *Benito = NULL;
    Base *Carmen = NULL;
    Base *Prueba = NULL;

    Alejandro = generate();
    Benito = generate();
    Carmen = generate();
    Prueba = generate();

    identify(Alejandro);
    identify(Benito);
    identify(Carmen);
    identify(Prueba);

    identify(*Alejandro);
    identify(*Benito);
    identify(*Carmen);
    identify(*Prueba);

    delete Alejandro;
    delete Benito;
    delete Carmen;
    delete Zacarias;
    delete Prueba;
}