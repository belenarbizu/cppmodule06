#include "Base.hpp"

int main(void)
{
    Base *Zacarias = new Base();
    Base *Alejandro = NULL;
    Base *Benito = NULL;
    Base *Carmen = NULL;
    Base *Prueba = NULL;

    Alejandro = Zacarias->generate();
    Benito = Zacarias->generate();
    Carmen = Zacarias->generate();
    Prueba = Zacarias->generate();

    Zacarias->identify(Alejandro);
    Zacarias->identify(Benito);
    Zacarias->identify(Carmen);
    Zacarias->identify(Prueba);

    delete Alejandro;
    delete Benito;
    delete Carmen;
    delete Zacarias;
    delete Prueba;
}