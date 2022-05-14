#include <iostream>
#include "gtest_lite.h"
#include "adatok.hpp"
#include "lista.hpp"
#include "filekezeles.hpp"

int main() {

    Lista ll;

    Adatok robert("Kis Robert", "Robi", "Budapest", "robert@gmail.com", "06304444444", "06301111111");


    //getter függvények tesztelése tesztelése
    TEST (adat, getNev()) {
        EXPECT_EQ("Kis Robert", robert.getNev());
    END }

    TEST (adat, getBecenev()) {
        EXPECT_EQ("Robi", robert.getBecenev());
    END }

    TEST (adat, getLakcim()) {
        EXPECT_EQ("Budapest", robert.getLakcim());
    END }

    TEST (adat, getEmail()) {
        EXPECT_EQ("robert@gmail.com", robert.getEmail());
    END }

    TEST (adat, getMunkSzam()) {
        EXPECT_EQ("06304444444", robert.getMunkSzam());
    END }

    TEST (adat, getPrivSzam()) {
        EXPECT_EQ("06301111111", robert.getPrivSzam());
    END }
    //================================================
    try {
     Adatok peti("Nagy Peter", "Peti", "Budapest", "peti@gmail.com", "0620000000", "06908888888");
     ll.hozzafuz(peti);
    } catch (std::length_error& err) {
        std::cerr << err.what() << std::endl;
    }
    /*
    TEST (lista, hozzafuz()) {
        Adatok peti("Nagy Peter", "Peti", "Budapest", "peti@gmail.com", "0620000000", "06908888888");
        EXPECT_ANY_THROW(ll.hozzafuz(peti));
    END }
    */
}