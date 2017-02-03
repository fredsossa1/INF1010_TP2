#include "Specialite.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

using namespace std;


Specialite::Specialite()
{
	domaine_= "";
	niveau_= 0;
}

Specialite::Specialite(const std::string & domaine, unsigned int niveau) : domaine_(domaine), niveau_(niveau) 
{
}

std::string Specialite::obtenirDomaine() const
{
	return domaine_;
}

unsigned int Specialite::obtenirNiveau() const
{
	return niveau_;
}

void Specialite::modifierDomaine(const std::string & domaine)
{
	domaine_ = domaine;
}

void Specialite::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}


ostream& operator<<(ostream& o, const Specialite& specialite) //quand appel fonction : parametre o prend cout automatiquement quand on appelle avec une spe par parametre
{
	o << " | " << specialite.obtenirDomaine() << AFFICHER_ESPACE(espace_domaine - specialite.obtenirDomaine().size())
	  << " | " << AFFICHER_ESPACE(espace_niveau - std::to_string(specialite.obtenirNiveau()).size()) << specialite.obtenirNiveau()
	  << AFFICHER_ESPACE(espace_niveau) << " | ";

	return o;
}