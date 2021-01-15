/*
  Exercice 2 - Tableau 2D

  On désire implémenter un tableau dynamique à deux dimensions. Pour ce faire, on considérera
  qu'un tableau 2D se stocke dans un tableau dynamique standard et que, lorsque sa largeur
  et sa hauteur sont disponibles, on peut calculer la position linéaire n d'un élément de coordonnées
  (i,j) par la formule :

    n = (i +j) * largeur

  Q1 - Proposez une structure tableau2D qui suit cette spécification.
  Q2 - Surchargez l'opérateur () pour accéder à l'élément (i,j) du tableau.
  Q3 - Surchargez l'opérateur d'insertion de flux afin d'afficher vos tableaux
  Q4 - Fournissez sous forme de fonction un moyen d'obtenir la somme des éléments du tableau
  Q5 - Implémentez les fonctions membres begin() et end() permettant d'utiliser votre structure dans
  une boucle for par interval
*/

#include <iostream>
#include <vector>
using namespace std;

struct tableau2D
{
  size_t largeur, hauteur;
  vector<int> data;
  //Q1
  tableau2D(size_t largeur=0, size_t hauteur=0){
    this->hauteur=hauteur;
    this->largeur=largeur;
    this->data.reserve(largeur*hauteur);
  }

  //Q2
  int& operator()(int i, int j){
    return data[i*largeur+j];
  }

  //Q4
  int sum(){
    int s=0;
    for (int item: data){
      s+=item;
    }
    return s;
  }

  //Q5
  auto begin() { return data.begin(); }
  auto end() { return data.end(); }

};

// Q3 - à noter qu'on surcharge l'opérateur d'insertion de flux et pas tableau2D
ostream& operator<<(ostream& os, tableau2D t)
  {
    int i =0;
    for (auto item:t.data){
      if(i%t.largeur==0){

        os << "\n";
      }
      os << item << " ";
      i++;
    }
    os << "\n";
    return os;
  }

int main(int, char**)
{
  //Q1
  tableau2D t(3,4);
  cout << "t (largeur, hauteur): ("<<t.largeur<<", "<<t.hauteur<<")\n";
  t.data={0,1,2,3,4,5};
  cout << "t.data (size "<<t.data.size()<<", capacity "<<t.data.capacity()<<"):\n";
  cout<<t<<"\n";

  //Q2
  int i = 1;
  int j = 1;
  cout << "element ("<<i<<", "<<j<<"): "<<t(i,j)<<"\n";
  t(i,j)=6;
  cout << "element ("<<i<<", "<<j<<"): "<<t(i,j)<<"\n";
  cout<<t<<"\n";

  //Q4
  cout << "Somme: "<< t.sum()<<"\n\n";

  //Q5
  for(auto item:t){
    cout << item << " ";
  }
  cout<<"\n";

  return 0;
}