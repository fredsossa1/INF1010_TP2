#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <string>
#include <vector>
#include "Medecin.h"
#include "Infirmier.h"

using namespace std;

class Personnel
{
public:
	// Constructeur par defaut
	Personnel();

	// Destructeur
	~Personnel();
	
	// Methodes publiques
	bool ajouterMedecin(Medecin* medecin);
	bool retirerMedecin(const std::string& nom);
	bool ajouterInfirmier(Infirmier* infirmier);
	bool retirerInfirmier(const std::string& nom);

	Personnel& operator+=(Medecin* medecin);
	Personnel& operator-=(Medecin* medecin);
	Personnel& operator+=(Infirmier* infirmier);
	Personnel& operator-=(Infirmier* infirmier);
		
	void information() const; // A MODIFIER... (si necessaire)
	// _________TP2___________


	//friend ostream& operator<< (ostream& os, const Infirmier& unInfimier);
	//bool operator== (const Infirmier& unInfimier) const;
	//bool operator== (const string& nomComplet) const;

	//friend bool operator== (const string& nomComplet, const Infirmier& unInfimier);


private:
	void afficherInfirmiers() const; // A MODIFIER... (si necessaire)
	void afficherMedecins() const; // A MODIFIER... (si necessaire)

	// _________TP2___________
	vector <Medecin*> medecins_;
	vector <Infirmier*> infirmiers_;
};

#endif