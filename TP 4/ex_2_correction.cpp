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
#include <algorithm>
#include <numeric>

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
  // plus eloigne de ref <=> maximum de |points - ref|
	return *max_element(points.begin(), points.end(),
			[ref](auto a, auto b){
				return distance(a, ref) < distance(b, ref); 
			});
}

//Q6
Point3D closest(Point3D const& ref, vector<Point3D> const& points){
  // plus proche de ref <=> minimum de |points - ref|
	return *min_element(points.begin(), points.end(),
			[ref](auto a, auto b){
				// pour chaque item a et b dans tab, 
				// si |a - ref| < |b - ref|
				// alors a est plus proche de origine
				return distance(a, ref) < distance(b, ref); 
			});
}

//Q7
Point3D acc(Point3D b, Point3D point){
  b.x+=point.x*point.weight;
  b.y+=point.y*point.weight;
  b.z+=point.z*point.weight;
  b.weight+=point.weight;
  return b;
}
Point3D barycentre(vector<Point3D> const& points){
  Point3D b = {0,0,0,0};
  b = accumulate(points.begin(), points.end(), b, acc);
  b.x /= b.weight;
  b.y /= b.weight;
  b.z /= b.weight;
  return b;
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
