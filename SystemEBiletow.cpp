// SystemEBiletow.cpp
#include "SystemEBiletow.h"
#include "Wydarzenie.h"
#include "Uzytkownik.h"
#include "Bilet.h"
#include "Platnosc.h"

void SystemEBiletow::zarejestrujUzytkownika(std::string nazwa, std::string haslo, Adres adr, std::string email, std::string imie, std::string nazwisko) {
	uzytkownicy.push_back(Uzytkownik(nazwa, haslo, adr, email, imie, nazwisko));
	std::cout << "Uzytkownik zarejestrowany pomyslnie.\n";
}

bool SystemEBiletow::zalogujUzytkownika(std::string nazwa, std::string haslo) {
	for (const Uzytkownik &uzytkownik : uzytkownicy) {
		if (uzytkownik.nazwaUzytkownika == nazwa && uzytkownik.getHaslo() == haslo) {
			std::cout << "Logowanie udane.\n";
			return true;
		}
	}
	std::cout << "Logowanie nieudane. Nieprawidlowa nazwa uzytkownika lub haslo.\n";
	return false;
}

void SystemEBiletow::przegladajWydarzeniaWedlugDaty(std::string data) const {
		std::cout << "Wydarzenia w dniu " << data << ":\n";
		for (const Wydarzenie &wydarzenie : wydarzenia) {
			if (wydarzenie.data == data) {
				std::cout << "Nazwa: " << wydarzenie.nazwa << ", Typ: " << wydarzenie.typ << ", Dostepne bilety: " << wydarzenie.dostepneBilety << "\n";
			}
		}
	}

void SystemEBiletow::przegladajWydarzeniaWedlugTypu(std::string typ) const {
		std::cout << "Wydarzenia typu " << typ << ":\n";
		for (const Wydarzenie &wydarzenie : wydarzenia) {
			if (wydarzenie.typ == typ) {
				std::cout << "Nazwa: " << wydarzenie.nazwa << ", Data: " << wydarzenie.data << ", Dostepne bilety: " << wydarzenie.dostepneBilety << "\n";
			}
		}
	}

bool SystemEBiletow::sprawdzDostepnoscBiletu(std::string nazwaWydarzenia, std::string kategoria) {
	for (const Wydarzenie &wydarzenie : wydarzenia) {
		if (wydarzenie.nazwa == nazwaWydarzenia && wydarzenie.dostepneBilety > 0) {
			return true;
		}
	}
	return false;
}

Bilet& SystemEBiletow::zarezerwujBilet(std::string nazwaWydarzenia, std::string kategoria, std::string miejsce, double cena) {
	for (Wydarzenie &wydarzenie : wydarzenia) {
		if (wydarzenie.nazwa == nazwaWydarzenia && wydarzenie.dostepneBilety > 0) {
			wydarzenie.dostepneBilety--;
			bilety.push_back(Bilet(nazwaWydarzenia, kategoria, miejsce, cena));
			std::cout << "Bilet zarezerwowany pomyslnie. Cena: " << cena << " PLN\n";
			return bilety.back();  // Zwraca referencje do ostatnio utworzonego biletu
		}
	}
	throw std::runtime_error("Rezerwacja biletu nieudana. Wydarzenie nie znalezione lub brak dostepnych biletów.");
}

void SystemEBiletow::dokonajPlatnosci(std::string metodaPlatnosci, Bilet &bilet) {
	platnosci.push_back(Platnosc(metodaPlatnosci, bilet.cena));
	std::cout << "Platnosc zaakceptowana. Kwota: " << bilet.cena << " PLN, Metoda platnosci: " << metodaPlatnosci << "\n";
}

void SystemEBiletow::generujRaport() {
	std::cout << "Raport sprzedazy biletow:\n";
	for (const Bilet &bilet : bilety) {
		std::cout << "Wydarzenie: " << bilet.wydarzenie << ", Kategoria: " << bilet.kategoria << ", Miejsce: " << bilet.miejsce << "\n";
	}
}

void SystemEBiletow::aktualizujDostepnoscBiletow(std::string nazwaWydarzenia, int nowaDostepnosc) {
	for (Wydarzenie &wydarzenie : wydarzenia) {
		if (wydarzenie.nazwa == nazwaWydarzenia) {
			wydarzenie.dostepneBilety = nowaDostepnosc;
			std::cout << "Aktualizacja dostepnosci biletow pomyslna.\n";
			return;
		}
	}
	std::cout << "Wydarzenie nie znalezione. Aktualizacja dostepnosci biletow nieudana.\n";
}

void SystemEBiletow::dodajWydarzenie(std::string nazwa, std::string data, std::string typ, int dostepneBilety) {
	wydarzenia.push_back(Wydarzenie(nazwa, data, typ, dostepneBilety));
	std::cout << "Wydarzenie dodane pomyslnie.\n";
}
