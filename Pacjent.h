#pragma once
#include "Osoba.h"
#include "Date.h"
#include "Wizyta.h"
#include <vector>
#include <memory>

class Pacjent : public Osoba {
private:
    std::string pesel;
    Date dataUrodzenia;
    std::vector<std::shared_ptr<Wizyta>> historiaWizyt;

public:
    Pacjent(std::string imie, std::string nazwisko, int id, std::string pesel, Date dataUrodzenia);
    
    void wyswietlRole() const override;
    void dodajWizyte(std::shared_ptr<Wizyta> w);
    void usunWizyte(std::shared_ptr<Wizyta> w);
};