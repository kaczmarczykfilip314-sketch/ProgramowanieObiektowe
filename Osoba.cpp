#include "Osoba.h"

Osoba::Osoba(std::string imie, std::string nazwisko, int id) 
    : imie(std::move(imie)), nazwisko(std::move(nazwisko)), id(id) {}

int Osoba::getId() const {
    return id;
}