#pragma once
#include "Osoba.h"
#include "SlotCzasowy.h"
#include <vector>
#include <memory>

class Lekarz : public Osoba {
private:
    std::string numerPWZ;
    std::string specjalizacja;
    std::vector<std::shared_ptr<SlotCzasowy>> grafik;

public:
    Lekarz(std::string imie, std::string nazwisko, int id, std::string pwz, std::string specjalizacja);
    
    void wyswietlRole() const override;
    void dodajSlot(std::shared_ptr<SlotCzasowy> s);
    std::vector<std::shared_ptr<SlotCzasowy>>& getGrafik();
};