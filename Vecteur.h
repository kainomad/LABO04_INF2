/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : main.cpp
 Groupe      : Labo_04
 Auteur(s)   : Chau Ying Kot, Johann Werkle
 Date        : 02.04.2019
 
 But         : Cette classe a pour but de modelise un vecteur avec la classe
               Vector et de gerer les differents exceptions avec des classes
               d'exceptions personalisees
 
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
    /**
     * @throw DepacementCapacite si la multiplication depasse la capacite du type
     * @throw ArgumentInvalide si l'un des paramètres est incompatible
     */
    Vecteur<T> operator*(const Vecteur<T>& v2) const;
    /**
     * @throw DepacementCapacite si la multiplication depasse la capacite du type
     * @throw ArgumentInvalide si l'un des paramètres est incompatible
     */
    Vecteur<T> operator*(const T mult) const;
    friend Vecteur<T> operator*(const T mult, const Vecteur<T>& v){
        //Nécessaire pour instancier la fonction dans le main à la compilation
        return v * mult;
    }
    /**
     * @throw DepacementCapacite si la somme depasse la capacite du type
     */
    Vecteur<T> operator+(const Vecteur<T>& v2) const;
    
    /**
     * @throw DepacementCapacite si la somme depasse la capacite du type
     */
    Vecteur<T> operator-(const Vecteur<T>& v2) const;


    /**
     *
     * @return Retourne la taille du vecrteur
     */
    size_t size() const noexcept ;

    /**
     *
     * @param n
     * @return Retourne une referece sur l'element à la postion n du vecteur
     */
    T& at(size_t n);

    /**
     *
     * @param n
     * @return Retourne une referece constant sur l'element à la postion n du
     *         vecteur
     */
    const T& at(size_t n) const;

    /**
     * Redefinit le nombre d'element dans le vecteur
     * @param n
     */
    void resize(size_t n);

    /**
     * Redefinit le nombre d'element dans le vecteur. Si n est plus grand que
     * la taille avant redefinition, vaCompl sera utiliser pour completer le
     * vecteur
     * @param n
     * @param valCompl
     */
    void resize(size_t n, const T& valCompl);

    /**
     *
     * @return Retourne la somme des elements du vecteur
     */
    T somme() const;
    
private:
    std::vector<T> data;
};



#include "VecteurImpl.h"
#endif /* Vecteur_h */


