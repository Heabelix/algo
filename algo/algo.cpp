// algo.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>


#include "Capteur.h"

void lecture(std::string nameFile)
{
	
	//int nb_cibles, nb_capteurs;
	std::ifstream file(nameFile);
	if(file.is_open())
	{
		int param;

		file >> param;
		const int nb_cibles = param;

		file >> param;
		const int nb_capteurs = param;

		std::vector<Capteur*> capteurs(nb_capteurs);
		for (int index = 0; index < nb_capteurs; index++)
		{
			int cout;
			file >> cout;

			Capteur* capteur;
			capteur = new Capteur(index, cout);
			capteurs[index] = capteur;
			
		}
		for (int index_cible = 0; index_cible < nb_cibles; index_cible++)
		{
			int capteur_cible;
			file >> capteur_cible;

			Cible* cible;
			cible = new Cible(index_cible);

			for (int index_capteur = 0; index_capteur < capteur_cible; index_capteur++)
			{
				int id_capteur;
				file >> id_capteur;

				capteurs[id_capteur - 1]->addCible(cible);
			}	
		}
	}
}
int main()
{
	lecture("inst41.txt");
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
