
// exo 2 
#include <iostream>
#include <vector>
using namespace std;

float moyenne_r(vector<float> V){
	float somme = 0; 
	for (float e : V){ somme += e; }

	return somme/V.size();
}

    
int main(){
    vector<float> V = {1.0,2.0,3.0};
    float moyenne = moyenne_r(V); 
    cout << "la moyenne est de " << moyenne << endl;
}