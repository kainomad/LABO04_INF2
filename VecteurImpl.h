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
        std::cout
        << "Dans Vecteur : La position donnee depasse la taille du vecteur"
        << std::endl;
        exit(EXIT_FAILURE);
    }
}

template<typename T>
const T& Vecteur<T>::at(size_t n) const {
    try {
        return data.at(n);
    } catch (std::out_of_range& e) {
        std::cout
        << "Dans Vecteur : La position donnee depasse la taille du vecteur"
        << e.what();
        exit(EXIT_FAILURE);
    }
}

template<typename T>
size_t Vecteur<T>::size() const noexcept {
    return data.size();
}

template <typename T>
void Vecteur<T>::resize(size_t n) noexcept{
    data.resize(n);
}
template <typename T>
void Vecteur<T>::resize(size_t n, const T& valCompl) noexcept{
    data.resize(n, valCompl);
}

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

template <typename T>
Vecteur<T> Vecteur<T>::operator*(const Vecteur<T>& v2) const{
    std::vector<T> result;
    try {
        size_t tailleMax = std::max(data.size(), v2.size());
        for (size_t i = 0; i < tailleMax ; i++){
            result.push_back (data.at(i) * v2.at(i));
        }
    }
    catch (std::out_of_range & e){
        // trouver la bonne erreur
        std::cout << "Le vecteur doit contenir au moins un élément pour faire une multiplication" << std::endl
        << e.what();
        exit(EXIT_FAILURE);
    }
    return result;
}

template <typename T>
Vecteur<T> Vecteur<T>::operator*(const T mult) const{
    std::vector<T> result;
    try{
        for (size_t i = 0; i < data.size(); i++){
            result.push_back (data.at(i) * mult);
        }
    }
    catch (std::out_of_range & e){
        // trouver la bonne erreur
        std::cout << "Le vecteur doit contenir au moins un élément pour faire une multiplication" << std::endl
        << e.what();
        exit(EXIT_FAILURE);
    }
    return result;
}

template <typename T>
Vecteur<T> Vecteur<T>::operator+(const Vecteur<T>& v2) const{
    std::vector<T> result;
    try {
        
        size_t tailleMax = std::max(data.size(), v2.size());
        for (size_t i = 0; i < tailleMax ; i++){
            result.push_back (data.at(i) + v2.at(i));
        }
        
    }
    catch (std::out_of_range & e){
        // trouver la bonne erreur
        std::cout << "Le vecteur doit contenir au moins un élément pour faire une addition" << std::endl
        << e.what();
        exit(EXIT_FAILURE);
    }
    return result;
}

template <typename T>
Vecteur<T> Vecteur<T>::operator-(const Vecteur<T>& v2) const{
    std::vector<T> result;
    try{
        
        size_t tailleMax = std::max(data.size(), v2.size());
        for (size_t i = 0; i < tailleMax ; i++){
            result.push_back (data.at(i) - v2.at(i));
        }
    }
    catch (std::out_of_range & e){
        // trouver la bonne erreur
        std::cout << "Le vecteur doit contenir au moins un élément pour faire une soustraction" << std::endl
        << e.what();
        exit(EXIT_FAILURE);
    }
    return result;
}


#endif /* VecteurImpl_h */
