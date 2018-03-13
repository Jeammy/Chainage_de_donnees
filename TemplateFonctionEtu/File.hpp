#pragma once
#include "Noeud.hpp"


template<class T>
class File
{
public:
	File();
	~File();
	void Ajouter(T* _contenue);
	T* Retirer();
	void Affiche();
	int GetNbNoeud();

private:
	Noeud<T>* premierNoeud;
	Noeud<T>* dernierNoeud;
	int nbNoeud;
};

template<class T>
File<T>::File()
{
	//TODO : Compléter le code de construction
	premierNoeud = NULL;
	dernierNoeud = NULL;
	nbNoeud = 0;
}

template<class T>
File<T>::~File()
{
	//TODO : Compléter le code de destruction
	while (Retirer());
}

/// <summary>
/// Ajouter une contenue dans la liste.
/// </summary>
/// <param name="_contenue">le contenue à ajouter</param>
/// <returns></returns>
template<class T>
void File<T>::Ajouter(T* _contenue)
{
	//TODO : Compléter le code d'ajout
	Noeud<T>* noeud = new Noeud<T>();
	noeud->SetContenue(_contenue);
	if (premierNoeud == NULL)
	{
		premierNoeud = noeud;
		dernierNoeud = noeud;
		dernierNoeud->SetSuivant(NULL);
	}
	else
	{
		dernierNoeud->SetSuivant(noeud);
		dernierNoeud = noeud;
		dernierNoeud->SetSuivant(NULL);
	}
	nbNoeud++;
}

/// <summary>
/// Retirer le premier contenue de la file.
/// </summary>
/// <param name="_contenue">le contenue.</param>
/// <returns></returns>
template<class T>
T* File<T>::Retirer()
{
	//TODO : Compléter le code de retrait
	T* contenue = NULL;
	if (premierNoeud)
	{
		if (premierNoeud->GetSuivant())
		{
			Noeud<T>* noeudTempo = premierNoeud->GetSuivant();
			contenue = premierNoeud->GetContenue();
			delete premierNoeud;
			premierNoeud = noeudTempo;
		}
		else
		{
			contenue = premierNoeud->GetContenue();
			delete premierNoeud;
			premierNoeud = NULL;
		}
		nbNoeud--;
	}
	return contenue;
}

/// <summary>
/// Affiche le contenue de la liste.
/// </summary>
template<class T>
void File<T>::Affiche()
{
	//TODO : Compléter le code d'affichage
	if (premierNoeud)
	{
		premierNoeud->GetContenue()->Affiche();
		Noeud<T>* noeudTempo = premierNoeud->GetSuivant();
		while (noeudTempo)
		{
			noeudTempo->GetContenue()->Affiche();
			noeudTempo = noeudTempo->GetSuivant();
		}
	}
}

/// <summary>
/// donne le nombre de contenue de la liste.
/// </summary>
/// <returns></returns>
template<class T>
int File<T>::GetNbNoeud()
{
	return nbNoeud;
}