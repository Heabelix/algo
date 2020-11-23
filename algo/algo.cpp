// algo.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>


#include "Capteur.h"

void lecture(std::string nameFile)
{
	
	int nb_cibles, nb_capteurs;
	std::ifstream file(nameFile);
	if(file)
	{
		file >> nb_cibles;
		file >> nb_capteurs;
		const int nb_capteurs2 = nb_capteurs;
		Capteur capteurs[nb_capteurs2];
		for (int index=1;index<=nb_capteurs;index++)
		{
			int cout;
			file >> cout;
			Capteur capteur(index, cout);
			capteurs[index] = capteur;
			
		}
		for (int index = 1; index <= nb_cibles; index++)
		{
			int capteur_cible;
			file >> capteur_cible;
			for (int index2 = 1; index2<=capteur_cible;index2++)
			{
				int id_capteur;
				file >> id_capteur;
				Cible cible(index);
				capteurs[id_capteur].addCible(cible);
			}
			
			
		}
	}
}
int main()
{
    
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
