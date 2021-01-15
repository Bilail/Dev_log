/*
  Exercice 4 - Récupération des options de la ligne de commande
  
  La variable entière argc contient le nombre de valeurs passées sur la ligne de commande
  La variable pointeur argv contient la liste des valeurs passées sur la ligne de commande.
  Ainsi, si vous exécutez votre programme comme ceci :
     ./exo4  test 42 "la la"
  argc vaudra 4 et  argv contiendra 4 chaines de caractères :
    - argv[0] : "./exo4"
    - argv[1] : "test"
    - argv[2] : "42"
    - argv[3] : "la la" (Notez l'absence de guillemets)
  On remarquera que la quantité argv + argc correspond à la fin de la liste des valeurs ainsi
  récupérées (le pointeur ainsi obtenu pointe 4 cases plus loin que argv).
  Dans cet exercice, nous allons utiliser std::vector et std::string pour manipuler proprement
  ces valeurs.
  Q1 - Construisez une variable name de type std::string construite à partir de la valeur argv[0].
       Affichez son contenu, est-il cohérent avec le nom de votre exécutable ?
  Q2 - std::vector posséde un constructeur qui, à partir d'un pointeur vers le début et un pointeur
  vers la fin d'une zone de donnée, recopie ces données. Utilisez ce constructeur pour construire
  une variable nommée args de type std::vector<std::string> contenant les arguments de la ligne
  de commandes à l'exception du nom du programme.
  Q3 - Vérifiez que args.size() est bien égale à argc-1 en affichant le résultat de leur comparaison
  Q4 - En utilisant le code fourni pour lire un entier à partir du clavier, afficher le N-ieme
  argument contenu dans args. Que se passe-t-il si le N fourni dépasse args.size() ?
*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
  // Q1

  // Q2

  // Q3

  // Q4
  int n;
  std::cout << "Element a afficher:\n";
  std::cin >> n;

  return 0;
}