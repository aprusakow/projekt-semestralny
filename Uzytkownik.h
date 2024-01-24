// Uzytkownik.h

#pragma once
#include "Adres.h"
#include <string>


class Uzytkownik {
protected:
	std::string haslo;
	std::string imie;
	std::string nazwisko;
	std::string email;
	Adres adres;

public:
	std::string nazwaUzytkownika;
	Uzytkownik(std::string nazwa, std::string haslo, Adres adr, std::string mail, std::string im, std::string nazw);
	std::string getHaslo() const {
		return haslo;
	}
};
