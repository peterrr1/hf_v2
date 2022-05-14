#include <iostream>
#include "lista.hpp"


Lista::Lista(const Lista& rhs) {

    if (rhs.elso == NULL) {
        elso = NULL;
    }
    else {
        elso = new Elem(rhs.elso->adat);

        Elem* tmp = elso;

        for (Elem* rhsTmp = rhs.elso->kov; rhsTmp != NULL; rhsTmp = rhsTmp->kov) {
            tmp->kov = new Elem(rhsTmp->adat);
            tmp = tmp->kov;
        }
    }
}


Lista& Lista::operator=(const Lista& rhs) {
    if (this == &rhs) {
        return *this;
    }

    this->listaTorol();


    if (rhs.elso == NULL) {
        elso = NULL;
    }
    else {
        elso = new Elem(rhs.elso->adat);

        Elem* tmp = elso;

        for (Elem* rhsTmp = rhs.elso->kov; rhsTmp != NULL; rhsTmp = rhsTmp->kov) {
            tmp->kov = new Elem(rhsTmp->adat);
            tmp = tmp->kov;
        }
    }

    return *this;
}

bool Lista::szam(const std::string& telSzam) const {
    for (unsigned int i = 0; i != telSzam.length(); i++) {
        if (std::isdigit(telSzam[i]) == 0)
        return false;
    }
    return true;
}

