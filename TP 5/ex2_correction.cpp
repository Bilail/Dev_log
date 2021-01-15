/*
Soit un tableau de nombres réels V contenant chacun N éléments.
    1. Donnez un algorithme permettant de calculer la moyenne des éléments de V de manière
    itérative.
    2. Donnez un algorithme permettant de calculer la moyenne des éléments de V de manière
    récursive.
    3. Donnez le code C++ des fonctions implémentant ces deux algorithmes.
    4. En utilisant la fonction std::chrono, mesurez le temps d’exécutions des deux algorithmes
    pour des vecteurs de tailles croissantes de 1000 à 10000000 éléments. Que constatez vous ?
*/

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <fstream>
#include <sstream>
#include <limits>
#include <chrono>

using namespace std;

//Q1
template<typename T, size_t N>
float mean_iter(array<T, N> const& tableau, size_t foo){
    T sum = 0;
    for (size_t i =0; i<tableau.size(); i++){
        sum+=tableau[i];
    }
    return (float)sum/tableau.size();
}

//Q2
template<typename T, size_t N>
float mean_rec(array<T, N> const& tableau, size_t i){
    if (i==tableau.size()-1){
        return tableau[i];
    }
    if (i==0){
        return (float) (tableau[i] + mean_rec(tableau, i+1))/tableau.size();
    }
    return tableau[i] + mean_rec(tableau, i+1);
}

// alternative à la somme récursive en utilisant les itérateurs (v0.begin(), v0.end())
template<typename Iterator>
float sum_rec_it(Iterator begin, Iterator end){
    if (begin != end){
        return *begin + sum_rec_it(begin+1, end);
    }
    return *begin;
}

//Q4
template<class Function, typename T, size_t N>
chrono::duration<double> timer(Function f, array<T, N> const& tableau){
    auto start = chrono::steady_clock::now();
    f(tableau, 0);
    auto end = chrono::steady_clock::now();
    auto elapsed_seconds = end-start;
    return elapsed_seconds;
}

int main(){
    array<int, 3> v0 = {0,2,4};
    cout << sum_rec_it(v0.begin(), v0.end()) << endl;
    array<int, 1000> v1 = {0,2,4};
    cout << "N="<<1000<<", mean_iter: " << timer(mean_iter<int,1000>, v1).count()*1000 << "ms\n";
    cout << "N="<<1000<<", mean_rec: " << timer(mean_rec<int,1000>, v1).count()*1000 << "ms\n\n\n";
    array<int, 10000> v2 = {0,2,4};
    cout << "N="<<10000<<", mean_iter: " << timer(mean_iter<int,10000>, v2).count()*1000 << "ms\n";
    cout << "N="<<10000<<", mean_rec: " << timer(mean_rec<int,10000>, v2).count()*1000 << "ms\n\n\n";
    array<int, 100000> v3 = {0,2,4};
    cout << "N="<<100000<<", mean_iter: " << timer(mean_iter<int,100000>, v3).count()*1000 << "ms\n";
    cout << "N="<<100000<<", mean_rec: " << timer(mean_rec<int,100000>, v3).count()*1000 << "ms\n\n\n";
    
    
    //Program returned: 139 -> 1000000 est trop grand (même pour initialiser le tableau)
    //array<int, 1000000> v4 = {0,2,4};
    //cout << "N="<<1000000<<", mean_iter: " << timer(mean_iter<int,1000000>, v4).count()*1000 << "ms\n";
    //cout << "N="<<1000000<<", mean_rec: " << timer(mean_rec<int,1000000>, v4).count()*1000 << "ms\n\n\n";
 
    return 0;
}