/*
  Exercice 3 - Manipulation de tableaux de taille fixe -- correction

  Q1 - Utilisez std::array pour définir un tableau de 3 éléments de type double
  Q2 - Utilisez std::array pour définir un tableau de 3 éléments de type tableau de 3 doubles
  Q3 - Définissez un alias de type nommé vec3 pour le type vecteur de 3 éléments de type double
  Q4 - Utilisez le type ainsi défini pour créer une variable v contenant le vecteur suivant:
  | 2.5 |
  | 0.6 |
  | 1.1 |
  Q5 - Définissez un alias de type nommé mat33 pour le type matrice de 3x3 éléments de type double
  Q6 - Utilisez le type ainsi défini pour créer une variable m contenant la matrice suivante :
  | 1 2 1 |
  | 2 4 6 |
  | 1 2 0 |
  Q7 - Calculez le produit de la matrice m et du vecteur v ainsi défini dans un vecteur res
  Q8 - Vérifiez votre résultat
*/

#include <iostream>
#include <array>

using namespace std;

int main(int, char**)
{
  // Q1
  std::array<double,3> t3;

  //Q2
  std::array<std::array<double,3>, 3> t33;

  //Q3
  using vec3 =  std::array<double,3>;

  // Q4
  vec3 v = {2.5, 0.6, 1.1 };

  // Q5
  using mat33 =  std::array<vec3,3>;

  // Q6
  mat33 m = { 1,2,1
            , 2,4,6
            , 1,2,0
            };

  // Q7
  vec3 res = {0,0,0};

  res[0] = v[0]*m[0][0] + v[1]*m[0][1] + v[2]*m[0][2];
  res[1] = v[0]*m[1][0] + v[1]*m[1][1] + v[2]*m[1][2];
  res[2] = v[0]*m[2][0] + v[1]*m[2][1] + v[2]*m[2][2];

  cout << res[0] << "\n";
  cout << res[1] << "\n";
  cout << res[2] << "\n";

// Ou avec une boucle for
vec3 res1 = {0,0,0};
for (int k=0; k<3; k=k+1) {
    for (int j=0; j<3; j+=1){

    res1[k]+=  m[k][j]*v[j];
}

}

  // Q8
  cout << res1[0] << "\n";
  cout << res1[1] << "\n";
  cout << res1[2] << "\n";

  return 0;
}