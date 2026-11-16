#include "Wizyta.h"
#include "Recepta.h"
#include <iostream>

Wizyta::Wizyta(std::shared_ptr<SlotCzasowy> przypisanySlot) 
    : status("Zaplanowana"), opis(""), slot(przypisanySlot) {}

void Wizyta::zmienStatus(const std::string& nowyStatus) {
    status = nowyStatus;
}

void Wizyta::dodajRecepte(std::shared_ptr<Recepta> r) {
    recepty.push_back(r);
}

std::shared_ptr<SlotCzasowy> Wizyta::getSlot() const {
    return slot;
}

void Wizyta::wypisz() const {
    std::cout << "Wizyta - Status: " << status << ", Opis: " << (opis.empty() ? "brak" : opis) << std::endl;
    for (const auto& r : recepty) {
        r->wypisz();
    }
}
