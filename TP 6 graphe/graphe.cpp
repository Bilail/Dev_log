#include <iostream>
#include <vector>
using namespace std;

//Exercice 1 -----------------------------------------

struct sommet{
	int id; 
	vector<int> arc; 
};

struct graphe {
	vector<sommet> matrice;
	int nbr_sommet;

	void ajout_sommet(){
		nbr_sommet +=1;
		sommet s{nbr_sommet,{}};
		matrice.push_back(s);
	}


//initialisation des arc de chaque sommet
	void initialisation_arc(){
		for (sommet s : matrice){
			for(int i = 0; i < nbr_sommet ; i++){
				s.arc.push_back(0);
			}
		}
	}

	void ajout_arrete(sommet depart, sommet arrive){
		matrice[depart.id].arc[arrive.id] = 1;
		matrice[arrive.id].arc[depart.id] = -1;
	}

	void sommet_adjacent(sommet s){
		vector<int> adjacent;
		for (int i : matrice[s.id].arc){
			adjacent.push_back(i);
		}
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


	int nombre_de_sommet(){
	return nbr_sommet;
		}

	int nbr_arrete(){
		int nbr_arrete = 0;
		for (sommet s : matrice){
			for(int i = 0 ;i<nbr_sommet; i++){
					nbr_arrete += 1 ;

			}
		}
		return nbr_arrete;

	}
};
//Exercice 2 -----------------------------------------		
// ces deux programmes sont de difficultés n car on parcoure une boucle for. 


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

int degre_entrant(sommet s){
	int res = 0;
	for (int i : s.arc ){
		if (i == 1){
			res += 1;
		}
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

int degre_sortant(sommet s){
	int res = 0;
	for (int i : s.arc ){
		if (i == -1){
			res += 1;
		}
	}
    return res;
}

// Exercice 3 -------------------------------------

bool est_addjacent(sommet d, sommet a){
	if (d.arc[a.id] == -1 && a.arc[d.id] == 1){ return true;}
	else return false;
}




// ############# AFFICHAGE #############

int main(){
	
	};


	
