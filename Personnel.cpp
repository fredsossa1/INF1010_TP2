#include "Medecin.h"
#include "Infirmier.h"
#include "Personnel.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

using namespace std;

Personnel::Personnel() {}

Personnel::~Personnel() {};
	
bool Personnel::ajouterMedecin(Medecin* medecin)  
{
	bool ok = true;

	for (unsigned i = 0; i < medecins_.size(); i++)
	{
		if ((*medecins_[i]).obtenirNom() == (*medecin).obtenirNom())
			ok = false;
	}

	if (ok == true) medecins_.push_back(medecin);

	return ok;
}


bool Personnel::retirerMedecin(const string& nom)
{
	for (unsigned int i = 0; i < medecins_.size(); i++) {

		if ((*medecins_[i]).operator== (nom))
		{
			//(*medecins_[i]) = (*medecins_[medecins_.size() - 1]);
			medecins_[i] = medecins_[medecins_.size() - 1];

			medecins_.pop_back();
			return true;
		}
	}

	return false;
}

bool Personnel::ajouterInfirmier(Infirmier* infirmier)
{
	bool ok = true;

		for (unsigned int i = 0; i < infirmiers_.size(); i++) {

			if ((*infirmiers_[i]).obtenirNom() == (*infirmier).obtenirNom())
				ok = false;
		}

		if (ok == true) infirmiers_.push_back(infirmier);

	return ok;
}

bool Personnel::retirerInfirmier(const string& nomComplet) 
{
	for (unsigned i = 0; i < (infirmiers_).size(); i++)
	{
		if ((*infirmiers_[i]).operator== (nomComplet))
		{
			//(*infirmiers_[i]) = (*infirmiers_[infirmiers_.size()-1]);
			infirmiers_[i] = (infirmiers_[infirmiers_.size()-1]);

			infirmiers_.pop_back();
			return true;
		}
	
	}
	return false;
}
	
//Gestion de l'Affichage
ostream& operator<< (ostream& os, const Personnel& personnel)
{
	personnel.afficherMedecins(os);
	personnel.afficherInfirmiers(os);
	return os;
}

void Personnel::afficherMedecins(ostream & os) const // A MODIFIER... (si necessaire)
{
	string tabMed = "Tableau Medecins";
	string nom = "Nom";
	string horaires = "Horaires";
	string domaine = "Domaine Specialite";
	string niveau = "Niveau Specialite";

	os << AFFICHER_ESPACE(espacement_medecin / 2) << tabMed 
		<< AFFICHER_ESPACE(espacement_medecin / 2) << endl;

	os << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;

	os << "| " << nom << AFFICHER_ESPACE(espace_nom - nom.size()) 
		<< " | " << horaires << AFFICHER_ESPACE(2*espace_horaires - horaires.size())
		<< " | " << domaine << AFFICHER_ESPACE(espace_domaine - domaine.size()) 
		<< " | " << AFFICHER_ESPACE(espace_niveau - niveau.size() / 2) << niveau
		<< AFFICHER_ESPACE(espace_niveau - niveau.size() / 2)
		<< "| " << endl;
		
	os << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	for (size_t i = 0; i < medecins_.size(); i++)
	{	
		os<<(*medecins_[i])<< endl;
	}
	os << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	os << AFFICHER_ESPACE(espacement_medecin + tabMed.size()) << endl;
}

void Personnel::afficherInfirmiers(ostream & os) const // A MODIFIER... (si necessaire)
{
	string tabInf = "Tableau Infimiers";
	string nomComplet = "Nom Complet";
	string nbChambre = "Nombre de Chambre";
	os << AFFICHER_ESPACE(espacement_infirmier/2) << tabInf 
		<< AFFICHER_ESPACE(espacement_infirmier/2) << endl;
	os << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;
	
	os << "| " << nomComplet << AFFICHER_ESPACE(espace_nom - nomComplet.size())
		 << " | " << nbChambre << AFFICHER_ESPACE(2 * espace_chambre - nbChambre.size())
		 << " | " << endl;
	os << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;

	for (size_t i = 0; i < infirmiers_.size(); i++)
	{
		os<<(*infirmiers_[i])<< endl;
	}

	os << AFFICHER_LINE(espacement_infirmier + tabInf.size());
}

// Opérateurs de surcharge
Personnel& Personnel::operator+=(Medecin* medecin)
{
	if ((*this).ajouterMedecin(medecin)) 
		cout << "Le medecin " << (*medecin).obtenirNom() << " a ete ajoute." << endl;
	
	return *this;
}

Personnel& Personnel::operator-=(Medecin* medecin)
{
	if ((*this).retirerMedecin((*medecin).obtenirNom()))
		cout << "Le medecin " << (*medecin).obtenirNom() << " a ete retire." << endl;

	return (*this);
}

Personnel& Personnel::operator+=(Infirmier* infirmier)
{
		
	if ((*this).ajouterInfirmier(infirmier)) 
		cout << "L'infimier " << (*infirmier).obtenirNomComplet() << " a ete ajoute." << endl;
	
	return *this;
}

Personnel& Personnel::operator-=(Infirmier* infirmier)
{
	if ((*this).retirerInfirmier((*infirmier).obtenirNomComplet()))
		cout << "L'infimier " << (*infirmier).obtenirNomComplet() << " a ete retire." << endl;

	return (*this);
}

