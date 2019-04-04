/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : main.cpp
 Groupe      : Labo_04
 Auteur(s)   : Chau Ying Kot, Johann Werkle
 Date        : 02.04.2019
 
 But         :
 
 Remarque(s) : -
 
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>

#include "Vecteur.h"
#include "Matrice.h"
#include "VecteurImpl.h"
#include "MatriceImpl.h"
using namespace std;
int main() {

    vector<int> a = {1,2,3,4,5};
    vector<int> b = {2,3,4,5,6};
    Vecteur<int> aBis = a;
    Vecteur<int> bBis = b;
    Vecteur<int> c = aBis*bBis;
    cout << "a*b " << c << endl;
    Vecteur<int> g = aBis*17;
    cout << "a*17 " << g << endl;
    Vecteur<int> d = aBis+bBis;
    cout << "a+b " << d << endl;
    Vecteur<int> e = bBis-aBis;
    cout << "a-b " << e << endl;
    e.resize(4);
    cout << "resize1 " << e << endl;
    e.resize(6,4);
    cout << "resize2 " <<  e << endl;
    cout << "size " <<  e.size() << endl;
    Vecteur<int> test(4);
    cout << test << endl;
    cout << test.size() << endl;
    
    Vecteur<int> test1(test);
    test1.at(6) = 10;
    cout << test1 << endl;
    
    system("PAUSE");
    
    return EXIT_SUCCESS;
}


