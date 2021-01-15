/*
  Exercice 1 - Fraction

  Fournissez une implémentation d'une structure fraction représentant un nombre
  fractionnaire. Vous implémenterez sous forme de fonction ou d'opérateur surchargés les
  fonctionnalités suivantes:

  - Q1a. addition fraction/fraction, entier/fraction, fraction/entier
  - Q1b. soustraction fraction/fraction, entier/fraction, fraction/entier
  - Q2. multiplication fraction/fraction, entier/fraction, fraction/entier
  - Q3. division fraction/fraction, entier/fraction, fraction/entier
  - Q4. négation de fraction
  - Q5. conversion de la fraction en nombre réel double précision
  - Q6. insertion et extraction depuis un flux
*/

#include <iostream>
using namespace std;

struct fraction
{
  int num, denum;
  fraction inverse() const{
    return {denum, num};
  }
  double to_double(){
    return (double) num/denum;
  }
};

// opposé
fraction operator-(fraction const& self)
{
  return { -self.num, self.denum };
}
// addition
//   a/b + c/d
fraction operator+(fraction const& self, fraction const& other)
{
  auto num = self.num*other.denum + other.num*self.denum;
  auto denum = self.denum * other.denum;
  return { num, denum};
}
//   a/b + c
fraction operator+(fraction const& self, int const& other)
{
  return {self.num + other*self.denum, self.denum};
}
//   c + a/b
fraction operator+(int const& self, fraction const& other)
{
  return other + self;
}
// soustraction -> a-b <=> a+(-b)
//   fraction-fraction
fraction operator-(fraction const& self, fraction const& other)
{
  return self + (-other);
}
//   fraction-entier
fraction operator-(fraction const& self, int const& other)
{
  return self + (-other);
}
//   entier-fraction
fraction operator-(int const& self, fraction const& other)
{
  return self + (-other);
}

// multiplication
//   a/b * c/d
fraction operator*(fraction const& self, fraction const& other)
{
  return { self.num*other.num, self.denum * other.denum};
}
//   a/b * c
fraction operator*(fraction const& self, int const& other)
{
  return {self.num * other, self.denum};
}
//   c * a/b
fraction operator*(int const& self, fraction const& other)
{
  return other*self;
}


// division -> (a/b)/(c/d) <=> (a/b)*(d/c)
fraction operator/(fraction const& self, fraction const& other)
{
  return self * other.inverse();
}
 //   (a/b) / c <=> a/(b*c)
fraction operator/(fraction const& self, int const& other)
{
  return {self.num, self.denum*other};
}
//   c / (a/b)
fraction operator/(int const& self, fraction const& other)
{
  return other/self;
}
 

//q6
ostream& operator<< (std::ostream& os, fraction const & f){
  return os  << f.num << '/' << f.denum;
}
//A noter qu'ici il est obligatoire d'utiliser une référence pour pouvoir modifier p
// pour l'ostream ci-dessus c'est optionnel, juste pour ne pas copier la structure 
istream& operator>>(istream& is, fraction& f)
{
  is >>f.num >> f.denum;
  return is;
} 
int main(int, char**)
{
  fraction f = {1, 2};
  fraction g = {1, 3};
  cout << "f: "<<f<<endl;
  cout << "g: "<<g<<endl;

  //Q1 - Addition (+) et soustraction (-)
  cout << "\n\nQ1 - Addition (+) et soustraction (-)\n\n";
  cout << "-f: "<<-f<<endl;
  cout << "f+g: " << f+g<<endl;
  cout << "f-g: " << f-g<<endl;
  cout << "f+1: " << f+1<<endl;
  cout << "1+f: " << 1+f<<endl;
  cout << "f-1: " << f-1<<endl;
  cout << "1-f: " << 1-f<<endl;

  //Q2 - multiplication (*)
  cout << "\n\nQ2 - multiplication (*)\n\n";
  cout << "f*g: " << f*g<<endl;
  cout << "f*2: " << f*2<<endl;
  cout << "2*f: " << 2*f<<endl;

  //Q3 - division (/)
  cout << "\n\nQ3 - division (/)\n\n";
  cout << "f.inverse() <=> 1/f: " << f.inverse()<<endl;
  cout << "f/g: " << f/g<<endl;
  cout << "f/2: " << f/2<<endl;
  cout << "2/f: " << 2/f<<endl;

  //Q4 - négation ???

  // Q5. conversion de la fraction en nombre réel double précision
  cout << "\n\nQ5. conversion de la fraction en nombre réel double précision (double)\n\n";
  cout << "Fraction -> double: f="<<f.to_double()<< ", g="<<g.to_double()<<"\n";

  // Q6. insertion et extraction depuis un flux
  fraction input;
  cout << "\n\nEntre le nominateur et le dénominateur au format '<a> <b>'\n";
  cin >> input;
  cout << "Merci pour ta participation ! Tu as entré :\n" << input<<endl;
  return 0;
}