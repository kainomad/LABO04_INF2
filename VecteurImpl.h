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

template <typename T>
T& Vecteur<T>::at(size_t n) {
    return data.at(n);
}

template <typename T>
const T& Vecteur<T>::at(size_t n) const{
    return data.at(n);
}

template <typename T>
size_t Vecteur<T>::size() const {
    return data.size();
}



template <typename T>
T Vecteur<T>::somme() const{
    try{
        // faire une méthode à part pour la vérification
        if (isdigit(this->vector.at(0))){
            //throw <#expression#>;
        }
        
    }
    catch(
    return this->v.size();
}

template <typename T>
size_t Vecteur<T>::size() const{
    
    return this->v.size();
}

template <typename T>
void Vecteur<T>::resize(size_t n){
    this->v.resize(n);
}
/*template <typename T>
 void Vecteur<T>::resize(size_t n, const T& val){
 
 }
 */


#endif /* VecteurImpl_h */
