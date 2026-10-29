#include "Pacjent.h"
#include <iostream>

Pacjent::Pacjent(std::string imie, std::string nazwisko, int id, std::string pesel, Date dataUrodzenia)
    : Osoba(std::move(imie), std::move(nazwisko), id), pesel(std::move(pesel)), dataUrodzenia(std::move(dataUrodzenia)) {}

void Pacjent::wyswietlRole() const {
    std::cout << "Rola: Pacjent" << std::endl;
}

void Pacjent::dodajWizyte(std::shared_ptr<Wizyta> w) {
    historiaWizyt.push_back(w);
}