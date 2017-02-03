#ifndef MEDECIN_H
#define MEDECIN_H

#include <string>
#include "Specialite.h"

using namespace std;

class Medecin 
{
public:

	// Constructeurs par parametre et par copie :
	Medecin(const string& nom, int horaires, Specialite* specialite);
	Medecin(const Medecin& unMedecin); 

	// Destructeur
	~Medecin(); 
	
	// Methodes d'acces
	string obtenirNom() const;
	int obtenirHoraires() const;
	Specialite obtenirSpecialite() const;
	
	// Methodes de modification
	void modifierNom(const string& nom);
	void modifierHoraires(int horaires);
	void modifierSpecialite(Specialite* specialite);
	
	//Surcharge d'operateur
	Medecin operator= (const Medecin& unMedecin);
	friend ostream& operator<<(ostream& o, const Medecin& unMedecin);
	bool operator==(const Medecin& unMedecin);
	bool operator==(const string& nom);
	friend bool operator==(const string& nom, const Medecin& unMedecin);


private:

	// Variables privees
	string nom_;
	int horaires_;
	Specialite* specialite_;
	
};

#endif