/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : VecteurImpl.h
 Groupe      : Labo_04
 Auteur(s)   : Chau Ying Kot, Johann Werkle
 Date        : 02.04.2019
 
 But         : Implémentation des fonctions de la classe Vecteur
 
 Remarque(s) : -
 
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef VecteurImpl_h
#define VecteurImpl_h

#include "Vector_errors.h"

#include <vector>
#include <ostream>

template<typename T>
T& Vecteur<T>::at(size_t n) {
    try {
        return data.at(n);
    } catch (std::out_of_range& e) {
        throw DepacementTaille("Dans Vecteur");
    }
}

template<typename T>
const T& Vecteur<T>::at(size_t n) const {
    try {
        return data.at(n);
    } catch (std::out_of_range& e) {
        throw DepacementTaille("Dans Vecteur");
    }
}

template<typename T>
size_t Vecteur<T>::size() const noexcept {
    return data.size();
}

template<typename T>
void Vecteur<T>::resize(size_t n) {
    try {
        data.resize(n);
    }
    catch (std::length_error& e) {
        throw DepacementVector("Dans Vecteur");
    }
}

template<typename T>
void Vecteur<T>::resize(size_t n, const T& valCompl) {
    try {
        data.resize(n, valCompl);
    }
    catch (std::length_error& e) {
        throw DepacementVector("Dans Vecteur");
    }
}

template<typename T>
T Vecteur<T>::somme() const {
    try {
        T total = data.at(0);
        if (data.size() > 1) {
            for (size_t i = 1; i < data.size(); i++) {
                total += data.at(i);
            }
        }
        return total;
    }
    catch (std::overflow_error& e) {
        throw DepacementCapacite("Dans Vecteur");
    }
}

template<typename T>
Vecteur<T> Vecteur<T>::operator*(const Vecteur<T>& v2) const {
    try {
        std::vector<T> result;
        size_t tailleMax = std::max(data.size(), v2.size());
        for (size_t i = 0; i < tailleMax; i++) {
            result.push_back(data.at(i) * v2.at(i));
        }
        return result;
    }
    catch (std::overflow_error& e) {
        throw DepacementCapacite("Dans Vecteur");

    }
    catch (std::invalid_argument& e) {
        throw ArgumentInvalide("Dans Vecteur");

    }
}

template<typename T>
Vecteur<T> Vecteur<T>::operator*(const T mult) const {
    try {
        std::vector<T> result;
        for (size_t i = 0; i < data.size(); i++) {
            result.push_back(data.at(i) * mult);
        }
        return result;
    }
    catch (std::overflow_error& e) {
        throw DepacementCapacite("Dans Vecteur");
    }
    catch (std::invalid_argument& e) {
        throw ArgumentInvalide("Dans Vecteur");

    }
}

template<typename T>
Vecteur<T> Vecteur<T>::operator+(const Vecteur<T>& v2) const {
    std::vector<T> result;
    size_t tailleMax = std::max(data.size(), v2.size());
    for (size_t i = 0; i < tailleMax; ++i) {
        if ((std::numeric_limits<T>::max() - data.at(i)) < v2.at(i)) {
            throw DepacementCapacite("Dans Vecteur ");
        }
        result.push_back(data.at(i) + v2.at(i));
       
    }
    return result;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator-(const Vecteur<T>& v2) const {
    try {
        std::vector<T> result;
        size_t tailleMax = std::max(data.size(), v2.size());
        for (size_t i = 0; i < tailleMax; i++) {
            result.push_back(data.at(i) - v2.at(i));
        }
        return result;
    }
    catch (std::overflow_error& e) {
        throw DepacementCapacite("Dans Vecteur");
    }
}


#endif /* VecteurImpl_h */
