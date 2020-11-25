#pragma once
#include "Cible.h"


class Capteur
{
private:
	int cout, id;
	std::vector<Cible*> cibles;

public:
	Capteur(void);
	Capteur(int id, int cout);
	void addCible(Cible* cible);
	std::vector<Cible*> getCibles(void);

	void set_id(int ID)
	{
		id = ID;
	}
	void set_cout(int COUT)
	{
		cout = COUT;
	}
	int get_id()
	{
		return id;
	}
	int get_cout()
	{
		return cout;
	}
};

