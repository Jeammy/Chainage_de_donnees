#pragma once
#include "livre.h"

template<class T>
class Noeud
{
public:
	Noeud();
	~Noeud();
	Noeud * GetSuivant();
	void SetSuivant(Noeud * _suivant);
	T * GetContenue();
	void SetContenue(T * _contenue);
	Noeud * GetPrecedent();
	void SetPrecedent(Noeud * _precedent);
private:
	T * contenue;
	Noeud * suivant;
	Noeud * precedent;

};

template<class T>
Noeud<T>::Noeud()
{
}

template<class T>
Noeud<T>::~Noeud()
{
}

template<class T>
Noeud<T> * Noeud<T>::GetSuivant()
{
	return suivant;
}

template<class T>
void Noeud<T>::SetSuivant(Noeud * _suivant)
{
	suivant = _suivant;
}

template<class T>
T * Noeud<T>::GetContenue()
{
	return contenue;
}

template <class T>
void Noeud<T>::SetContenue(T * _contenue)
{
	contenue = _contenue;
}

template <class T>
Noeud<T> * Noeud<T>::GetPrecedent(){
	return precedent;
}

template <class T>
void Noeud<T>::SetPrecedent(Noeud<T> * _precedent){
	precedent = _precedent;
}
