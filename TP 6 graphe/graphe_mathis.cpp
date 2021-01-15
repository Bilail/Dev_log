/*
 * graphe.cpp
 *
 *  Created on: 16 déc. 2019
 *      Author: mathis
 */

#include "graphe.h"

Graphe::Graphe() :
	matrice(),
	nombreSommets(0),
	nombreAretes(0)
{

}


Graphe::~Graphe() {
	// TODO Auto-generated destructor stub
}



// ############### EXO 1 ###############



sommet Graphe::nouveauSommet() {
	nombreSommets ++;
	matrice.push_back( std::vector<short>(nombreAretes, 0) );
	return sommet(nombreSommets-1);
}

void Graphe::nouvelleArete(sommet sommetDepart, sommet sommetArrivee) {
	for(size_t i = 0; i < nombreSommets; i++) {
		matrice.at(i).push_back(0);
	}
	matrice.at(sommetDepart.id).at(nombreAretes)  = -1;
	matrice.at(sommetArrivee.id).at(nombreAretes) =  1;
	nombreAretes ++;
}

/* PseudoCode

	Algorithme sommetsAdjacents(
		matrice : Tableau2d d'Entiers,
		sommet  : Entier
	)

	Variables:
	  -  res  : Tableau d'Entiers
	  -  i, j : Entiers

	Début
		res <- Tableau(vide)

		pour i <- 0 à Taille(matrice[sommet]), faire
			si matrice[sommet][i] = -1
				pour j <- 0 à Taille(matrice), faire
					si matrice[j][i] = 1
						res.ajout(j)
					fin_si
				fin_pour
			fin_si
		fin_pour

		Retourner res
	Fin

 */
std::vector<sommet> Graphe::sommetsAdjacents(sommet s) const {
	std::vector<sommet> res;

	for(size_t i = 0; i < nombreAretes; i++) {
		if(matrice.at(s.id).at(i) == -1) {
			for(size_t j = 0; j < nombreSommets; j++) {
				if(matrice.at(j).at(i) == 1) {
					res.push_back(sommet(j));
					break;
				}
			}
		}
	}

	return res;
}

int Graphe::getNombreSommets() const {
	return nombreSommets;
}

int Graphe::getNombreAretes() const {
	return nombreAretes;
}

matriceIncidence Graphe::getMatrice() const {
	return matrice;
}



// ############### EXO 2 ###############



/* PseudoCode

	Algorithme degreEntrant(matrice : Tableau2d, sommet : Entier)

	Variables:
	  -  res : Entier
	  -  i   : Entier

	Début
		res <- 0

		pour i <- 0 à Taille(matrice[sommet]), faire
			si matrice[sommet][i] = -1
				res <- res + 1
			fin_si
		fin_pour

		Retourner res
	Fin
 */

/* Complexité : O(n)
 *
 * Une unique boucle for parcourant les colonnes de la matrice.
 * Le nombre d'opération est directement proportionnel au nombre d'arêtes (n).
 */
int Graphe::degreEntrant(sommet s) const { // complexité : O(n)
	size_t res = 0;

	for(size_t i = 0; i < nombreAretes; i++) {
		if(matrice.at(s.id).at(i) == 1) res ++;
	}
	return res;
}

/* PseudoCode

	Algorithme degreSortant(
		matrice : Tableau2d,
		sommet : Entier
	)

	Variables :
	  -  res  : Entier
	  -  i    : Entier

	Début
		res <- 0

		pour i <- 0 à Taille( matrice[sommet] ) - 1, faire
			si matrice[sommet][i] = -1
				res <- res + 1
			fin_si
		fin_pour

		Retourner res
	Fin

 */
int Graphe::degreSortant(sommet s) const { // complexité : O(n)
	size_t res = 0;

	for(size_t i = 0; i < nombreAretes; i++) {
		if(matrice.at(s.id).at(i) == -1) res ++;
	}
	return res;
}



