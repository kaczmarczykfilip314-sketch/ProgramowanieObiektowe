#pragma once
#include <string>
#include <vector>
#include "Date.h"
#include "PozycjaRecepty.h"

class Recepta {
private:
    std::string numerRecepty;
    Date dataWystawienia;
    std::vector<PozycjaRecepty> pozycje;

public:
    Recepta(std::string numer, Date data);
    
    void dodajPozycje(const PozycjaRecepty& pozycja);
    void wypisz() const;
};
