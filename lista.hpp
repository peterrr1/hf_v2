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
    //konstruktor
    Lista() : elso(NULL) {}

    //másoló konstruktor
    Lista(const Lista& lista);

    //operator=
    Lista& operator=(const Lista& rhs);

    //hozzáfűz egy elemet a lista végéhez
    void hozzafuz(Adatok& adat);

    //ellenőrzi, hogy a megadott telefonszám benne van-e a listában
    bool benne_van(const std::string& telSzam) const;

    //a listában lévő összes elemet kiirja
    void listaKiir(std::ostream& os = std::cout) const;

    //minden elemet töröl a listából
    void listaTorol();

    //törli a megadott elemet a listából
    void torol(const std::string& telSzam);

    //megkeresi a megadott telefonszám benne van-e a listában, ha benne van kiirja az adatait
    void szamKeres(const std::string& telSzam) const;

    //megkeresi a megadott név benne van-e a listában, ha benne van kiiírja az adatait
    void nevKeres(const std::string& nev) const;

    //telefonszám formátumának ellenőrzése
    bool szam(const std::string& telSzam) const;


    void modosit(const std::string& telSzam);


    //destruktor
    ~Lista();

    //ezért kell, hogy a file osztály hozzáférjen a lista első eleméhez
    friend class File;
};


#endif