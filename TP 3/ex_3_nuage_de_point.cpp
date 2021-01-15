/*
  Exercice 3 - Nuage de points
  Q1 - Implémentez une structure représentant un point 3D pondéré par un réel.
  Q2 - Implémentez les opérateurs nécessaires pour extraire et insérer une instance de cette
  structure dans un flux.
  Q3 - Renseignez vous sur la fonction std::getline. Utilisez la pour lire un fichier texte contenant
  une quantité arbitraire de points pondérés. Cette fonction prendra en paramètre le nom du fichier à lire
  et renverra un std::vector de point 3D pondéré.
  Q4 - Implémentez une fonction calculant la distance entre deux points pondérés
  Q5 - Implémentez une fonction renvoyant le point le plus éloigné d'un point donné parmi tous les
  points stockés dans un std::vector de points pondérés.
  Q6 - Implémentez une fonction renvoyant le point le plus proche d'un point donné parmi tous les
  points stockés dans un std::vector de points pondérés.
  Q7 - Implémentez une fonction calculant le barycentre d'un ensemble de point stocké dans un
  std::vector.
  Q8 - Implémentez une fonction calculant la distance entre le point le plus proche et le plus
  éloigné du barycentre d'un ensemble de points.
  Chaque fonction devra être testée en isolation afin de s'assurer de son fonctionnement correct.
*/

#include <iostream>

/* Mon exerccie 3 : https://godbolt.org/z/3dnr1d
  /*
  Exercice 3 - Nuage de points
  Q1 - Implémentez une structure représentant un point 3D pondéré par un réel.
  Q2 - Implémentez les opérateurs nécessaires pour extraire et insérer une instance de cette
  structure dans un flux.
  Q3 - Renseignez vous sur la fonction std::getline. Utilisez la pour lire un fichier texte contenant
  une quantité arbitraire de points pondérés. Cette fonction prendra en paramètre le nom du fichier à lire
  et renverra un std::vector de point 3D pondéré.
  Q4 - Implémentez une fonction calculant la distance entre deux points pondérés
  Q5 - Implémentez une fonction renvoyant le point le plus éloigné d'un point donné parmi tous les
  points stockés dans un std::vector de points pondérés.
  Q6 - Implémentez une fonction renvoyant le point le plus proche d'un point donné parmi tous les
  points stockés dans un std::vector de points pondérés.
  Q7 - Implémentez une fonction calculant le barycentre d'un ensemble de point stocké dans un
  std::vector.
  Q8 - Implémentez une fonction calculant la distance entre le point le plus proche et le plus
  éloigné du barycentre d'un ensemble de points.
  Chaque fonction devra être testée en isolation afin de s'assurer de son fonctionnement correct.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;
//Q1
struct point3D {
    float x;
    float y;
    float z;
    float p;
};
//Q2
ostream& operator<<(ostream& os, point3D pt)
  {
    os << "coordonnée : " << pt.x << " " << pt.y <<" "<< pt.z << " le poids : "<<pt.p;
    return os;
  }
istream& operator>>(istream& is, point3D& pt) {
    is >> pt.x >> pt.y >> pt.z >> pt.p;
    return is;
}
//Q3
 vector<point3D> read(){    
  point3D pt;
  string line;
  vector<point3D> points;
  //cout << "Q3: stdin contient:\n";
  while (getline(cin, line))
  {
    // skip empty lines:
    if (line.empty())
        continue;
    // make a stream out of the string
    istringstream istream(line);
    // parse the line in a Point3D
    istream >> pt;
    //push the point in the vector
    points.push_back(pt);
  }
  return points;
}

//Q4 
float dist(point3D a, point3D b){
    return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)));
}
//Q5
point3D plus_loin(point3D a, vector<point3D> points){
    float res_dist = 0;
    point3D res_p;
    for (auto pt:points){
        if (dist(a, pt)>res_dist){
            res_dist = dist(a, pt);
            res_p = pt;
        }
    }
    return res_p;
    }

//Q6
point3D plus_proche(point3D a, vector<point3D> points){
    float res_dist = numeric_limits<float>::infinity();
    point3D res_p;
    for (auto pt:points){
        if (dist(a, pt)<res_dist){
            res_dist = dist(a, pt);
            res_p = pt;
              }
    }
    return res_p;
    }

//Q7
point3D barycentre(vector<point3D> points){
    point3D res; 
    float som_x = 0; 
    float som_y = 0; 
    float som_z = 0; 
    float som_p = 0; 
    for (auto pt:points){
        som_x += pt.p*pt.x;
        som_y += pt.p*pt.y;
        som_z += pt.p*pt.z;
        som_p += pt.p;
    }
    res.x = som_x/som_p;
    res.y = som_y/som_p; 
    res.z = som_z/som_p; 
    res.p = som_p/som_p;
    return res;
}

//Q8
float plus_proche_b(vector<point3D> points){
    point3D B = barycentre(points);
    point3D p = plus_proche(B,points);
    return dist(p,B) ;}

float plus_loin_b(vector<point3D> points){
    point3D B = barycentre(points);
    point3D l = plus_loin(B,points);
    return dist(l,B);}


int main(int, char**)
{
    point3D p1={1,2,3,6};
    point3D p2={2,4,5,6};
    point3D p3; 
    cin >>p3;
    cout<<p1<<endl;
    cout<<p2<<endl;
    cout<<p3<<endl;
    cout<<"distance entre p1 et p2 : "<<dist(p1,p2)<<endl;
}

