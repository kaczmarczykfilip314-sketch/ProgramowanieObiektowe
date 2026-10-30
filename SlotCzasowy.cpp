#include "SlotCzasowy.h"
#include <stdexcept>

SlotCzasowy::SlotCzasowy(Date od, Date doo) 
    : dataGodzinaOd(std::move(od)), dataGodzinaDo(std::move(doo)), czyWolny(true) {}

bool SlotCzasowy::isWolny() const {
    return czyWolny;
}

// Logika biznesowa zarządzania dostępnością
void SlotCzasowy::zajmij() {
    if (!czyWolny) {
        throw std::logic_error("Slot czasowy jest juz zajety.");
    }
    czyWolny = false;
}

void SlotCzasowy::zwolnij() {
    czyWolny = true;
}