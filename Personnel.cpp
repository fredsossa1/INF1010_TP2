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
	for (unsigned i = 0; i < (medecins_).size(); i++)
	{
		if ((*medecins_[i]) == (*medecin))
			return false;
		else
		{
			medecins_.push_back(medecin);
			return true;
		}
	}

}

bool Personnel::retirerMedecin(const string& nom)
{
	bool ok = false;

	for (unsigned int i = 0; i < medecins_.size(); i++) {

		if ((*medecins_[i]) == nom)
		{
			(*medecins_[i]) = (*medecins_[medecins_.size() - 1]);
			//medecins_[i] = medecins_[medecins_.size() - 1];

			medecins_.pop_back();
			ok = true;
		}
	}

	return ok;
}

bool Personnel::ajouterInfirmier(Infirmier* infirmier)
{

	for (unsigned int i = 0; i < infirmiers_.size(); i++) {

		if ((*infirmiers_[i]) == (*infirmier))
			return false;

		else
		{
			infirmiers_.push_back(infirmier);
			return true;
		}
	}
}

bool Personnel::retirerInfirmier(const string& nomComplet) 
{
	for (unsigned i = 0; i < (infirmiers_).size(); i++)
	{
		if ((*infirmiers_[i]) == nomComplet)
		{
			(*infirmiers_[i]) = (*infirmiers_[infirmiers_.size()-1]);
			//infirmiers_[i] = (infirmiers_[infirmiers_.size()]);
			infirmiers_.pop_back();
			return true;
		}
		else
			return false;
	}
}
	
ostream& operator<< (ostream& os, const Personnel& personnel)
{
	personnel.afficherMedecins(os);
	personnel.afficherInfirmiers(os);
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
		os<<medecins_[i]<< endl;
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
		os<<infirmiers_[i]<< endl;
	}

	os << AFFICHER_LINE(espacement_infirmier + tabInf.size());
}

// Opérateurs de surcharge
Personnel& Personnel::operator+=(Medecin* medecin)
{
	(*this).ajouterMedecin(medecin); // Verifier si c'est vraiment nécessaire d'utiliser this
	return *this;
}

Personnel& Personnel::operator-=(Medecin* medecin)
{
	(*this).retirerMedecin((*medecin).obtenirNom); // Verifier si c'est vraiment nécessaire d'utiliser this
	return (*this);
}

Personnel& Personnel::operator+=(Infirmier* infirmier)
{
	(*this).ajouterInfirmier(infirmier); // Verifier si c'est vraiment nécessaire d'utiliser this
	return *this;
}

Personnel& Personnel::operator-=(Infirmier* infirmier)
{
	(*this).retirerInfirmier((*infirmier).obtenirNomComplet); // Verifier si c'est vraiment nécessaire d'utiliser this
	return (*this);
}

