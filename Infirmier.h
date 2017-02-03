#ifndef INFIRMIER_H
#define INFIRMIER_H

#include <string>
#include <iostream>
using namespace std;
class Infirmier
{
public:
	Infirmier(); 
	Infirmier(const string& nom, const string& prenom, unsigned int nbChambre); 
	~Infirmier();

	string obtenirNom() const; 
	string obtenirPrenom() const;
	unsigned int obtenirNbChambre() const;


	void modifierNom(const string& nom);
	void modifierPrenom(const string& prenom);
	void modifierNbChambre(unsigned int nbChambre);

	// Constructeur qui renvoie le nom complet 
	string obtenirNomComplet() const;

	//Opérateurs de la classe
	 friend ostream& operator<< ( ostream& os, const Infirmier& unInfimier);
	bool operator== (const Infirmier& unInfimier) const;
	bool operator== (const string& nomComplet) const;

	friend bool operator== (const string& nomComplet, const Infirmier& unInfimier );

private:
	string nom_;
	string prenom_;
	unsigned int nbChambre_;
};

#endif
