#ifndef SPECIALITE_H
#define SPECIALITE_H

#include <string>
#include <iostream>

class Specialite
{
public:
	Specialite();

	Specialite(const std::string& domaine, unsigned int niveau);

	std::string obtenirDomaine() const;
	unsigned int obtenirNiveau() const;

	void modifierDomaine(const std::string& domaine);
	void modifierNiveau(unsigned int niveau);

	// _________TP2___________
	friend ostream& operator<<(ostream& o, const Specialite& specialite) ; //Operateur << doivent etre en friend pour etre appeler en chaine
	
private:
	std::string domaine_;
	unsigned int niveau_;
};

#endif