#include "Capteur.h"

Capteur::Capteur(void)
{
	this->id   = 0;
	this->cout = 0;
}

Capteur::Capteur(int id, int cout) 
{
		this->id   = id + 1;
		this->cout = cout;
}

void Capteur::addCible(Cible* cible) 
{
		this->cibles.push_back(cible);
}

std::vector<Cible*> Capteur::getCibles(void) 
{
		return this->cibles;
}