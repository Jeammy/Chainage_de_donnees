#pragma once
#include "Noeud.hpp"
#include "Livre.h"

using namespace std;
template<class T>
class Pile
{
public:
	Pile();
	~Pile();
	void Push(T* _contenue);
	T* Pop();
	void Affiche();
	Noeud<T>* GetPremierNoeud();
	int GetNbNoeuds();
private:
	Noeud<T>* premierNoeud;
	int nbNoeud;
};

template <class T>
Pile<T>::Pile()
{
	//TODO : Construction d'une pile = pile vide (voir spécifications)
	premierNoeud = NULL;
	nbNoeud = 0;
}

template <class T>
Pile<T>::~Pile()
{
	//TODO : Detruire la pile selon les spécifications
	while (Pop()){}
}

/// <summary>
/// Ajouter une contenue dans la liste.
/// </summary>
/// <param name="_contenue">le contenue à ajouter</param>
/// <returns></returns>
template <class T>
void Pile<T>::Push(T* _contenue)
{
	//TODO : Empiler selon les spécifications
	Noeud<T>* noeud = new Noeud<T>();
	noeud->SetContenue(_contenue);
	noeud->SetSuivant(premierNoeud);
	premierNoeud = noeud;
	nbNoeud++;
}

/// <summary>
/// Retirer le dernier contenue de la pile.
/// </summary>
/// <param name="_contenue">le contenue.</param>
/// <returns></returns>
template<class T>
T* Pile<T>::Pop()
{
	T * contenue = NULL;
	//TODO : Dépiler selon les spécifications
	if(premierNoeud != NULL)
	{
		Noeud<T>* noeudTempo = premierNoeud->GetSuivant();
		contenue = premierNoeud->GetContenue();
		delete premierNoeud;
		premierNoeud = noeudTempo;
		nbNoeud--;

	}
	return contenue;
}

/// <summary>
/// Affiche le contenue de la liste.
/// </summary>
template<class T>
void Pile<T>::Affiche()
{
	//TODO : Afficher toutes les données de la Pile
	if (premierNoeud)
	{
		premierNoeud->GetContenue()->Affiche();
		Noeud* noeudTempo = premierNoeud->GetSuivant();
		while (noeudTempo)
		{
			noeudTempo->GetContenue()->Affiche();
			noeudTempo = noeudTempo->GetSuivant();
		}
	}
	else
	{
		cout << "pile vide\n************" << endl;
	}
}

/// <summary>
/// Donne le premier noeud de la pile.
/// </summary>
/// <returns></returns>
template<class T>
Noeud<T>* Pile<T>::GetPremierNoeud()
{
	return premierNoeud;
}

/// <summary>
/// donne le nombre de contenue de la liste.
/// </summary>
/// <returns></returns>
template<class T>
int Pile<T>::GetNbNoeuds()
{
	return nbNoeud;
}

