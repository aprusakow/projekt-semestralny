// Bilet.h
#ifndef BILET_H
#define BILET_H

#include <string>

class Bilet {
public:
	std::string wydarzenie;
	std::string kategoria;
	std::string miejsce;
	double cena;
	Bilet(std::string e, std::string c, std::string s, double cena);
};

#endif // BILET_H
