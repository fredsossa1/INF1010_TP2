/**************************************************
* Main.cpp
* Date: 31 janvier 2017
**************************************************/

#include <string>
#include <iostream>
#include "Infirmier.h"
#include "Medecin.h"
#include "Personnel.h"
#include "Hopital.h"
using namespace std;

int main()
{
	// C'est a vous de voir si vous devez allouer dynamiquement ou non les elements

	//1-  Creez 11 objets du type Infirmier � l'aide du constructeur par param�tre avec des valeurs de votre choix
	Infirmier* unInfirmier1 = new Infirmier("Ralay", "Taylor", 8);
	Infirmier* unInfirmier2 = new Infirmier("Batiste", "Susie", 3);
	Infirmier* unInfirmier3 = new Infirmier("Walker", "Christopher", 10);
	Infirmier* unInfirmier4 = new Infirmier("Elisabeth", "Matthieu", 5);
	Infirmier* unInfirmier5 = new Infirmier("Saint-Albin", "Jean", 6);
	Infirmier* unInfirmier6 = new Infirmier("Smith", "Alex", 11);
	Infirmier* unInfirmier7 = new Infirmier("Jackobs", "Vanessa", 9);
	Infirmier* unInfirmier8 = new Infirmier("Martel", "Jacques", 7);
	Infirmier* unInfirmier9 = new Infirmier("Pierre-Louis", "Kate", 2);
	Infirmier* unInfirmier10 = new Infirmier("Theodore", "Sacha", 12);
	Infirmier* unInfirmier11 = new Infirmier("Davidson", "Eleanor", 4);

	//2-  Creez deux objets du type Personnel � l'aide du constructeur par d�faut
	Personnel* lePersonnel1 = new Personnel();
	Personnel* lePersonnel2 = new Personnel();

	//3 - Creez deux objects de type Hopital qui vont prendre chacun en parametre le nom de l'hopital et le personnel assigné
	// Hopital Sacré-Coeur de Montréal
	// Hôpital Jean-Talon
	
	Hopital sacreCoeur = Hopital("Hopital Sacre-Coeur", lePersonnel1);
	Hopital jeanTalon = Hopital("Hopital Jean-Talon", lePersonnel2);

	cout << sacreCoeur.obtenirNom()<< endl;
	//4-  Ajoutez les 6 objets du type Infimier � au personnel de l'Hôpital Sacré-Coeur de Montréal

	lePersonnel1->operator+=(unInfirmier1);
	lePersonnel1->operator+=(unInfirmier2);
	lePersonnel1->operator+=(unInfirmier3);
	lePersonnel1->operator+=(unInfirmier4);
	lePersonnel1->operator+=(unInfirmier5);
	lePersonnel1->operator+=(unInfirmier6);

	sacreCoeur.modifierPersonnel(lePersonnel1);

	cout << endl << "__Ajout infimiers : ok__" << endl;
	//5-  Ajoutez les 5 objets qui restent du type Infimier � au personnel de l'Hôpital Jean-Talon
	cout << jeanTalon.obtenirNom() << endl;

	lePersonnel2->operator+=(unInfirmier7);
	lePersonnel2->operator+=(unInfirmier8);
	lePersonnel2->operator+=(unInfirmier9);
	lePersonnel2->operator+=(unInfirmier10);
	lePersonnel2->operator+=(unInfirmier11);

	jeanTalon.modifierPersonnel(lePersonnel2);


	//6-  Creez 7 objets du type Specialite � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// Specialites : Chirurgie, Demartologie, Gastrologie, Sport, Podologie, Pediatrie, Psychiatrie
	Specialite* uneSpecialite1 = new Specialite("Pediatrie", 3);
	Specialite* uneSpecialite2 = new Specialite("Ophtamologie", 4);
	Specialite* uneSpecialite3 = new Specialite("Deonthologie", 6);
	Specialite* uneSpecialite4 = new Specialite("Podologie", 7);
	Specialite* uneSpecialite5 = new Specialite("Dermatologie", 2);
	Specialite* uneSpecialite6 = new Specialite("Psychiatrie", 5);
	Specialite* uneSpecialite7 = new Specialite("Gastrologie", 11);

	cout << endl << "__Creation specialite : ok__" << endl;

	//7- Creez 7 autres objets du type Medecin � l'aide du constructeur par param�tre avec des valeurs de votre choix
	
	Medecin* Marcel = new Medecin("Marcel", 9, uneSpecialite1);
	Medecin* Patrice = new Medecin("Patrice", 12, uneSpecialite2);
	Medecin* Jack = new Medecin("Jack", 8, uneSpecialite3);
	Medecin* Sandy = new Medecin("Sandy", 11, uneSpecialite4);
	Medecin* Christelle = new Medecin("Christelle", 13, uneSpecialite5);
	Medecin* Holmes = new Medecin("Holmes", 13, uneSpecialite6);
	Medecin* Julian = new Medecin("Julian", 13, uneSpecialite7);

	cout << endl << "__Creation medecin : ok__" << endl;

	//8- Creer un autre medecin Jack en utilisant l'opérateur = et en utilisant le medecin Jack existant.
	// L'horaire du deuxieme Jack devrait ensuite etre modifie pour une valeur differnte du premier Jack
	
	Medecin* unMedecin1 = Jack;
	(*unMedecin1).modifierHoraires(20);

	cout << endl<< (*unMedecin1).obtenirNom()<< endl << "__Creation medecin op= : ok__" << endl;

	//9- Creer un autre medecin Sandy en utilisant le constructeur de copie et en utilisant le medecin Sandy existant.
	// L'horaire du deuxieme Sandy devrait ensuite etre modifie pour une valeur differente du premier Sandy
	Medecin* unMedecin2 = new Medecin((*Sandy));
	unMedecin2->modifierHoraires(30);

	cout << endl << (*unMedecin2).obtenirNom() << endl << "__Creation medecin par copie : ok__" << endl;

	//10- Ajoutez les medecins : parmis le personnel de l'hopital Sacré-Coeur : 
	// Dr. Franc, Dr. Sherlock, Dr. Holmes, Dr. Jean, Dr. Jules
	// A COMPLETER...
	// Dr. Sherlock(2), Dr. Holmes(2), Dr. Kyle, Dr. House
	lePersonnel1->operator+=(Marcel);
	lePersonnel1->operator+=(Patrice);
	lePersonnel1->operator+=(Jack);
	lePersonnel1->operator+=(Sandy);
	lePersonnel1->operator+=(Christelle);

	sacreCoeur.modifierPersonnel(lePersonnel1);

	cout << endl << "__Ajout medecins : ok__" << endl << endl;

	//11- Retirer le medecin Patrice et deux infirmiers de l'hopital Sacré-Coeur et ajouter les
	// a l'hopital Jean-talon
	lePersonnel1->operator-=(Patrice);
	lePersonnel1->operator-=(unInfirmier3);
	lePersonnel1->operator-=(unInfirmier5);

	sacreCoeur.modifierPersonnel(lePersonnel1);

	lePersonnel2->operator+=(Patrice);
	lePersonnel2->operator+=(unInfirmier3);
	lePersonnel2->operator+=(unInfirmier5);

	jeanTalon.modifierPersonnel(lePersonnel2);

	//12- Faites afficher l'hopital Sacré-Coeur puis Jean-Talon
	cout << sacreCoeur << endl;
	cout << jeanTalon << endl;

	return 0;
}
