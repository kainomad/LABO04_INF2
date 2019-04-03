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

#ifndef Vecteur_h
#define Vecteur_h
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Vecteur {
private:
    
    
    size_t size() const;
    void resize(size_t n);
//    void resize(size_t n, const T& val);
    T somme() const;
public:
    vector<T> v;
};




#include "VecteurImpl.h"
#endif /* Vecteur_h */

