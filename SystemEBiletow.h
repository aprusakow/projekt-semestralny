// SystemEBiletow.h

#pragma once

#include <iostream>
#include <vector>
#include <string>

class Wydarzenie;
class Uzytkownik;
class Bilet;
struct Adres;
struct Platnosc;

class SystemEBiletow {
private:
	std::vector<Uzytkownik> uzytkownicy;
	std::vector<Wydarzenie> wydarzenia;
	std::vector<Bilet> bilety;
	std::vector<Platnosc> platnosci;

public:
	void zarejestrujUzytkownika(std::string nazwa, std::string haslo, Adres adr, std::string email, std::string imie, std::string nazwisko);
	bool zalogujUzytkownika(std::string nazwa, std::string haslo);
	void przegladajWydarzeniaWedlugDaty(std::string data) const;
	void przegladajWydarzeniaWedlugTypu(std::string typ) const;
	bool sprawdzDostepnoscBiletu(std::string nazwaWydarzenia, std::string kategoria);
	Bilet& zarezerwujBilet(std::string nazwaWydarzenia, std::string kategoria, std::string miejsce, double cena);
	void dokonajPlatnosci(std::string metodaPlatnosci, Bilet &bilet);
	void generujRaport();
	void aktualizujDostepnoscBiletow(std::string nazwaWydarzenia, int nowaDostepnosc);
	void dodajWydarzenie(std::string nazwa, std::string data, std::string typ, int dostepneBilety);
};
