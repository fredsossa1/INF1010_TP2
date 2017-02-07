#include "Infirmier.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
#include "Const.h"

Infirmier::Infirmier() :nom_(""), prenom_(""), nbChambre_(0)
{

}

Infirmier::Infirmier(const string & nom, const string & prenom, unsigned int nbChambre): nom_(nom), prenom_(prenom), nbChambre_(nbChambre)
{
}


Infirmier::~Infirmier()
{
	
}

string Infirmier::obtenirNom() const
{
	return nom_;
}

string Infirmier::obtenirPrenom() const
{
	return prenom_;
}

unsigned int Infirmier::obtenirNbChambre() const
{
	return nbChambre_;
}

void Infirmier::modifierNom(const string & nom)
{
	nom_ = nom;
}

void Infirmier::modifierPrenom(const string & prenom)
{
	prenom_ = prenom;
}

void Infirmier::modifierNbChambre(unsigned int nbChambre)
{
	nbChambre_ = nbChambre;
}
string Infirmier::obtenirNomComplet() const
{
	//Faire une concaténation dans un string séparé par un espace
	string nomComplet = nom_ + " " + prenom_;
	return nomComplet;
}

// Opérateurs de surchage

 ostream& operator<< (ostream& os, const Infirmier& unInfirmier)
{
	os << "| " << unInfirmier.obtenirNomComplet() << AFFICHER_ESPACE(espace_nom - unInfirmier.obtenirNomComplet().size());
	os << " | " << AFFICHER_ESPACE(espace_chambre - std::to_string(unInfirmier.nbChambre_).size() / 2);
	os << unInfirmier.nbChambre_ << AFFICHER_ESPACE(espace_chambre);
	os << "|" << endl;
	return os;
}


bool Infirmier::operator== (const Infirmier& unInfimier) const
{
	if (this != &unInfimier)
	{
		bool estEgal = true;

		if (obtenirNomComplet() == unInfimier.obtenirNomComplet())
		{
			return estEgal;
		}
		else
			return false;
	}
	else
		return true;
}

bool Infirmier::operator== (const string& nomComplet) const
{
	if ((*this).obtenirNomComplet() == nomComplet)
		return true;
	else
		return false;

		/*for (int i = 0; i < obtenirNomComplet().size(); i++)
	{
		if (obtenirNomComplet()[i] == nomComplet[i])
			return true;
		else
			return false;
	}*/
}

bool operator== (const string& nomComplet, const Infirmier& unInfimier)
{
	if (unInfimier.obtenirNomComplet() == nomComplet)
		return true;
	else
		return false;
}


