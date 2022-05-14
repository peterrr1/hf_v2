#include <iostream>
#include "adatok.hpp"
#include "lista.hpp"
#include "filekezeles.hpp"


int main() {

    Lista ll;
    File ff;

    ff.fileBeolvas(ll);

    Adatok peti("Brezovcsik Peter", "Peti", "1028 Budapest", "brezop@gmail.com", "06205693212", "06204355322");


    ll.hozzafuz(peti);

    ll.listaKiir();


    ll.modosit("06204355322");

    ll.listaKiir();

    ff.fileKiiras(ll);

    return 0;
}