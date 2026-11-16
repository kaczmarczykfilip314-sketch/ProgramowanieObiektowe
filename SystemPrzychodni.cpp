#include "SystemPrzychodni.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>

void SystemPrzychodni::dodajPacjenta(std::shared_ptr<Pacjent> p) {
    listaPacjentow.push_back(p);
}

void SystemPrzychodni::dodajLekarza(std::shared_ptr<Lekarz> l) {
    listaLekarzy.push_back(l);
}

void SystemPrzychodni::dodajSlot(int id_lekarza, std::shared_ptr<SlotCzasowy> slot) {
    katalogSlotowCzasowych.push_back(slot);
    
    auto it = std::find_if(listaLekarzy.begin(), listaLekarzy.end(),
        [id_lekarza](const std::shared_ptr<Lekarz>& l) { return l->getId() == id_lekarza; });
        
    if (it != listaLekarzy.end()) {
        (*it)->dodajSlot(slot); 
    }
}

bool SystemPrzychodni::usunSlot(int id_lekarza, std::shared_ptr<SlotCzasowy> slot) {
    if (!slot->isWolny()) return false;
    
    auto itL = std::find_if(listaLekarzy.begin(), listaLekarzy.end(),
        [id_lekarza](const std::shared_ptr<Lekarz>& l) { return l->getId() == id_lekarza; });
        
    if (itL != listaLekarzy.end()) {
        (*itL)->usunSlot(slot);
    }
    
    katalogSlotowCzasowych.erase(
        std::remove(katalogSlotowCzasowych.begin(), katalogSlotowCzasowych.end(), slot), 
        katalogSlotowCzasowych.end());
        
    return true;
}

void SystemPrzychodni::umowWizyte(int id_pacjenta, int id_lekarza, std::shared_ptr<SlotCzasowy> slot) {
    auto pacjentIt = std::find_if(listaPacjentow.begin(), listaPacjentow.end(),
        [id_pacjenta](const std::shared_ptr<Pacjent>& p) { return p->getId() == id_pacjenta; });

    if (pacjentIt == listaPacjentow.end()) {
        throw std::logic_error("Nie znaleziono pacjenta.");
    }
    
    std::shared_ptr<Pacjent> docelowyPacjent = *pacjentIt;

    if (slot->isWolny()) {
        slot->zajmij();
        auto nowaWizyta = std::make_shared<Wizyta>(slot);
        listaWizyt.push_back(nowaWizyta);
        docelowyPacjent->dodajWizyte(nowaWizyta);
        
        std::cout << "Wizyta zostala pomyslnie umowiona (sukces: true)." << std::endl;
    } else {
        std::cout << "Wybrany termin jest niedostepny (porazka: false)." << std::endl;
    }
}

bool SystemPrzychodni::anulujWizyte(int id_pacjenta, std::shared_ptr<Wizyta> wizyta) {
    auto pacjentIt = std::find_if(listaPacjentow.begin(), listaPacjentow.end(),
        [id_pacjenta](const std::shared_ptr<Pacjent>& p) { return p->getId() == id_pacjenta; });

    if (pacjentIt != listaPacjentow.end()) {
        (*pacjentIt)->usunWizyte(wizyta);
        wizyta->zmienStatus("Odwołana");
        wizyta->getSlot()->zwolnij();
        std::cout << "Wizyta zostala anulowana." << std::endl;
        return true;
    }
    return false;
}

void SystemPrzychodni::wystawRecepte(int id_lekarza, std::shared_ptr<Wizyta> wizyta, std::shared_ptr<Recepta> r) {
    katalogRecept.push_back(r);
    wizyta->dodajRecepte(r);
    std::cout << "Recepta zostala wystawiona." << std::endl;
}
