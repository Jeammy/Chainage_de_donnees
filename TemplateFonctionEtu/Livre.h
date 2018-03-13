#pragma once
#include <string>

using namespace std;

class Livre
{
public:
	Livre(unsigned int _id, string _titre, string _auteur, unsigned int quantité);
	~Livre();
	void Affiche();
	int GetID();
	int GetQuantite();
	bool operator<(Livre const& a);
	bool operator>(Livre const& a);
private:
	unsigned int id;
	string titre;
	string auteur;
	unsigned int quantité;

	
};