// ############### EXO 3 ###############



bool Graphe::estAdjacent(sommet sommetDepart, sommet sommetArrivee) const {
	for(size_t i = 0; i < nombreAretes; i++) {
		if(matrice.at(sommetDepart.id).at(i) == -1) {
			if(matrice.at(sommetArrivee.id).at(i) == 1) {
				return true;
			}
		}
	}
	return false;
}

/*  Algorithme cheminExiste(
   	    matrice : Tableau2d d'Entiers,
   	    sommetDépart : Entier,
   	    sommetArrivée : Entier
    )

    Variables :
      -  sommetsTraités : Tableau d'Entiers

    Début
		sommetsTraités = Tableau( taille=Taille(matrice) )
		Retourner cheminExisteRecursif(
			matrice,
			sommetDépart,
			sommetArrivée,
			sommetsTraites
		)
	Fin
 */
bool Graphe::cheminExiste(sommet sommetDepart, sommet sommetArrivee) {
	std::vector<sommet> sommetsTraites;
	return cheminExisteRecursif(sommetDepart, sommetArrivee, sommetsTraites);
}

/*  Algorithme vecteurContient(
   	    vecteur : Tableau d'Entiers,
   	    élément : Entier,
    )

    Variables :
     -  i : Entier

    Début
		Pour i <- 0 à Taille(vecteur) - 1 faire
			si vecteur[i] = élément
				Retourner vrai
			fin_si
		fin_pour
		Retourner faux
	Fin
 */
bool Graphe::vecteurContient(const std::vector<sommet>& sommetsTraites, sommet s) {
	for(size_t j = 0; j < sommetsTraites.size(); j++) {
		if( sommetsTraites.at(j).id == s.id ) {
			return true;
		}
	}
	return false;
}

/*  Algorithme cheminExisteRécursif(
   	    matrice : Tableau2d,
   	    sommetDépart : Entier,
   	    sommetArrivée : Entier,
   	    (par référence ou globale) sommetsTraités : Tableau d'Entiers
	)

	Variables :
	  -  adjacents : Tableau d'Entiers

	Début
		si sommetDépart = sommetArrivée
			Retourner vrai
		fin_si

		adjacents = sommetsAdjacents(sommetDépart)
		sommetsTraités.ajoute(sommetDépart)

		pour i <- 0 à Taille(adjacents) - 1, faire

			si vecteurContient(sommetsTraités, adjacents[i])
				Retourner faux
			sinon si cheminExisteRécursif(
				matrice,
				sommetDépart,
				sommetArrivée,
				sommetsTraités
			)
				Retourner vrai
			fin_si

		fin_pour

		Retourner faux
	Fin
 */
bool Graphe::cheminExisteRecursif(
		sommet sommetDepart,
		sommet sommetArrivee,
		std::vector<sommet>& sommetsTraites)
{
	if( sommetDepart.id == sommetArrivee.id ) {
		return true;
	}

	std::vector<sommet> adjacents = sommetsAdjacents(sommetDepart);
	sommetsTraites.push_back( sommetDepart );

	for(size_t i = 0; i < adjacents.size(); i++) {
		if( vecteurContient(sommetsTraites, adjacents.at(i)) ) return false;
		if( cheminExisteRecursif(adjacents.at(i), sommetArrivee, sommetsTraites) ) return true;
	}

	return false;
}



// ############# AFFICHAGE #############



#include "util.h"

// Implémentation de l'affichage de sommet
std::ostream& operator<< (std::ostream& output, const sommet& s) {
    output << "<sommet : id=" << s.id
    	   << ">";
    return output;
}

// Implémentation de l'affichage de Graphe
std::ostream& operator<< (std::ostream& output, const Graphe& g) {
	output << "<Graphe : sommets=" << g.getNombreSommets()
		   << ", aretes=" << g.getNombreAretes()
		   << ">";
	output << g.getMatrice();
    return output;
}

