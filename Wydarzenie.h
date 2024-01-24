// Wydarzenie.h
#ifndef WYDARZENIE_H
#define WYDARZENIE_H

#include <string>

class Wydarzenie {
public:
	std::string nazwa;
	std::string data;
	std::string typ;
	int dostepneBilety;

	Wydarzenie(std::string n, std::string d, std::string t, int bilety);
};

#endif // WYDARZENIE_H
