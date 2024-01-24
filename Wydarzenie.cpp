// Wydarzenie.cpp
#include "Wydarzenie.h"

Wydarzenie::Wydarzenie(std::string n, std::string d, std::string t, int bilety)
	: nazwa(n), data(d), typ(t), dostepneBilety(bilety) {}
