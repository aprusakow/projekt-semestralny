// Uzytkownik.cpp
#include "Uzytkownik.h"
#include "Adres.h"

Uzytkownik::Uzytkownik(std::string nazwa, std::string haslo, Adres adr, std::string email, std::string im, std::string nazw)
	: nazwaUzytkownika(nazwa), haslo(haslo), adres(adr), email(email), imie(im), nazwisko(nazw) {}
