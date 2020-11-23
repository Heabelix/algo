#include "Capteur.h"

Capteur::Capteur(void)
{

}

Capteur::Capteur(int id, int cout) 
{
		this->id   = id;
		this->cout = cout;
}

void Capteur::addCible(Cible cible) 
{
		this->cibles.push_back(cible);
}

std::vector<Cible> Capteur::getCibles(void) 
{
		return this->cibles;
}