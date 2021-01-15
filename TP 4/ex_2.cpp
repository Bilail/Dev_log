/*
  Exercice 2 - Nuage de point II - Le retour

  Q1 - A partir de votre solution de l'exercice struct-3, réimplémentez chaque fonction
  manipulant le nuage de point sous forme d'algorithme. Justifiez vos choix et vérifiez
  le bon comportement de votre nouvelle version.

  ~~~~
      Exercice 3 - Nuage de points
      Q5 - Implémentez une fonction renvoyant le point le plus éloigné d'un point donné parmi tous les
      points stockés dans un std::vector de points pondérés.
      Q6 - Implémentez une fonction renvoyant le point le plus proche d'un point donné parmi tous les
      points stockés dans un std::vector de points pondérés.
      Q7 - Implémentez une fonction calculant le barycentre d'un ensemble de point stocké dans un
      std::vector.
      Q8 - Implémentez une fonction calculant la distance entre le point le plus proche et le plus
      éloigné du barycentre d'un ensemble de points.
  ~~~~
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

struct Point3D{
  //Q1
  float x,y,z,weight;
};

//Q4
float distance(Point3D const& left, Point3D const& right){
  float dx = left.x - right.x;
  float dy = left.y - right.y;
  float dz = left.z - right.z;
  return sqrt(dx*dx+dy*dy+dz*dz);
}

//Q5
Point3D farthest(Point3D const& ref, vector<Point3D> const& points){
  float max=0;
  Point3D farthest_p;
  for (auto point: points){
    auto d = distance(ref, point);
    if (d > max){
      max=d;
      farthest_p=point;
    }
  }
  return farthest_p;
}

//Q6
Point3D closest(Point3D const& ref, vector<Point3D> const& points){
  float min=numeric_limits<float>::infinity();
  Point3D closest_p;
  for (auto point: points){
    auto d = distance(ref, point);
    if (d < min){
      min=d;
      closest_p=point;
    }
  }
  return closest_p;
}

//Q7
Point3D barycentre(vector<Point3D> const& points){
  float weight=0.f, x=0.f, y=0.f, z=0.f;
  for (auto point:points){
    x+=point.x*point.weight;
    y+=point.y*point.weight;
    z+=point.z*point.weight;
    weight+=point.weight;
  }
  return {x/weight, y/weight, z/weight, weight};
}

//Q8
float range(vector<Point3D> const& points){
  auto b = barycentre(points);
  auto c = closest(b, points);
  auto f = farthest(b, points);
  return distance(c,f);
}

//Q2
ostream& operator<<(ostream& os, Point3D p)
{
  os << "("<<p.x<<", "<<p.y<<", "<<p.z<<") * "<<p.weight;
  return os;
}
//A noter qu'ici il est obligatoire d'utiliser une référence pour pouvoir modifier p
// pour l'ostream ci-dessus c'est optionnel, juste pour ne pas copier la structure 
istream& operator>>(istream& is, Point3D& p)
{
  is >>p.x>>p.y>>p.z>>p.weight;
  return is;
} 

//Q3
vector<Point3D> read(){    
    //ifstream ifs(path);
  Point3D p;
  string line;
  vector<Point3D> points;
  //cout << "Q3: stdin contient:\n";
  while (getline(cin, line))
  {
    // skip empty lines:
    if (line.empty())
        continue;
    // make a stream out of the string
    istringstream istream(line);
    // parse the line in a Point3D
    istream >> p;
    //push the point in the vector
    points.push_back(p);
  }
  return points;
}
int main(int, char**)
{
  //Q2
  //Point3D p; = {1,2,3,1.5};
  /* 
  cout << "Q2: Entre le point 3D au format '<x> <y> <z> <w>' (4 float):\n";
  cin>>p;
  cout << "Merci, tu as entré: "<<p << endl<< endl; */

  auto points = read();

  //q4
  cout << "Q4:\npoints[0]: "<<points[0]<<"\npoints[1]: "<< points[1]
  <<"\ndistance(points[0], points[1]): "<<distance(points[0], points[1])<<endl<<endl;

  //Q5
  Point3D p = {2,1,3,1.5};
  cout<<"Q5: farthest of "<<p<<" : "<<farthest(p,points)<<endl<<endl;

  //Q6
  cout<<"Q6: closest of "<<p<<" : "<<closest(p,points)<<endl<<endl;

  //Q7
  auto b=barycentre(points);
  cout<<"Q7 - barycentre : "<<b<<endl<<endl;

  //Q8
  auto d = range(points);
  cout <<"Q8: "<< d<<endl;
}
