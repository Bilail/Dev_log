#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <set>
using namespace std;
/**
  Pour chaque fonction, utilisez les éléments de l'interface des conteneurs adéquats
  et les structures de contrôles adéquates pour répondre à la problématique des fonctions.

  Pensez à tester les éventuels corner cases.
**/

template<typename T, size_t N>
array<T, N> revert(array<T, N> const& tab)
{
  // Renvoyer un array contenant les valeurs de tab rangées dans l'ordre inverse
  array<T, N> reverse;
  for (int i=0; i < tab.size(); i++){
    reverse[tab.size()-1-i]=tab[i];
  }
  return reverse;
}

template<typename T, size_t N>
vector<int> find_all(array<T, N> const& tab, T value)
{
  // Renvoyer un tableau contenant tous les index où la valeur de tab vaut value
  vector<int> where;
  for (int i = 0; i < tab.size(); i++){
    if (tab[i]==value){
      where.push_back(i);
    }
  }
  return where;
}

template<typename T, size_t N>
set<T> uniques(array<T, N> const& tab)
{
  // Renvoyer un conteneur contenant la liste des valeurs uniques stockées dans tab
  // Ex:
  //  tab = [ 1 2 5 4 4 1 2 3 6 2 1 5 8 ]
  // renvoit
  //  [ 1 2 5 4 3 6 8 ]
  set<T> unique_values;
  for (T value: tab){
    unique_values.insert(value);
  }
  return unique_values;
}

template<typename T, size_t N>
float unique_sum(array<T, N> const& tab)
{
  // Renvoyer la somme des valeurs uniques de tab
  float sum = 0.0;
  for (T item: uniques(tab)){
    sum += item;
  }
  return sum;
}

template<typename T, size_t N>
void print(array<T, N> const& tab){
  for (T item: tab){
    cout << item << " ";
  }
  cout << "\n";
}

template<typename T>
void print(set<T> const& set_){
  for (T item: set_){
    cout << item << " ";
  }
  cout << "\n";
}

template<typename T>
void print(vector<T> const& vector_){
  for (T item: vector_){
    cout << item << " ";
  }
  cout << "\n";
}

int main(int argc, char** argv)
{
  // Q1 - revert
  array<int, 4> tab = {1,2,3,3};
  cout << "Q1 - revert:\n";
  cout << "Original: ";
  print(tab);
  array<int, 4> reverse = revert(tab);
  cout << "Reversed: ";
  print(reverse);
  cout << "\n\n";

  // Q2 - find_all
  cout << "Q2 - find_all:\n";
  cout << "tab: ";
  print(tab);
  int value = 3;
  cout << "Indices where tab == "<<value << ":\n";
  vector<int> where = find_all(tab, value);
  print(where);
  cout << "\n\n";

  // Q3 - uniques
  cout << "Q3 - uniques:\n";
  cout << "Original: ";
  print(tab);
  set<int> unique_values = uniques(tab);
  cout << "Uniques: ";
  print(unique_values);

  // Q4 - Uniques sum
  cout << "Q4 - sum: "<< unique_sum(tab) <<"\n\n";
  return 0;

}
