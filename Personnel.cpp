#include "Medecin.h"
#include "Infirmier.h"
#include "Personnel.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

Personnel::Personnel() {}

Personnel::~Personnel() {};
	
bool Personnel::ajouterMedecin(Medecin* medecin)  
{
	for (int i = 0; i < (medecins_).size(); i++)
	{

	}
	//return true;
}

bool Personnel::retirerMedecin(const std::string& nom)
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

bool Personnel::retirerInfirmier(const std::string& nomComplet) 
{
	// A MODIFIER...
	return false;
}
	

void Personnel::information() const // A MODIFIER...
{
	personnel.afficherMedecins();
	personnel.afficherInfirmiers();
}

void Personnel::afficherMedecins() const // A MODIFIER... (si necessaire)
{
	string tabMed = "Tableau Medecins";
	string nom = "Nom";
	string horaires = "Horaires";
	string domaine = "Domaine Specialite";
	string niveau = "Niveau Specialite";

	std::cout << AFFICHER_ESPACE(espacement_medecin / 2) << tabMed 
		<< AFFICHER_ESPACE(espacement_medecin / 2) << endl;

	std::cout << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;

	std::cout << "| " << nom << AFFICHER_ESPACE(espace_nom - nom.size()) 
		<< " | " << horaires << AFFICHER_ESPACE(2*espace_horaires - horaires.size())
		<< " | " << domaine << AFFICHER_ESPACE(espace_domaine - domaine.size()) 
		<< " | " << AFFICHER_ESPACE(espace_niveau - niveau.size() / 2) << niveau
		<< AFFICHER_ESPACE(espace_niveau - niveau.size() / 2)
		<< "| " << endl;
		
	std::cout << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	for (size_t i = 0; i < medecins_.size(); i++)
	{	
		medecins_[i]->information();
		std::cout << endl;
	}
	std::cout << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	std::cout << AFFICHER_ESPACE(espacement_medecin + tabMed.size()) << endl;
}

void Personnel::afficherInfirmiers() const // A MODIFIER... (si necessaire)
{
	string tabInf = "Tableau Infimiers";
	string nomComplet = "Nom Complet";
	string nbChambre = "Nombre de Chambre";
	std::cout << AFFICHER_ESPACE(espacement_infirmier/2) << tabInf 
		<< AFFICHER_ESPACE(espacement_infirmier/2) << endl;
	std::cout << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;
	
	std::cout << "| " << nomComplet << AFFICHER_ESPACE(espace_nom - nomComplet.size())
		 << " | " << nbChambre << AFFICHER_ESPACE(2 * espace_chambre - nbChambre.size())
		 << " | " << endl;
	std::cout << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;

	for (size_t i = 0; i < infirmiers_.size(); i++)
	{
		infirmiers_[i]->information()
		std::cout << endl;
	}

	std::cout << AFFICHER_LINE(espacement_infirmier + tabInf.size());
}
