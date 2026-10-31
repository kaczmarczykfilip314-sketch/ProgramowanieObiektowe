#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Recepta.h"
#include "SlotCzasowy.h"

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
};