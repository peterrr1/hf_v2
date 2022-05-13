#include <iostream>
#include "adatok.hpp"
#include "lista.hpp"


int main() {

    Lista ll;



    Adatok peti("Peter", "Peti", "Budapest", "brezo@gmail.com", "06704455332", "06204355322");

    ll.hozzafuz(peti);



    Adatok vivi("Vivien", "Vivi", "Budapest", "vivien@gmail.com", "06203349982", "06709928832");

    ll.hozzafuz(vivi);

    ll.listaKiir();

    Lista l2 = ll;

    l2.listaKiir();



    return 0;
}