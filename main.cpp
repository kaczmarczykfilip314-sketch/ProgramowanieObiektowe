#include <iostream>
#include <memory>
#include "SystemPrzychodni.h"
#include "Pacjent.h"
#include "Lekarz.h"
#include "SlotCzasowy.h"
#include "PozycjaRecepty.h"
#include "Recepta.h"

using namespace std;

void wypiszStory(const string& numer, const string& tresc) {
    cout << "\n======================================================================\n";
    cout << " " << numer << "\n " << tresc << "\n";
    cout << "======================================================================\n";
}

int main() {
    SystemPrzychodni system;
    auto pacjent = make_shared<Pacjent>("Jan", "Kowalski", 1, "90010112345", "1990-01-01");
    auto lekarz = make_shared<Lekarz>("Anna", "Nowak", 101, "PWZ123", "Kardiolog");
    system.dodajPacjenta(pacjent);
    system.dodajLekarza(lekarz);

    auto slot1 = make_shared<SlotCzasowy>("2026-11-20 10:00", "2026-11-20 10:30");
    auto slot2 = make_shared<SlotCzasowy>("2026-11-21 12:00", "2026-11-21 12:30");
    system.dodajSlot(101, slot1);
    system.dodajSlot(101, slot2);

    wypiszStory("USER STORY 1", 
                "Jako: Pacjent\n Chce: Wybrac lekarza i termin wizyty\n Aby: System mogl przypisac lekarza i zarezerwowac wolny slot czasowy");
    cout << ">> Pacjent Jan Kowalski (ID: 1) rezerwuje wolny termin u dr Anny Nowak (ID: 101):\n";
    system.umowWizyte(1, 101, slot1);
    cout << ">> Weryfikacja: Czy slot1 po rezerwacji jest wolny? " << (slot1->isWolny() ? "TAK" : "NIE") << "\n";


    wypiszStory("USER STORY 2", 
                "Jako: Lekarz\n Chce: Moc zobaczyc przyszle wizyty\n Aby: Pojawic sie na wizycie");
    cout << ">> Lekarz sprawdza swoj grafik (zablokowane sloty oznaczaja zaplanowane wizyty):\n";
    for(size_t i = 0; i < lekarz->getGrafik().size(); ++i) {
        auto s = lekarz->getGrafik()[i];
        cout << "   - Termin nr " << i+1 << " | Czy wolny? " << (s->isWolny() ? "TAK" : "NIE (Zaplanowana wizyta)") << "\n";
    }


    wypiszStory("USER STORY 3", 
                "Jako: Lekarz\n Chce: Wystawic recepte\n Aby: Pojawila sie ona pacjentowi w pozycji recept");
    cout << ">> Lekarz przeprowadza wizyte nr 1 i wystawia e-recepte...\n";
    auto recepta = make_shared<Recepta>("R-12345", "2026-11-20");
    recepta->dodajPozycje(PozycjaRecepty("Aspiryna", "1 tabl.", 30));
    
    auto zrealizowanaWizyta = pacjent->getHistoriaWizyt().front(); 
    system.wystawRecepte(101, zrealizowanaWizyta, recepta);
    zrealizowanaWizyta->zmienStatus("Zakonczona");
    
    cout << "\n>> Pacjent sprawdza podsumowanie wizyty wraz z przypisanymi receptami:\n";
    zrealizowanaWizyta->wypisz(); 


    wypiszStory("USER STORY 4", 
                "Jako: Pacjent\n Chce: Miec mozliwosc odwolania wizyty\n Aby: Zwolnic slot w systemie i udostepnic go innym pacjentom");
    cout << ">> Pacjent umawia sie na kolejny termin (slot2):\n";
    system.umowWizyte(1, 101, slot2);
    
    cout << "\n>> Pacjent zmienia zdanie i odwoluje wizyte:\n";
    auto wizytaDoAnulowania = pacjent->getHistoriaWizyt().back();
    system.anulujWizyte(1, wizytaDoAnulowania);
    
    cout << ">> Weryfikacja: Czy slot2 jest ponownie wolny po anulowaniu? " << (slot2->isWolny() ? "TAK" : "NIE") << "\n";

    wypiszStory("USER STORY 5", 
                "Jako: Lekarz\n Chce: Usunac wolny termin ze swojego grafiku\n Aby: Zablokowac mozliwosc rezerwacji w przypadku mojej nieobecnosci");
    
    cout << ">> Lekarz dowiaduje sie o naglym wyjezdzie i usuwa zwolniony przed chwila slot2 ze swojego grafiku:\n";
    bool usunieto = system.usunSlot(101, slot2);
    cout << ">> Weryfikacja: Czy udalo sie usunac slot z systemu? " << (usunieto ? "TAK" : "NIE") << "\n";
    
    cout << "\n>> Aktualny rozmiar grafiku lekarza: " << lekarz->getGrafik().size() << " terminow.\n";
    cout << ">> Proba usuniecia zajetego slotu (slot1):\n";
    bool usunietoZajety = system.usunSlot(101, slot1);
    cout << ">> Weryfikacja: Czy udalo sie usunac ZAJETY slot z systemu? " << (usunietoZajety ? "TAK" : "NIE (Odrzucono - zablokowane logiką)") << "\n";


    return 0;
}
