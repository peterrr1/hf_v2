#include <iostream>
#include "filekezeles.hpp"



void File::fileBeolvas(Lista& rhs) {
    std::fstream file;

    file.open("telefonkonyv.txt", std::ios::in | std::ios::app);
    try {
        if (!file) {
            throw std::runtime_error("Fajl megnyitasa sikertelen!\n");
        }
        else {
            std::string sor;

            while (std::getline(file, sor)) {
                std::stringstream ss(sor);

                std::string tmpNev, tmpBecNev, tmpLakcim, tmpEmail, tmpMunkSzam, tmpPrivSzam;

                std::getline(ss, tmpNev, ':');
                std::getline(ss, tmpBecNev, ':');
                std::getline(ss, tmpLakcim, ':');
                std::getline(ss, tmpEmail, ':');
                std::getline(ss, tmpMunkSzam, ':');
                std::getline(ss, tmpPrivSzam, ':');

                Adatok ujAdat(tmpNev, tmpBecNev, tmpLakcim, tmpEmail, tmpMunkSzam, tmpPrivSzam);

                rhs.hozzafuz(ujAdat);
            }
        }
    }
    catch (std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
    }
    file.close();
}

void File::fileKiiras(Lista& rhs) {
    std::fstream file;

    file.open("telefonkonyv.txt", std::ios::out);
    try {
        if (!file) {
            throw std::runtime_error("Fajl megnyitasa sikertelen!\n");
        }
        else {
            for (Lista::Elem *tmp = rhs.elso; tmp != NULL; tmp = tmp->kov) {
                file << tmp->adat.getNev() << ':' << tmp->adat.getBecenev() << ':' << tmp->adat.getLakcim() << ':' <<
                tmp->adat.getEmail() << ':' << tmp->adat.getMunkSzam() << ':' << tmp->adat.getPrivSzam() << '\n';
            }
        }
    }
    catch (std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
    }
    file.close();
}