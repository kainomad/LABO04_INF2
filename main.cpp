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
    cout << c;
    Vecteur<int> d = aBis+bBis;
    cout << d;
    Vecteur<int> e = bBis-aBis;
    cout << e;
    e.resize(4);
    cout << e;
    e.resize(6,4);
    cout << e;
    Vecteur<int> test(4);
    cout << test << endl;
    cout << test.size() << endl;
    
    Vecteur<int> test1(test);
    test1.at(6) = 10;
    cout << test1 << endl;
    
    system("PAUSE");
    
    return EXIT_SUCCESS;
}


