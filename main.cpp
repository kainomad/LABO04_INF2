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
#include <limits>

#include "Vecteur.h"
#include "Matrice.h"
#include "VecteurImpl.h"
#include "MatriceImpl.h"

using namespace std;

template <typename T>
void test(vector<T> a, vector<T> b, const T& val);

int main() {



    vector<int> aInt = {1, 2, 3, 4, 5};
    vector<int> bInt = {2, 3, 4, 5, 6};
    cout << "TEST AVEC INT ---------------" << endl;
    test(aInt,bInt,2);

    vector<char> aChar = {'a','b', 'c'};
    vector<char> bChar = {'d','e', 'f'};
    cout << "TEST AVEC CHAR---------------"  << endl;
    test(aChar, bChar, 'o');

    vector<double> aDouble = {1.0, 3.4, 5.6};
    vector<double> bDouble = {5.7,.3, 8.2};
    cout << "TEST AVEC DOUBLE---------------"  << endl;
    test(aDouble, bDouble, .5);




    system("PAUSE");
    return EXIT_SUCCESS;
}

template <typename T>
void test(vector<T> a, vector<T> b, const T& val){
    cout << "TEST VECTEUR" << endl<< endl;

    Vecteur<T> aBis = a;
    Vecteur<T> bBis = b;
    Vecteur<T> c = aBis*bBis;
    cout << "a*b " << c << endl;
    Vecteur<T> g = aBis*17;
    cout << "a*17 " << g << endl;
    Vecteur<T> d = aBis+bBis;
    cout << "a+b " << d << endl;
    Vecteur<T> e = bBis-aBis;
    cout << "a-b " << e << endl;
    e.resize(4);
    cout << "resize1 " << e << endl;
    e.resize(6,4);
    cout << "resize2 " <<  e << endl;
    cout << "size " <<  e.size() << endl;

    cout << endl;
    cout << "TEST MATRICE" << endl << endl;

    Matrice<T> m(3,2);
    m.resize(2,2);
    cout << "resize ligne et colonne a 6 " << m << endl;
    m.resize(5);
    cout << "resize ligne a 5 " << m << endl;

    Matrice<T> mVide(0);
    cout << "Matrice mVide : " << boolalpha << mVide.estVide() << endl;

    cout << "Matrice m regiliere : " << boolalpha << m.estReguliere() << endl;

    m.at(1) = a;
    m.at(0) = b;
    cout << "somme des lignes de " << m  << ":" << m.sommeLigne() << endl;
    cout << "somme des colonnes de " << m  << ":" << m.sommeColonne() << endl;
    m.resize(5,5);
    cout << "somme des diagonale GD de " << m << ": " << m.sommeDiagonaleGD() <<
         endl;
    cout << "somme des diagonale DG de " << m << ": " << m.sommeDiagonaleDG() <<
         endl;

    cout << "multi par 2 de " << m << ": "  << 2*val << endl;

    cout << "multi par elle meme : "<< m*m << endl;

    cout << "add par elle meme : "<< m+m << endl;
}
