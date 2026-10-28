#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Date.h"
#include "PozycjaRecepty.h"

class Recepta {
private:
    std::string numerRecepty;
    Date dataWystawienia;
    std::vector<std::unique_ptr<PozycjaRecepty>> pozycje;

public:
    Recepta(std::string numer, Date data);
    void dodajPozycje(std::unique_ptr<PozycjaRecepty> pozycja);
};