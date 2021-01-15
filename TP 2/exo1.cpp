
/*
  Exercice 1 - Avis de recherche

  Q1 - Remplissez le tableau data de valeurs réelles aléatoires comprises entre 1 et 20.

  Pour ce faire, consultez la documentation de std::rand.

  Q2 - Affichez le contenu du tableau ainsi rempli.

  Q3 - Ecrivez le code nécesaire pour parcourir le tableau data et insérer dans un tableau resultats
  les index des valeurs supérieurs à 15.

  Q4 - Affichez le tableau ainsi rempli et vérifiez vos résultats.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int, char**)
{
  srand(time(NULL));

  std::vector<float> data(20);

  // Q1
for(int i = 0; i < data.size(); i++){
    data.at(i) = (rand() % 20 + 1);}
  // Q2
  for(auto e: data)
    std::cout << e << " ";
  std::cout << "\n";

  // Q3
std::size_t idx = 0;
std::vector<std::size_t> index;

  for(auto const& e : data)
  {
    if(e > 15)
      index.push_back(idx);
    idx++;
  }
  // Q4

  return 0;
}