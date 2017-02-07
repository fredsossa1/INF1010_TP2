#ifndef HOPITAL_H
#define HOPITAL_H

#include <string>
#include <vector>
#include "Personnel.h"
#include "Infirmier.h"

using namespace std;

class Hopital
{
public:
	//Constructeur par défaut et par paramètres
	Hopital();
	Hopital(string nom, Personnel* personnel);

	// Méthodes d'accès

	string obtenirNom() const;
	Personnel obtenirPersonnel() const;

	// Méthodes de modification
	void modifierNom(string& nom);
	void modifierPersonnel( Personnel* personnel);

	//Opérateurs de surcharge
	friend ostream& operator<< (ostream& os, const Hopital& unHopital);
	

	
private:

	string nom_;
	Personnel* personnel_;
};

#endif
