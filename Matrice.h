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

#include <Vecteur.h>

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

template<typename T>
Matrice<T> operator*(const Matrice<T>& matrice, const T& val) {
    Matrice<T> temp(matrice.size());
    for(size_t i  = 0; i < matrice.size(); ++i){
        temp.at(i) = matrice.at(i)*val;
    }
    return temp;
}

template<typename T>
Matrice<T> operator*(const T& val, const Matrice<T>& matrice) {
    return matrice * val;
}



template <typename T>
class Matrice{
    friend std::ostream& operator<< <T> (std::ostream& os, const Matrice<T>& vecteur);

public:
    Matrice() {}
    Matrice(size_t ligne) : matrice(Vecteur<Vecteur<T>>(ligne)) {};
    Matrice(size_t ligne, size_t colonne) : matrice(Vecteur<Vecteur<T>>(ligne)) {
        for(size_t i = 0; i < ligne ;++i){
            this->at(i).resize(colonne);
        }
    };

    size_t size() const noexcept ;

    Ligne<T>& at(size_t i);
    const Ligne<T>& at(size_t i) const;

    void resize(size_t ligne);
    void resize(size_t ligne, size_t colonne);

    bool estVide() const noexcept;
    bool estReguliere() const noexcept;

    Vecteur<T> sommeLigne() const;
    Vecteur<T> sommeColonne() const;

    T sommeDiagonaleGD() const;
    T sommeDiagonaleDG() const;

    Matrice<T> operator*(const T& val) const;
    Matrice<T> operator*(const Matrice<T>& matrice) const;
    Matrice<T> operator+(const Matrice<T>& matrice) const;


private:
    Vecteur<Ligne<T>> matrice;
};

#include "MatriceImpl.h"
#endif /* Matrice_h */
