#include "SystemPrzychodni.h"
#include <stdexcept>
#include <iostream>

void SystemPrzychodni::dodajPacjenta(std::shared_ptr<Pacjent> p) {
    listaPacjentow.push_back(p);
}

void SystemPrzychodni::dodajLekarza(std::shared_ptr<Lekarz> l) {
    listaLekarzy.push_back(l);
}

// Logika biznesowa: Sprawdzenie poprawności, rezerwacja slotu, przypisanie wizyty[cite: 3, 10]
void SystemPrzychodni::umowWizyte(int id_pacjenta, int id_lekarza, std::shared_ptr<SlotCzasowy> slot) {
    std::shared_ptr<Pacjent> docelowyPacjent = nullptr;
    
    // Wyszukanie pacjenta
    for (auto& p : listaPacjentow) {
        if (p->getId() == id_pacjenta) {
            docelowyPacjent = p;
            break;
        }
    }
    
    if (!docelowyPacjent) {
        throw std::invalid_argument("Nie znaleziono pacjenta w systemie.");
    }

    // Walidacja logiki domenowej - zablokowanie zarezerwowanego slotu[cite: 3]
    if (slot->isWolny()) {
        slot->zajmij();
        
        auto nowaWizyta = std::make_shared<Wizyta>(slot);
        listaWizyt.push_back(nowaWizyta);
        docelowyPacjent->dodajWizyte(nowaWizyta);
        
        std::cout << "Wizyta zostala pomyslnie umowiona." << std::endl;
    } else {
        throw std::logic_error("Wybrany termin jest niedostepny.");
    }
}