#pragma once
#include "Noeud.hpp"

template<class T>
class List
{
public:
	List();
	~List();
	bool Ajouter(T* _livre);
	bool Retirer(T* _livre);
	void Affiche();
	int GetNbNoeud();
private:
	Noeud<T>* premierNoeud;
	int nbNoeud;
};

template<class T>
List<T>::List()
{
	premierNoeud = NULL;
	nbNoeud = 0;
}

template<class T>
List<T>::~List()
{
	//TODO
	do
	{
		Noeud<T>* noeudTemp = premierNoeud->GetSuivant();
		delete premierNoeud;
		premierNoeud = noeudTemp;
	}while (premierNoeud != NULL);
}


/// <summary>
/// Ajouter une contenue dans la liste.
/// </summary>
/// <param name="_contenue">le contenue à ajouter</param>
/// <returns></returns>
template<class T>
bool List<T>::Ajouter(T* _contenue){
	if (_contenue != NULL)
	{
		Noeud<T>* noeud = new Noeud<T>();
		noeud->SetContenue(_contenue);
		//verifie si c'est le premier noeud.
		if (premierNoeud == NULL)
		{
			premierNoeud = noeud;
			premierNoeud->SetSuivant(premierNoeud);
			premierNoeud->SetPrecedent(premierNoeud);
		}
		else
		{
			Noeud<T>* noeudTemp = new Noeud<T>();
			noeudTemp = premierNoeud;
			//Vérification si le Livre existe déja.
			do
			{
				if (noeudTemp->GetContenue() == _contenue){ return false; }
				else(noeudTemp = noeudTemp->GetSuivant());
			} while (noeudTemp != premierNoeud);
			//compare le contenue a ajouter aux elements deja present de la liste et l'ajoute au bon endroit.
			//commence par comparer le premier noeud.
			noeudTemp = premierNoeud;
			if (*(noeudTemp->GetContenue()) > *(noeud->GetContenue()))
			{
				noeud->SetSuivant(premierNoeud);
				noeud->SetPrecedent(premierNoeud->GetPrecedent());
				premierNoeud->SetPrecedent(noeud);
				if (premierNoeud->GetSuivant() == premierNoeud)
				{
					premierNoeud->SetSuivant(noeud);
				}
				premierNoeud = noeud;
				return true;
			}
			//ensuite le reste de la liste
			do
			{
				//----------------------------------------------------
				//operateur, le contenue a ajouter doit être plus grand que celui deja present.
				if (*(noeudTemp->GetContenue()) < *(noeud->GetContenue()))
				{

					//si on est a la fin de la liste on ajoute a la fin.
					if (noeudTemp->GetSuivant() == premierNoeud)
					{
						noeud->SetSuivant(premierNoeud);
						noeud->SetPrecedent(noeudTemp);
						noeudTemp->SetSuivant(noeud);
						premierNoeud->SetPrecedent(noeud);
						return true;
					}
				}
				//si le noeud est plus petit que le noeud actuel(noeudTemp) on ajoute le noeud dans la liste.
				else if (*(noeudTemp->GetContenue()) > *(noeud->GetContenue()))
				{
					noeud->SetSuivant(noeudTemp);
					noeud->SetPrecedent(noeudTemp->GetPrecedent());
					noeudTemp->GetPrecedent()->SetSuivant(noeud);
					noeudTemp->SetPrecedent(noeud);
				}
				noeudTemp = noeudTemp->GetSuivant();
				//----------------------------------------------------
			} while (noeudTemp != premierNoeud);
		}
		nbNoeud++;
		return true;
	}
	return false;
}

/// <summary>
/// Retirer un contenue specifique.
/// </summary>
/// <param name="_contenue">le contenue.</param>
/// <returns></returns>
template<class T>
bool List<T>::Retirer(T* _contenue)
{
	if (_contenue != NULL)
	{
		Noeud<T>* noeudTemp = premierNoeud;
		//verifie le premier noeud de la liste
		if (premierNoeud->GetContenue() == _contenue)
		{
			Noeud<T>* noeudASupprimer = premierNoeud;
			premierNoeud = premierNoeud->GetSuivant();
			premierNoeud->SetPrecedent(noeudASupprimer->GetPrecedent());
			premierNoeud->GetPrecedent()->SetSuivant(premierNoeud);
			delete noeudASupprimer;
			return true;
		}

		//verifie le reste de la liste
		do
		{
			if (noeudTemp->GetSuivant() != premierNoeud)
			{
				if (noeudTemp->GetSuivant()->GetContenue() == _contenue)
				{
					Noeud<T>* noeudASupprimer = noeudTemp->GetSuivant();
					noeudTemp->SetSuivant(noeudTemp->GetSuivant()->GetSuivant());
					noeudTemp->GetSuivant()->GetSuivant()->SetPrecedent(noeudTemp);
					delete noeudASupprimer;
					return true;
				}
			}
			noeudTemp = noeudTemp->GetSuivant();
		} while (noeudTemp != premierNoeud);
		return false;
	}
}

/// <summary>
/// Affiche le contenue de la liste.
/// </summary>
template<class T>
void List<T>::Affiche()
{
	Noeud<T>* noeudTemp = premierNoeud;
	do 
	{
		noeudTemp->GetContenue()->Affiche();
		noeudTemp = noeudTemp->GetSuivant();
	} while (noeudTemp != premierNoeud);
}

/// <summary>
/// donne le nombre de contenue de la liste.
/// </summary>
/// <returns></returns>
template<class T>
int List<T>::GetNbNoeud(){
	return nbNoeud;
}