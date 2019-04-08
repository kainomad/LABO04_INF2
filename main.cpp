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

    cout << "TEST VECTEUR" << endl;

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 5, 6};
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

    Matrice<int> m(3,2);
    m.resize(2,2);
    cout << "resize ligne et colonne a 6 " << m << endl;
    m.resize(5);
    cout << "resize ligne a 5 " << m << endl;

    Matrice<int> mVide(0);
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

    cout << "multi par 2 de " << m << ": "  << m*2 << endl;

    cout << "multi par elle meme : "<< m*m << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
