#ifndef lista_hpp
#define lista_hpp

#include <iostream>
#include "adatok.hpp"

class Lista {
    struct Elem {
        Adatok adat;
        Elem* kov;

        Elem(Adatok& adat) : adat(adat), kov(NULL) {}
    };
    
    Elem* elso;
public:

    Lista() : elso(NULL) {}

    Lista(const Lista& lista);

    void hozzafuz(Adatok& adat);

    bool benne_van(std::string telSzam) const;

    void listaKiir() const;

    ~Lista();

};


#endif