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
void Vecteur<T>::resize(size_t n){
    data.resize(n);
}
template <typename T>
 void Vecteur<T>::resize(size_t n, const T& valCompl){
 data.resize(n, valCompl);
 }

template <typename T>
T Vecteur<T>::somme() const{
    T total = 0;
    try{
        
        for (int i = 0; i < data.size(); i++){
            total += data.at(i);
        }
        // faire une méthode à part pour la vérification
        if (isdigit(this->vector.at(0))){
            //throw <#expression#>;
        }
        
    }
    catch(exception& e){
        cout << e.what();
    }
    return total;

}

template <typename T>
Vecteur<T> Vecteur<T>::operator*(const Vecteur<T>& v2) const{
    vector<T> result;
    size_t tailleMax = max(data.size(), v2.size());
    for (size_t i = 0; i < tailleMax ; i++){
        result.push_back (data.at(i) * v2.at(i));
    }
    
    return result;
}

template <typename T>
Vecteur<T> Vecteur<T>::operator*(const T mult) const{
    vector<T> result;
    for (size_t i = 0; i < data.size(); i++){
        result.push_back (data.at(i) * mult);
    }
    return result;
}

template <typename T>
Vecteur<T> Vecteur<T>::operator+(const Vecteur<T>& v2) const{
    vector<T> result;
    size_t tailleMax = max(data.size(), v2.size());
    for (size_t i = 0; i < tailleMax ; i++){
        result.push_back (data.at(i) + v2.at(i));
    }
    return result;
}

template <typename T>
Vecteur<T> Vecteur<T>::operator-(const Vecteur<T>& v2) const{
    vector<T> result;
    size_t tailleMax = max(data.size(), v2.size());
    for (size_t i = 0; i < tailleMax ; i++){
        result.push_back (data.at(i) - v2.at(i));
    }
    return result;
}


#endif /* VecteurImpl_h */
