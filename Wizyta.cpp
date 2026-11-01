#include "Wizyta.h"

Wizyta::Wizyta(std::shared_ptr<SlotCzasowy> przypisanySlot) 
    : status("Zaplanowana"), slot(przypisanySlot) {}

void Wizyta::zmienStatus(const std::string& nowyStatus) {
    status = nowyStatus;
}