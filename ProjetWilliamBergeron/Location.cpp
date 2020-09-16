// But : Écrire un programme qui calcule le montant d'un individu devra payer pour faire un voyage avec une voiture louée.
//		 *Il devra prendre compte du kilométrage parcouru et de la durée du voyage.
// Auteur : William Bergeron
// Date : 2020-09-16

#include <iostream>

using namespace std;

int main()
{

	setlocale(LC_ALL, "");

	// Déclaration des variables
	int nombreJour;
	int nombreKilo;
	double coutT;

	// Demande de jour loué
	std::cout << "Veuillez rentrer le nombre de jour que le client a louée sa voiture :";
	std::cin >> nombreJour;

	// Demande de kilomètres parcouru
	std::cout << "Veuillez rentrer le nombre de kilomètres que le client a parcouru :";
	std::cin >> nombreKilo;

	// Traduction des équations
	/*
	(nombreJour * 45) = Cout part jour de louage dont (45$ par jour de louage)
	(nombreKilo * 0, 076 * 1, 25) = Cout relier au gaz dont (0, 076 = 7,6L/100km) (1,25$/L)
	(nombreJour * 250 - nombreKilo * 0, 05) = Cout relier au kilomètres suplémentaire
	*/
	
	coutT = 0;
	// Il n'est pas possible que le client n'a pas louer la voiture
	if (nombreJour <= 0)
	{
		std::cout << "Le client ne peut pas louer la voiture zéro ou négatif jours." << endl << "Donc le cout du voyage s'élève à :0";
		return 0;
	}

	// Calcule du nombre de kilomètre supplémentaire si il en a
	if (nombreKilo > nombreJour * 250)
	{

		if (nombreKilo <= 0)
		{					
				// Le client a louer la voiture mais ne la pas utiliser... il doit quand même payer pour l'avoir louer
				coutT = 45 * nombreJour;		
		}
		else
		{
			// Calcule du prix avec des kilomètres supplémentaire
			coutT = (nombreKilo * 0.076 * 1.25) + nombreJour * 45 + ((nombreJour * 250) - (nombreKilo * 0.05));
			std::cout << "Le cout du voyage s'élève à :" << coutT;
		}

	}
	else
	{
		// Calcule du prix mais sans kilomètres suplémentaire (nombreJour * 250 - nombreKilo * 0,05)
		coutT = (nombreKilo * 0.076 * 1.25) + nombreJour * 45;

		std::cout << "Le cout du voyage s'élève à :" << coutT;
	}
	
	

	// Fin du programme
	return 0;
}

/* Plan de test		résultat
 2			450		132.75
 0			500		Le client ne peut pas louer la voiture zéro ou négatif jours.
 7			0		315
 0			0		Le client ne peut pas louer la voiture zéro ou négatif jours.
 -1			-5		Le client ne peut pas louer la voiture zéro ou négatif jours.
 -4			-600	Le client ne peut pas louer la voiture zéro ou négatif jours.
 4			800		256

*/