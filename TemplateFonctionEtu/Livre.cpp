#include <iostream>
#include "Livre.h"


Livre::Livre(unsigned int _noLivre, string _titre, string _auteur, unsigned int _quantité)
{
	id = _noLivre;
	titre = _titre;
	auteur = _auteur;
	quantité = _quantité;
}

Livre::~Livre()
{
}

int Livre::GetID()
{
	return id;
}

int Livre::GetQuantite()
{
	return quantité;
}


void Livre::Affiche()
{
		cout << "Numero : " << id << endl;
		cout << "Titre : " << titre << endl;
		cout << "Auteur : " << auteur << endl;
		cout << "Quantite : " << quantité << endl << endl;
}

bool Livre::operator<(Livre const& a)
{
	if (a.id==0)
	{
		return false;
	}
	return this->id<a.id;
}

bool Livre::operator>(Livre const& a)
{
	if (a.id == 0)
	{
		return true;
	}
	return this->id>a.id;
}

