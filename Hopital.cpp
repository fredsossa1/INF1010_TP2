#include "Hopital.h"
#include <iostream>
#include <iomanip>


using namespace std;


//Constructeurs par défaut et par paramètres

Hopital::Hopital() : nom_(""), personnel_(nullptr)
{

}

Hopital::Hopital(string nom, Personnel* personnel) : nom_(nom), personnel_(personnel)
{

}


// Méthodes d'accès

string Hopital::obtenirNom() const
{
	return nom_;
}
Personnel Hopital::obtenirPersonnel() const
{
	return *personnel_;
}


// Méthodes de modification

void Hopital::modifierNom(string& nom) 
{
	nom_=nom;
}
void Hopital::modifierPersonnel(Personnel* personnel)
{
	personnel_ = personnel;
}

ostream& operator<< (ostream& os, const Hopital& unHopital)
{
	os << '\n' << setw(97)<< setfill('=') << '\n';
	os <<  setfill(' ') << setw(60) << right << unHopital.obtenirNom() << endl;
	os << setw(97) << setfill('=') << '\n' << '\n';
	os << unHopital.obtenirPersonnel() << '\n' << endl;
	return os;
}
