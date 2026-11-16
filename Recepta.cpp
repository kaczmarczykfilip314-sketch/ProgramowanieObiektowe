#include "Recepta.h"
#include <iostream>

Recepta::Recepta(std::string numer, Date data) 
    : numerRecepty(std::move(numer)), dataWystawienia(std::move(data)) {}

void Recepta::dodajPozycje(const PozycjaRecepty& pozycja) {
    pozycje.push_back(pozycja);
}

void Recepta::wypisz() const {
    std::cout << "Recepta " << numerRecepty << " wystawiona dnia: " << dataWystawienia << std::endl;
    for (const auto& poz : pozycje) {
        poz.wypisz();
    }
}