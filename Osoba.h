#pragma once
#include <string>

class Osoba {
protected:
    std::string imie;
    std::string nazwisko;
    int id;

public:
    Osoba(std::string imie, std::string nazwisko, int id);
    virtual ~Osoba() = default;
    
    virtual void wyswietlRole() const = 0; // Metoda czysto wirtualna (polimorfizm)
    
    int getId() const;
};