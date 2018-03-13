#pragma once
#include <string>

using namespace std;

class JeuVideo
{
public:
	JeuVideo(unsigned int _id, string _titre, string plateforme, unsigned int quantité);
	~JeuVideo();
	void Affiche();
	int GetQuantite();
	int GetID();

private:
	unsigned int id;
	string titre;
	string plateforme;
	unsigned int quantité;

	
};

