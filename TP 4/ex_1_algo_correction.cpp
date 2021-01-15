/*
  Exercice 1 - Algos, prise en main

	Q1 - A l'aide de l'agorithme for_each de la biblio standard, écrivez une fonction d'affichage de tous les éléments du tableau. 
	
	Q2 - A l'aide de l'agorithme transform de la biblio standard, modifiez le tableau en remplaçant chaque élément par son carré.
  
	Q3 - A l'aide de l'agorithme min_element et max_element, écrivez deux fonctions qui renvoient respectivement l'élément le plus proche et le plus éloigné d'un élément passé en paramètre. 
  
	Q4 - Enfin, à l'aide de l'agorithme accumulate de la biblio standard, écrivez une fonction qui renvoie la moyenne de tous les éléments du tableau.
	
	Q5 - A l'aide de l'agorithme find_if, écrivez une fonction un itérateur sur le premier élément supérieur à la moyenne. 

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <limits>
#include <algorithm>
#include <numeric>
using namespace std;

/* Q1 */
void print(int const& item){
	cout << item << " ";
}
void affichage (vector<int> &tab){
	for_each(tab.begin(), tab.end(), print);
	cout << endl;
}

/* Q2 */
int square(int item){
	return item*item;
}

void au_Carre (vector<int> &tab){
	transform(tab.begin(), tab.end(), tab.begin(), square);
}

/* Q3 */
auto plus_proche (vector<int> &tab, int origine){
	// plus proche de origin <=> minimum de |tab - origine|
	return *min_element(tab.begin(), tab.end(),
			[&tab, origine](auto a, auto b){
				// pour chaque item a et b dans tab, 
				// si |a - origine| < |b - origine|
				// alors a est plus proche de origine
				return abs(a - origine) < abs(b - origine); 
			});
}

auto plus_eloigne (vector<int> &tab, int origine){
	// plus eloigne de origin <=> maximum de |tab - origine|
	return *max_element(tab.begin(), tab.end(),
			[&tab, origine](auto a, auto b){
				// a noter qu'on aurait pu garder 'min_element' et changer le sens du signe '<' ici
				return abs(a - origine) < abs(b - origine); 
			});
}

/* Q4 */
float moyenne (vector<int> &tab){
	int sum = 0;
	sum = accumulate(tab.begin(), tab.end(), sum);
	return (float) sum/tab.size();
}

/* Q5 */
auto premier_Plus_grand_Moyenne (vector<int> &tab, float moyenne){
	return *find_if(tab.begin(), tab.end(),
			[&tab, moyenne](auto item){ // on peut enlever &tab 
				return item > moyenne;
			});
}

int main(int, char**)
{
	vector<int> tab = {7,15,4,12,19,8,3,5,1,24};
	affichage(tab);
	au_Carre(tab);
	affichage(tab);
	int origine = 290;
	plus_proche(tab, origine);
	cout << "Le plus proche de " << origine << " : " << plus_proche(tab, origine) << endl;
	cout << "Le plus eloigne de " << origine << " : " << plus_eloigne(tab, origine) << endl;
	float moy = moyenne(tab);
	cout << "Moyenne du tableau : "<< moy << endl;
	cout << "premier_Plus_grand_Moyenne du tableau : "<< premier_Plus_grand_Moyenne (tab, moy) << endl;
}
