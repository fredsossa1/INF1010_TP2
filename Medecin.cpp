#include "Medecin.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

using namespace std;

//Constructeur par parametre
Medecin::Medecin(const string& nom, int horaires, Specialite* specialite): nom_(nom), horaires_(horaires), specialite_(specialite)
{
}

//Constructeur par copie
Medecin::Medecin(const Medecin& unMedecin) : nom_(unMedecin.nom_), horaires_(unMedecin.horaires_), specialite_(nullptr)
{
	specialite_ = new Specialite(unMedecin.specialite_->obtenirDomaine(), unMedecin.specialite_->obtenirNiveau());

}

//Destruceur
Medecin::~Medecin()
{
	delete specialite_;
}

//Methodes d'acces
string Medecin::obtenirNom() const
{
	return nom_;
}

int Medecin::obtenirHoraires() const
{
	return horaires_;
}

Specialite Medecin::obtenirSpecialite() const
{
	return *specialite_;
}

//Methodes de modification
void Medecin::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Medecin::modifierHoraires(int horaires)
{
	horaires_ = horaires;
}

void Medecin::modifierSpecialite(Specialite* specialite)
{
	specialite_ = specialite;
}

//Surcharge d'operateur
Medecin Medecin::operator=(const Medecin& unMedecin)
{
	if (this != &unMedecin) {

		delete specialite_;

		specialite_ = new Specialite(*(unMedecin.specialite_));
		nom_ = unMedecin.nom_;
		horaires_ = unMedecin.horaires_;

	}
	return (*this);
}

ostream& operator<<(ostream& o, const Medecin& unMedecin) 
{
	  o << "| " << unMedecin.nom_ << AFFICHER_ESPACE(espace_nom - unMedecin.nom_.size())
		<< " | " << AFFICHER_ESPACE(espace_horaires - std::to_string(unMedecin.horaires_).size()) << unMedecin.horaires_
		<< AFFICHER_ESPACE(espace_horaires)
		<< unMedecin.obtenirSpecialite() << endl; //Appel a l'operateur chevron de Specialite autto
}

bool Medecin::operator==(const Medecin& unMedecin) 
{
	bool estEgal = true;

	if (this != &unMedecin)
	{
		if ((*this).nom_ == unMedecin.nom_) 
			 estEgal = true;

		else estEgal = false;
	}
	return estEgal;
}

bool Medecin::operator==(const string& nom)
{
	bool estEgal = false;

	if ((*this).nom_ == nom)
	{
			estEgal = true;
	}
	return estEgal;
}

bool operator==(const string& nom, const Medecin& unMedecin)
{
	bool estEgal = false;

	if (nom == unMedecin.nom_)
	{
		estEgal = true;
	}
	return estEgal;
}