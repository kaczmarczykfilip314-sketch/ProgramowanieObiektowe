#include "PozycjaRecepty.h"
#include <iostream>

PozycjaRecepty::PozycjaRecepty(std::string lek, std::string dawka, int ilosc)
    : nazwaLeku(std::move(lek)), dawkowanie(std::move(dawka)), ilosc(ilosc) {}

void PozycjaRecepty::wypisz() const {
    std::cout << "  - " << nazwaLeku << ", ilosc: " << ilosc << ", dawkowanie: " << dawkowanie << std::endl;
}
