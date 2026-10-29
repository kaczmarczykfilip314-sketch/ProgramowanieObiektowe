#pragma once
#include "Date.h"

class SlotCzasowy {
private:
    Date dataGodzinaOd;
    Date dataGodzinaDo;
    bool czyWolny;

public:
    SlotCzasowy(Date od, Date doo);
    
    bool isWolny() const;
    void zajmij();
    void zwolnij();
};