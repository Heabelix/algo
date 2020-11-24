// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

int nbCibles;
int nbCapteurs;
int* coutCapteur;
int** matrice;

void writeLpFile()
{
    ofstream lpFile;
    lpFile.open("C:\\Users\\clair\\OneDrive\\Documents\\Valentin\\result.dat");

    lpFile << "data;\n";
    lpFile << "#nombre de cibles\n";
    lpFile << "param M := " << nbCibles << ";\n";
    lpFile << "# Capteurs\n";
    lpFile << "param N := " << nbCapteurs << ";\n";

    lpFile << "#Cible par capteur\n";
    lpFile << "param d: ";
    for (int i = 0; i < nbCapteurs; i++)
    {
        lpFile << i + 1 << " ";
    }
    lpFile << ":=\n";

    for (int i = 0; i < nbCibles; i++)
    {
        lpFile << i + 1 << " ";
        for (int j = 0; j < nbCapteurs; j++)
        {
            lpFile << matrice[i][j] << " ";
        }
        if (i + 1 < nbCibles)
        {
            lpFile << "\n";
        }
        else
        {
            lpFile << ";\n";
        }
    }

    lpFile << "#cout capteur\n";
    lpFile << "param v := ";
    for (int i = 0; i < nbCapteurs; i++)
    {
        lpFile << i + 1 << " " << coutCapteur[i];
        if (i + 1 < nbCapteurs)
        {
            lpFile << "\n";
        }
        else
        {
            lpFile << ";\n";
        }
    }
    lpFile << "end;\n";
    lpFile.close();
}

int main()
{
    ifstream confFile;
    confFile.open("C:\\Users\\clair\\OneDrive\\Documents\\Valentin\\inst42.txt");
    confFile >> nbCibles;
    confFile >> nbCapteurs;

    printf("Cibles %d\n", nbCibles);
    matrice = new int* [nbCibles];
    for (int i = 0; i < nbCibles; i++)
    {
        matrice[i] = nullptr;
        matrice[i] = new int[nbCapteurs];
    }
    for (int i = 0; i < nbCibles; i++)
        for (int j = 0; j < nbCapteurs; j++)
        {
            matrice[i][j] = 0;
        }
    coutCapteur = new int[nbCapteurs];
    for (int i = 0; i < nbCapteurs; i++)
    {
        confFile >> coutCapteur[i];
    }

    for (int cible = 0; cible < nbCibles; cible++)
    {
        int nbCapteurCible;
        confFile >> nbCapteurCible;
        for (int capteurIndex = 0; capteurIndex < nbCapteurCible; capteurIndex++)
        {
            int capteur;
            confFile >> capteur;
            matrice[cible][capteur - 1] = 1;
        }
    }

    confFile.close();

    for (int i = 1; i <= nbCapteurs; i++)
    {
        cout << i << ":" << coutCapteur[i - 1] << " , ";
        if (i % 12 == 0)
        {
            cout << "\n";
        }
    }

    cout << "\n";
    // for (int cible = 0; cible < 10; cible++)
    // {
    //   cout << cible << " [";
    //   for (int capteurIndex = 0; capteurIndex < 92; capteurIndex++)
    //   {
    //     cout << matrice[cible][capteurIndex] << " ";
    //   }
    //   cout << "]\n";
    // }

    writeLpFile();
    return 0;
}