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
#ifndef MatriceImpl_h
#define MatriceImpl_h

template<typename T>
size_t Matrice<T>::size() const noexcept{
    return matrice.size();
}

template<typename T>
const Ligne<T>& Matrice<T>::at(size_t i) const{
    return matrice.at(i);
}


#endif /* MatriceImpl_h */
