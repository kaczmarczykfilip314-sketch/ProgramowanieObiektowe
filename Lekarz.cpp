#include "Lekarz.h"
#include <iostream>

Lekarz::Lekarz(std::string imie, std::string nazwisko, int id, std::string pwz, std::string specjalizacja)
    : Osoba(std::move(imie), std::move(nazwisko), id), numerPWZ(std::move(pwz)), specjalizacja(std::move(specjalizacja)) {}

void Lekarz::wyswietlRole() const {
    std::cout << "Rola: Lekarz" << std::endl;
}

void Lekarz::dodajSlot(std::shared_ptr<SlotCzasowy> s) {
    grafik.push_back(s);
}