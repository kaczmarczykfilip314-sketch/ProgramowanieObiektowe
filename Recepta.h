#pragma once
#include <string>

class PozycjaRecepty {
private:
    std::string nazwaLeku;
    std::string dawkowanie;
    int ilosc;

public:
    PozycjaRecepty(std::string lek, std::string dawka, int ilosc);
};