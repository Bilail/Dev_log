/*
  Exercice 2 - Morpion

  Nous allons écrire un jeu simpliste de morpion. Le morpion est un jeu à deux joueurs
  qui consiste, à tour de rôle, de poser une croix (X) ou un rond (O) dans une grille 3x3.
  Un joueur gagne s'il aligne 3 symboles identiques en ligne, colonne ou diagonale.

  Q1 - Définissez un type 'grille' à base de array pour représenter la grille de jeu

  Q2 - Créez une valeur booléenne 'fin' valant false. Utilisez-la dans une boucle while dont la condition
  d'arrêt est le fait que cette variable vaille true. Vérifiez que le programme ne s'arrête pas.

  Q3 - Créez à l'endroit adéquat une variable 'symbole' de type char. Cette variable vaut 'X' au démarrage.
  Faites en sorte que, à chaque tour de boucle while, sa valeur alterne entre 'X' et 'O'.

  Q4 - Modifiez la boucle afin d'afficher un texte invitant le symbole courant à entrer sa position
  de jeu. Lisez ensuite une paire d'entiers entre 0 et 2. Cette paire d'entiers représente
  la coordonnée (x,y) dans la grille où le symbole courant doit être placé.

  Q5 - Construisez à l'endroit adéquat une variable de type 'grille' et mettez à jour sa valeur et
  affichez la à chaque itération.

  Q6 - Implémentez une série de tests qui vérifie après chaque coup si le joueur courant a gagné.
  Si c'est le cas, annoncez sa victoire et mettez la variable fin à true pour arrêter le jeu.

  QBONUS - Ajoutez tous les tests nécessaires à la capture des erreurs dues à l'entrée des positions
  des joueurs : case hors grille, case déjà utilisée, etc ...
*/

#include <iostream>
#include <array>
#include <tuple>
#include <string>
using namespace std;

//Q1
using grille = array<array<char, 3>, 3>;

//Q6
bool est_fini(grille const& morpion){
  for (int i = 0; i<morpion.size();i++){
    // horizontal check - valid pawn 
    if (morpion[i][0] == 'X' || morpion[i][0] == 'O'){
      // horizontal check
      if((morpion[i][0]==morpion[i][1]) && (morpion[i][0]==morpion[i][2])){
        return true;
      }
    }
    // vertical check - valid pawn 
    if (morpion[0][i] == 'X' || morpion[0][i] == 'O'){
      //vertical check
      if((morpion[0][i]==morpion[1][i]) && (morpion[0][i]==morpion[2][i])){
        return true;
      }
    }
    // diagonal check - valid pawn
    if (morpion[1][1]== 'X' || morpion[1][1] == 'O'){
      // 1st diagonal check
      if((morpion[0][0]==morpion[1][1]) && (morpion[0][0]==morpion[2][2])){
        return true;
      }
      // 2nd diagonal check
      if((morpion[0][2]==morpion[1][1]) && (morpion[0][2]==morpion[2][0])){
        return true;
      }
    }
  }
  return false;
}


// QBonus
bool valid(grille const& morpion, pair<int, int> position){
  // out of range
  if (position.first < 0 || position.second < 0){ return false; }
  if (position.first >= morpion.size() || position.second >= morpion.size()){ return false; }

  // busy
  auto coup = morpion[position.first][position.second];
  if (coup=='X' || coup == 'O'){return false;} 
  return true;
}

int main(int, char**)
{
  //Q2
  bool fin = false;
  /* while (!fin)
  {
    cout<<"bloqué"<<"\n";
  } */
  
  //Q3 - Q4 - Q5 - Q6
  //Q3
  char symbole = 'X';
  //Q4
  pair<int, int> position;
  //Q5
  grille morpion;
  
  while (!fin)
  {
    //Q3
    if (symbole == 'X'){
      symbole = 'O';
    }
    else {
      symbole = 'X';
    }
    //Q3 // cout << symbole << "\n";

    //Q4
    do {      
      cout << "Au tour de '"<< symbole <<"' ! Entre la position au format '<x> <y>' (entiers entre 0 et 2 inclus)\n";
      cin >> position.first >> position.second;
    }
    // QBonus
    while (!valid(morpion, position));
    
    //Q4 // cout << "Tu as joué ("<< position.first << ", " << position.second << ")\n";

    //Q5
    morpion[position.first][position.second] = symbole;
    cout <<"\n";
    for (int i =0; i < morpion.size();i++){
      for (int j=0; j < morpion[i].size();j++)
      {          
          cout << morpion[i][j] << " ";
      }
      cout <<"\n";
    } 

    //Q6
    fin = est_fini(morpion);
  }
  cout << "Victoire de '"<< symbole <<"', gg !\n";
  return 0;
}