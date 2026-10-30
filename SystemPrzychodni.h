#pragma once
#include <vector>
#include <memory>
#include "Pacjent.h"
#include "Lekarz.h"
#include "Recepta.h"
#include "SlotCzasowy.h"
#include "Wizyta.h"

class SystemPrzychodni {
private:
    std::vector<std::shared_ptr<Pacjent>> listaPacjentow;
    std::vector<std::shared_ptr<Lekarz>> listaLekarzy;
    std::vector<std::shared_ptr<Recepta>> katalogRecept;
    std::vector<std::shared_ptr<SlotCzasowy>> katalogSlotowCzasowych;
    std::vector<std::shared_ptr<Wizyta>> listaWizyt;

public:
    void umowWizyte(int id_pacjenta, int id_lekarza, std::shared_ptr<SlotCzasowy> slot);
    bool anulujWizyte(int id_pacjenta, std::shared_ptr<Wizyta> wizyta);
    void dodajPacjenta(std::shared_ptr<Pacjent> p);
    void dodajLekarza(std::shared_ptr<Lekarz> l);
};