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
	friend ostream& operator<< (ostream& os, const Personnel& personnel);
		
	// _________TP2___________

private:
	void afficherInfirmiers(ostream & os) const;
	void afficherMedecins(ostream & os) const;

	// _________TP2___________
	vector <Medecin*> medecins_;
	vector <Infirmier*> infirmiers_;
};

#endif
