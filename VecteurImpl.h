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

#ifndef VecteurImpl_h
#define VecteurImpl_h

#include <vector>
#include <ostream>

template<typename T>
T& Vecteur<T>::at(size_t n) {
    try {
        return data.at(n);
    } catch (std::out_of_range& e) {
        throw std::out_of_range("Dans Vecteur : La position donnee depasse la "
                                "taille du vecteur ");
    }
}

template<typename T>
const T& Vecteur<T>::at(size_t n) const {
    try {
        return data.at(n);
    } catch (std::out_of_range& e) {
        throw std::out_of_range("Dans Vecteur : La position donnee depasse la "
                                "taille du vecteur ");
    }
}

template<typename T>
size_t Vecteur<T>::size() const noexcept {
    return data.size();
}

template<typename T>
void Vecteur<T>::resize(size_t n) {
    data.resize(n);
}

template<typename T>
void Vecteur<T>::resize(size_t n, const T& valCompl) {
    data.resize(n, valCompl);
}

template<typename T>
T Vecteur<T>::somme() const {
    T total = 0;
    for (size_t i = 0; i < data.size(); i++) {
        total += data.at(i);
    }
    return total;

template <typename T>
T Vecteur<T>::somme() const{
    try {
        T total = data.at(0);
        if (data.size() > 1){
            for (size_t i = 1; i < data.size(); i++){
                total += data.at(i);
            }
        }
        return total;
    }
    catch (std::out_of_range & e){
        // trouver la bonne erreur
        std::cout << "Le vecteur doit contenir au moins un élément pour faire une somme" << std::endl
        << e.what();
        exit(EXIT_FAILURE);
    }
}

template<typename T>
Vecteur<T> Vecteur<T>::operator*(const Vecteur<T>& v2) const {
    std::vector<T> result;
    size_t tailleMax = std::max(data.size(), v2.size());
    for (size_t i = 0; i < tailleMax; i++) {
        result.push_back(data.at(i) * v2.at(i));
    }

    return result;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator*(const T mult) const {
    std::vector<T> result;
    for (size_t i = 0; i < data.size(); i++) {
        result.push_back(data.at(i) * mult);
    }
    return result;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator+(const Vecteur<T>& v2) const {
    std::vector<T> result;
    size_t tailleMax = std::max(data.size(), v2.size());
    for (size_t i = 0; i < tailleMax; ++i) {
        if ((std::numeric_limits<T>::max() - data.at(i)) < v2.at(i)) {
            throw std::overflow_error(
                    "Dans Vecteur : le resultat de l'operation "
                    "depasse la capcite du type");
        }
        result.push_back(data.at(i) + v2.at(i));
    }
    return result;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator-(const Vecteur<T>& v2) const {
    std::vector<T> result;
    size_t tailleMax = std::max(data.size(), v2.size());
    for (size_t i = 0; i < tailleMax; i++) {
        result.push_back(data.at(i) - v2.at(i));
    }
    return result;
}


#endif /* VecteurImpl_h */
