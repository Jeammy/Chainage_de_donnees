#include <iostream>

//#include "liste.h"
#include "livre.h"
#include "JeuVideo.h"
#include "Inventaire.h"
#include "Pile.hpp"
#include "File.hpp"
#include "List.hpp"
using namespace std;

int main ()
{
	Pile<JeuVideo> tousLesJeux = Pile<JeuVideo>();
	File<Livre> tousLesLivres = File<Livre>();
	List<Livre> livres = List<Livre>();

	Inventaire inventaire = Inventaire();

	JeuVideo jeu1(1, "jeu1", "NES", 4);
	JeuVideo jeu2(2, "jeu2", "XBOX", 9);
	JeuVideo jeu3(3, "jeu3", "PLAYSTATION", 14);
	JeuVideo jeu4(4, "jeu4", "ATARI", 2);

	Livre livre1(1, "livre1", "2009", 1);
	Livre livre2(2, "livre2", "2014", 6);
	Livre livre3(3, "livre3", "2007", 2);
	Livre livre4(4, "livre4", "2016", 5);
	Livre livre5(0, "livre5", "2017", 7);

	livres.Ajouter(&livre1);
	livres.Ajouter(&livre3);
	livres.Ajouter(&livre2);
	livres.Ajouter(&livre4);
	livres.Ajouter(&livre5);
	livres.Ajouter(NULL);
	cout << "list" << endl;
	livres.Affiche();
	cout << "retirer l1" << endl;
	livres.Retirer(&livre1);
	livres.Retirer(&livre4);
	livres.Retirer(NULL);
	livres.Affiche();
	cout << "list" << endl;

	tousLesJeux.Push(&jeu1);
	tousLesJeux.Push(&jeu2);
	tousLesJeux.Push(&jeu3);
	tousLesJeux.Push(&jeu4);

	tousLesLivres.Ajouter(&livre1);
	tousLesLivres.Ajouter(&livre2);
	tousLesLivres.Ajouter(&livre3);
	tousLesLivres.Ajouter(&livre4);
	tousLesLivres.Affiche();
	//TODO : Utilisez vos fonctions template pour 

	//1. Afficher la quantité totale de tous les jeux
	cout << "Quantite de jeux total: " << inventaire.GetQuantiteTotale(tousLesJeux) << "\n" << endl;
	//2. Afficher la quantité totale de tous les livres
	cout << "Quantite de livre total: " << inventaire.GetQuantiteTotale(tousLesLivres) << "\n" << endl;
	//3. Afficher les infos de tous les jeux
	cout << "Liste des jeux: \n" << endl;
	inventaire.AfficherInfos(tousLesJeux);
	//4. Afficher les infos de tous les livres
	cout << "Liste des livres: \n" << endl;
	inventaire.AfficherInfos(tousLesLivres);
	system("pause");
	return 0;
}

