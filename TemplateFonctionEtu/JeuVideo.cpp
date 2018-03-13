#include <iostream>
#include "JeuVideo.h"


JeuVideo::JeuVideo(unsigned int _id, string _titre, string _plateforme, unsigned int _quantité)
{
	id = _id;
	titre = _titre;
	plateforme = _plateforme;
	quantité = _quantité;
}


JeuVideo::~JeuVideo()
{
}

int JeuVideo::GetID()
{
	return id;
}

int JeuVideo::GetQuantite()
{
	return quantité;
}

void JeuVideo::Affiche()
{
		cout << "Numero : " << id << endl;
		cout << "Titre : " << titre << endl;
		cout << "Plateforme : " << plateforme << endl;
		cout << "Quantite : " << quantité << endl << endl;
}

