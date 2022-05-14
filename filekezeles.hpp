#ifndef filekezeles_hpp
#define filekezeles_hpp

#include <fstream>
#include <sstream>
#include "lista.hpp"

class File {
public:
    //fájlból beolvassa a listába az adatok
    void fileBeolvas(Lista& rhs);

    //kiirja fájlba a lista adatait
    void fileKiiras(Lista& rhs);
};

#endif