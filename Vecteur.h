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
#include <ostream>
//#include "Vector_errors.h"

template <typename T>
class Vecteur;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vecteur<T>& vector){
    os << "[";
    for(size_t i = 0; i < vector.size(); ++i){
        if(i != 0){
            os << ", ";
        }
        os << vector.at(i);
    }
    os << "]";
    return os ;
}

template <typename T>
class Vecteur {
public:
    Vecteur() : data(std::vector<T>(0)) {};
    Vecteur(size_t n) : data(std::vector<T>(n)) {};
    Vecteur(std::vector<T> vector) : data(vector) {};
    
    friend std::ostream& operator<< <T> (std::ostream& os, const Vecteur<T>& vecteur);
    Vecteur<T> operator*(const Vecteur<T>& v2) const;
    Vecteur<T> operator+(const Vecteur<T>& v2) const;
    Vecteur<T> operator-(const Vecteur<T>& v2) const;
    Vecteur<T> operator*(const T mult) const;
//    std::ostream& operator* <T> (T value);

    size_t size() const noexcept ;

    T& at(size_t n);
    const T& at(size_t n) const;
    void resize(size_t n);
    void resize(size_t n, const T& valCompl);
    T somme() const;
    
private:
    std::vector<T> data;
};


//template <typename T> class Vecteur;





#include "VecteurImpl.h"
#endif /* Vecteur_h */

