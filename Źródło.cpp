#include <iostream>
#include <vector>
#include <string>
#include "SystemEBiletow.h"
#include "Bilet.h"
#include "Uzytkownik.h"
#include "Wydarzenie.h"
#include "Adres.h"
#include "Platnosc.h"

using namespace std;


int main() {
	SystemEBiletow systemBiletow;

	// Przyk³adowe u¿ycie funkcji
	Adres adresUzytkownika{ "Warszawa", "00-001", "Aleje Jerozolimskie", "123", "45" };
	systemBiletow.zarejestrujUzytkownika("jan_kowalski", "haslo123", adresUzytkownika, "jan@example.com", "Jan", "Kowalski");
	systemBiletow.zalogujUzytkownika("jan_kowalski", "haslo123");


	systemBiletow.dodajWydarzenie("Koncert", "2024-02-01", "Muzyka", 1000);
	systemBiletow.dodajWydarzenie("Mecz", "2024-02-15", "Sport", 500);

	//U¿ytkownik mo¿e wybraæ preferowany sposób przegl¹dania wydarzeñ

	systemBiletow.przegladajWydarzeniaWedlugDaty("2024-02-01"); 
	systemBiletow.przegladajWydarzeniaWedlugTypu("Sport"); 

	if (systemBiletow.sprawdzDostepnoscBiletu("Koncert", "VIP")) {
		// Cena biletu jest teraz przekazywana podczas rezerwacji
		Bilet& zarezerwowanyBilet = systemBiletow.zarezerwujBilet("Koncert", "VIP", "A1", 150.0);

		// Dodanie p³atnosci za zarezerwowany bilet
		systemBiletow.dokonajPlatnosci("Karta kredytowa", zarezerwowanyBilet);
	}

	systemBiletow.generujRaport();

	systemBiletow.aktualizujDostepnoscBiletow("Koncert", 900);

	return 0;
}