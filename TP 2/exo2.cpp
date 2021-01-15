#include <iostream>
#include <array>

using namespace std ;


void afficher_plateau(){

    // Je voulais faire une fonction qui affiche proprement le plateau
    // mais je n'ai pas eu le temps. N'hésitez pas à le faire...

}

int main(int, char**)
{
  // Q1
  using grille = std::array<std::array<char,3>,3>;

  // Q2
  bool fin = false;

  // Q3 - Gestion du symbole
  char  symbole = 'X';

  // Q5 - Grille
  grille plateau = { '_','_','_'
            , '_','_','_'
            , '_','_','_'
            };

  // Q2 - Lecture de la position
  while(!fin)
  {

    // Q4 - lecture (x,y);
    int x,y;
    cout << "Position de jeu pour " << symbole << " :\n";
    cin >> x >> y;

    // Q5
    plateau[x][y] = symbole;

    for(auto ligne : plateau)
    {
      for(auto sym : ligne)
        cout << sym << " ";
      cout << "\n";
    }

    // Q6 Victoire ?
    // le long d'une ligne ?
    for(int l=0;l<3;++l)
    {
      if(!fin)
        fin = (plateau[l][0] == symbole) && (plateau[l][1] == symbole) && (plateau[l][2] == symbole);
    }

    if(!fin)
    {
      // le long d'une colonne ?
      for(int c=0;c<3;++c)
      {
        if (!fin)
          fin = (plateau[0][c] == symbole) && (plateau[1][c] == symbole) && (plateau[2][c] == symbole);
      }
    }

    if(!fin)
    {
      fin = ((plateau[0][0] == symbole) && (plateau[1][1] == symbole) && (plateau[2][2] == symbole))
         || ((plateau[0][2] == symbole) && (plateau[1][1] == symbole) && (plateau[2][0] == symbole));
    }

    if(fin)
      cout << symbole << " remporte la manche.\n";

    // Q3
    if(symbole == 'X')
      symbole = 'O';
    else
      symbole = 'X';
  }

  return 0;
}