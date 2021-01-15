// TP 5

#include <iostream>
#include <vector>
using namespace std;

// exercice 1 
template<typename T>
vector <T> tri_paire_impaire(vector<T> V1, vector<T> V2){
    vector <T> W; 
    int u = 0;
    int d = 0;
	for(int i = 0; i<V1.size()*2 ; i++){
		if (i%2 == 0) { // c'est paire
			W.push_back(V1[u]);
            u = u+1;}
		else { // c'est impaire
			W.push_back(V2[d]);
            d = d+1;}
	}
    return W;
}


int main() {

    vector <int> V1 = {0,1,2,3,4};
    vector <int> V2 = {5,6,7,8,9};
    vector <int> w = tri_paire_impaire(V1,V2);
    for (auto i : w){
        cout << i << endl;
    }
}

