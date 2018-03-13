#pragma once
#include <vector>
#include "JeuVideo.h"
#include "Livre.h"


class Inventaire
{
public:


	//TODO : Convertir en une seule fonction template qui reçoit un vector en paramètre
	//     : Utilisez un itérateur pour parcourir les items
	//int GetQuantiteTotaleDeLivres();
	//int GetQuantiteTotaleDeJeux();

	//TODO : Convertir en une seule fonction template qui reçoit un vector en paramètre
	//     : Utilisez un itérateur pour parcourir les items
	//void AfficherInfosDesLivres();
	//void AfficherInfosDesJeux();


	template<class T>
	void AfficherInfos(T &data)
	{
		/*T::iterator iter;
		for (iter = data.begin(); iter < data.end(); iter++)
		{
			iter->Affiche();
		}*/
	}
	template<class T>
	int GetQuantiteTotale(T &data)
	{
		int quantite = 0;
		/*T::iterator iter;
		for (iter = data.begin(); iter < data.end(); iter++)
		{
			quantite += iter->GetQuantite();
		}*/
		return quantite;
	}
	
};


