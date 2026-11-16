#pragma once
#include <string>
#include <vector>
#include <memory>
#include "SlotCzasowy.h"

class Recepta;

class Wizyta {
private:
    std::string status;
    std::string opis;
    std::vector<std::shared_ptr<Recepta>> recepty;
    std::shared_ptr<SlotCzasowy> slot;

public:
    Wizyta(std::shared_ptr<SlotCzasowy> przypisanySlot);
    
    void zmienStatus(const std::string& nowyStatus);
    void dodajRecepte(std::shared_ptr<Recepta> r);
    std::shared_ptr<SlotCzasowy> getSlot() const;
    void wypisz() const;
};
