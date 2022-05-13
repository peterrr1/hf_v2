#include <iostream>
#include "lista.hpp"

Lista::Lista(const Lista& lista) {
    
}


void Lista::hozzafuz(Adatok& adat) {
    if (benne_van(adat.getPrivSzam()) || benne_van(adat.getMunkSzam())) {
        throw std::logic_error("A megadott telefonszam mar benne van a listaban!\n");
    }
    else {

        Elem *ujElem = new Elem(adat);

        if (elso == NULL) {
            elso = ujElem;
        }
        else {
            Elem* tmp = elso;
            while (tmp->kov != NULL) {
                tmp = tmp->kov;
            }
            tmp->kov = ujElem;
        }
    }
}

bool Lista::benne_van(std::string telSzam) const {
    for (Elem *tmp = elso; tmp != NULL; tmp = tmp->kov) {
        if (tmp->adat.getMunkSzam() == telSzam || tmp->adat.getPrivSzam() == telSzam) {
            return true;
        }
    }
    return false;
}

void Lista::listaKiir() const {
    for (Elem* tmp = elso; tmp != NULL; tmp = tmp->kov) {
        tmp->adat.adatKiir();
    }
}

Lista::~Lista() {
    Elem *tmp = elso;
    while (tmp != NULL) {
        Elem *kovTmp = tmp->kov;
        delete tmp;
        tmp = kovTmp;
    }
}