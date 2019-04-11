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

template<typename T>
void test(vector<T> a, vector<T> b, const T& val);


template<typename T>
void testError(const vector<T>& v);

template<typename T>
void testText(vector<T> a, vector<T> b);

int main() {


    vector<int> aInt = {1, 2, 3, 4, 5};
//    vector<int> bInt = {2, 3, 4, 5, 6};
//    cout << "TEST AVEC INT ---------------" << endl;
//    test(aInt, bInt, 2);
//
//    vector<double> aDouble = {1.0, 3.4, 5.6};
//    vector<double> bDouble = {5.7, .3, 8.2};
//    cout << "TEST AVEC DOUBLE---------------" << endl;
//    test(aDouble, bDouble, .5);

    testError(aInt);

    system("PAUSE");
    return EXIT_SUCCESS;
}


    
template<typename T>
void test(vector<T> a, vector<T> b, const T& val) {

    cout << "TEST VECTEUR------------------" << endl << endl;

    Vecteur<T> aBis = a;
    Vecteur<T> bBis = b;
    cout << "Vecteur a : " << aBis << endl;
    cout << "Vecteur b : " << bBis << endl;
    Vecteur<T> c = aBis * bBis;
    cout << "a*b = " << c << endl;
    Vecteur<T> g = aBis * 17;
    cout << "a*17 = " << g << endl;
    Vecteur<T> d = aBis + bBis;
    cout << "a+b = " << d << endl;
    Vecteur<T> e = bBis - aBis;
    cout << "a-b = " << e << endl;
    e.resize(4);
    cout << "resize a 4 : " << e << endl;
    e.resize(6, val);
    cout << "resize a 6 en ajouter " << val << " : " << e << endl;
    cout << "size :" << e.size() << endl;

    cout << "somme du vecteur a : " << aBis.somme() << endl;

    cout << endl;
    cout << "TEST MATRICE------------------" << endl << endl;

    Matrice<T> m(3, 2);
    Matrice<T> mVide(0);
    m.at(1) = a;
    m.at(0) = b;

    cout << "Matrice m : " << m << endl;
    cout << "Matrice mVide : " << mVide << endl;

    m.resize(2, 2);
    cout << "resize ligne et colonne a 2 de la matrice m : " << m << endl;
    m.resize(5);
    cout << "resize ligne a 5 de la matrice m: " << m << endl;

    cout << "Matrice mVide estVide : " << boolalpha << mVide.estVide() << endl;

    cout << "Matrice m regiliere : " << boolalpha << m.estReguliere() << endl;


    cout << "Somme des lignes de la matrice m : " << m.sommeLigne() << endl;
    cout << "Somme des colonnes de la matrice m : " << m.sommeColonne() << endl;
    m.resize(5, 5);
    cout << "resize de la matrce m en une matrice 5x5" << endl;
    cout << "somme de la diagonale GD de la matrice m : "
         << m.sommeDiagonaleGD()
         << endl;
    cout << "somme de la diagonale DG de la matrice m : "
         << m.sommeDiagonaleDG()
         << endl;

    cout << "La matrice m multi par " << val << " : " << m * val << endl;

    cout << "la matrice m multi par elle meme : " << m * m << endl;

    cout << "add par elle meme : " << m + m << endl;

    cout << endl;
}

template<typename T>
void testError(const vector<T>& v) {
    cout << "TEST ERROR----------" << endl;
    try {
        Vecteur<T> test = v;
        //test.at(test.size() + 1);
//        test.at(0) = numeric_limits<T>::max();
//        test = test + v;
//        test.at(test.size()+1);
//
        Matrice<T> matrice(2);
        matrice.at(0) = test;
        matrice.at(1) = test;

       // matrice.at(matrice.size()+1);

    } catch (DepassementTaille& e) {
        cout << e.where() << " : " << e.what() << endl;
    } catch (DepassementCapacite& e) {
        cout << e.where() << " : " << e.what() << endl;
    } catch (DepassementVector& e){
        cout << e.where() << " : " << e.what() << endl;
    } catch (ArgumentInvalide& e){
        cout << e.where() << " : " << e.what() << endl;
    } catch (MatriceReguliereError& e){
        cout << e.where() << " : " << e.what() << endl;
    }
}