void Lista::hozzafuz(Adatok& adat) {
    try {
        if (benne_van(adat.getPrivSzam()) || benne_van(adat.getMunkSzam())) {
            throw std::invalid_argument("A megadott telefonszam mar benne van a listaban!\n");
        }
        if (!szam(adat.getPrivSzam()) || !szam(adat.getMunkSzam())) {
            throw std::invalid_argument("Nem megfelelo formatumu telefonszam!\n");
        }
        if (adat.getMunkSzam().length() != 11 || adat.getPrivSzam().length() != 11) {
            throw std::length_error("Nem megfelelo formatumu telefonszam!\n");
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
    catch (std::invalid_argument& err) {
        std::cerr << err.what() << std::endl;
    }
    catch (std::length_error& err) {
        std::cerr << err.what() << std::endl;
    }
}


bool Lista::benne_van(const std::string& telSzam) const {
    for (Elem *tmp = elso; tmp != NULL; tmp = tmp->kov) {
        if (tmp->adat.getMunkSzam() == telSzam || tmp->adat.getPrivSzam() == telSzam) {
            return true;
        }
    }
    return false;
}


void Lista::listaKiir(std::ostream& os) const {
    for (Elem* tmp = elso; tmp != NULL; tmp = tmp->kov) {
        tmp->adat.adatKiir();
    }
}


void Lista::listaTorol() {
    Elem *tmp = elso;
    while (tmp != NULL) {
        Elem *kovTmp = tmp->kov;
        delete tmp;
        tmp = kovTmp;
    }
}


void Lista::torol(const std::string& telSzam) {
    try {
        if (elso == NULL) {
            throw std::length_error("Nem lehet ures listat torolni!\n");
        }
        if (!benne_van(telSzam)) {
            std::cout << "A megadott telefonszam nincs a listaban!\n" << std::endl;
            return;
        }
        Elem* elozo = NULL;
        for (Elem* tmp = elso; tmp != NULL; tmp = tmp->kov) {
            if (telSzam == tmp->adat.getMunkSzam() || telSzam == tmp->adat.getPrivSzam()) {
                tmp->adat.adatKiir();
                std::cout << "Biztosan torli a bejegyzest? [I/N]";
                std::string bemenet;
                std::getline(std::cin, bemenet);
                
                if (bemenet == "I" || bemenet == "i") {
                    if (tmp == elso) {
                        elso = tmp->kov;
                        delete tmp;
                    }
                    else {
                        elozo->kov = tmp->kov;
                        delete tmp;
                    }
                    std::cout << "Sikeres torles!\n" << std::endl;
                    return;
                }
                if (bemenet == "N" || bemenet == "n") {
                    std::cout << "Nem tortent torles!\n" << std::endl;
                    return;
                }
                else {
                    std::cout << "Hibas bemenet!\n" << std::endl;
                    return;
                }
            }
            elozo = tmp;
        }
    }
    catch (std::length_error& err) {
        std::cerr << err.what() << std::endl;
    }
}


void Lista::szamKeres(const std::string& telSzam) const {
    if (!benne_van(telSzam)) {
        std::cout << "A megadott telefonszam nincs a listaban!\n" << std::endl;
        return;
    }
    for (Elem* tmp = elso; tmp != NULL; tmp = tmp->kov){
        if (telSzam == tmp->adat.getMunkSzam() || telSzam == tmp->adat.getPrivSzam()) {
            tmp->adat.adatKiir();
        }
    }
}


void Lista::nevKeres(const std::string& nev) const{
    bool nevBenneVan = false;
    for (Elem* tmp = elso; tmp != NULL; tmp = tmp->kov) {
        if (tmp->adat.getNev() == nev) {
            tmp->adat.adatKiir();
            nevBenneVan = true;
        }
    }
    if (!nevBenneVan) {
        std::cout << "A megadott nev nincs a listaban!" << std::endl;
    }
}


void Lista::modosit(const std::string& telSzam) {
    try {
        if (elso == NULL) {
            throw std::length_error("Üres listát nem lehet modositani!\n");
        }
        if (!benne_van(telSzam)) {
            std::cout << "A megadott telefonszam nincs a listaban!\n" << std::endl;
            return;
        }
        Elem *tmp = elso;
        Elem* elozo = NULL;
        while (tmp != NULL) {
            if (tmp->adat.getPrivSzam() == telSzam || tmp->adat.getMunkSzam() == telSzam) {
                tmp->adat.adatKiir();

                std::string tmpNev, tmpBecNev, tmpLakcim, tmpEmail, tmpMunkSzam, tmpPrivSzam;

                std::cout << "Nev:";
                std::getline(std::cin, tmpNev);

                std::cout << "Becenev:";
                std::getline(std::cin, tmpBecNev);

                std::cout << "Lakcim:";
                std::getline(std::cin, tmpLakcim);

                std::cout << "Email:";
                std::getline(std::cin, tmpEmail);

                std::cout << "Munkahelyi szam:";
                std::getline(std::cin, tmpMunkSzam);

                std::cout << "Privat szam:";
                std::getline(std::cin, tmpPrivSzam);
                std::cout << std::endl;

                Adatok ujAdat(tmpNev, tmpBecNev, tmpLakcim, tmpEmail, tmpMunkSzam, tmpPrivSzam);

                Elem* ujElem = new Elem(ujAdat);

                if (!szam(ujElem->adat.getPrivSzam()) || !szam(ujElem->adat.getMunkSzam())) {
                    delete ujElem;
                    throw std::invalid_argument("Nem megfelelo formatumu telefonszam!\n");
                }
                if (ujElem->adat.getMunkSzam().length() != 11 || ujElem->adat.getPrivSzam().length() != 11) {
                    delete ujElem;
                    throw std::length_error("Nem megfelelo formatumu telefonszam!\n");
                }
                if (tmp == elso) {
                    ujElem->kov = tmp->kov;
                    elso = ujElem;
                    delete tmp;
                    break;
                }
                else {
                    ujElem->kov = tmp->kov;
                    elozo->kov = ujElem;
                    delete tmp;
                }
            }
            elozo = tmp;
            tmp = tmp->kov;
        }
    }
    catch (std::length_error& err) {
        std::cerr << err.what() << std::endl;
    }
    catch (std::invalid_argument& err) {
        std::cerr << err.what() << std::endl;
    }
}

Lista::~Lista() {
    listaTorol();
}