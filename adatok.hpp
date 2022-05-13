#ifndef adatok_hpp
#define adatok_hpp

#include <iostream>

class Adatok {
    std::string Nev;
    std::string Becenev;
    std::string Lakcim;
    std::string Email;
    std::string MunkSzam;
    std::string PrivSzam;
public:

    Adatok(std::string aNev = "", std::string aBecNev = "", std::string aLakcim = "", std::string aEmail = "", std::string aMunkSzam = "", std::string aPrivSzam = "")
    : Nev(aNev), Becenev(aBecNev), Lakcim(aLakcim), Email(aEmail), MunkSzam(aMunkSzam), PrivSzam(aPrivSzam) {}

    std::string getNev() const {
        return Nev;
    }

    std::string getBecenev() const {
        return Becenev;
    }

    std::string getLakcim() const {
        return Lakcim;
    }

    std::string getEmail() const {
        return Email;
    } 

    std::string getMunkSzam() const {
        return MunkSzam;
    }

    std::string getPrivSzam() const {
        return PrivSzam;
    }

    void adatKiir() const {
        std::cout << Nev << '\n' << Becenev << '\n' << Lakcim <<
        '\n' << Email << '\n' << MunkSzam << '\n' << PrivSzam << '\n' << std::endl;
    }
};


#endif