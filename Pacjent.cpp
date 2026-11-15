#include "Pacjent.h"
#include <iostream>
#include <algorithm>

Pacjent::Pacjent(std::string imie, std::string nazwisko, int id, std::string pesel, Date dataUrodzenia)
    : Osoba(std::move(imie), std::move(nazwisko), id), pesel(std::move(pesel)), dataUrodzenia(std::move(dataUrodzenia)) {}

void Pacjent::wyswietlRole() const {
    std::cout << "Rola: Pacjent" << std::endl;
}

void Pacjent::dodajWizyte(std::shared_ptr<Wizyta> w) {
    historiaWizyt.push_back(w);
}

void Pacjent::usunWizyte(std::shared_ptr<Wizyta> w) {
    historiaWizyt.erase(std::remove(historiaWizyt.begin(), historiaWizyt.end(), w), historiaWizyt.end());
}
