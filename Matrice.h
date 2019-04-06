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
#ifndef Matrice_h
#define Matrice_h

#include "Vecteur.h"

template <typename T> using Ligne = Vecteur<T>;


template <typename T>
class Matrice;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrice<T>& matrice){
    os << "[";
    for(size_t i = 0; i < matrice.size(); ++i){
        os << matrice.at(i);
    }
    os << "]";
    return os ;
}

template <typename T>
class Matrice{
    friend std::ostream& operator<< <T> (std::ostream& os, const Matrice<T>& vecteur);


public:
    Matrice() {}
    Matrice(size_t ligne) : matrice(Vecteur<Vecteur<T>>(ligne)) {};
    Matrice(const Vecteur<T>& ligne, const Vecteur<T>& colonne) {
        for(size_t i = 0; i < ligne ;++i){
            matrice.at(i) = Ligne<T>(colonne);
        }
    };

    size_t size() const noexcept ;

    Ligne<T>& at(size_t i);
    const Ligne<T>& at(size_t i) const;


private:
    Vecteur<Ligne<T>> matrice;
};

#include "MatriceImpl.h"
#endif /* Matrice_h */
