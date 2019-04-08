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


#include "Matrice.h"

template<typename T>
size_t Matrice<T>::size() const noexcept {
    return this->matrice.size();
}

template<typename T>
const Ligne<T>& Matrice<T>::at(size_t i) const {
    return this->matrice.at(i);
}

template<typename T>
Ligne<T>& Matrice<T>::at(size_t i) {
    return this->matrice.at(i);
}

//TODO Resize ajout de 0 ?
template<typename T>
void Matrice<T>::resize(size_t ligne) {
    this->matrice.resize(ligne);
}

template<typename T>
void Matrice<T>::resize(size_t ligne, size_t colonne) {
    this->matrice.resize(ligne);
    for (size_t i = 0; i < this->matrice.size(); ++i) {
        this->matrice.at(i).resize(colonne);
    }
}

//TODO vide aucun elem sur tout la matrice ou uniquement sur les lignes ou les
// colonne ?
template<typename T>
bool Matrice<T>::estVide() const noexcept {
    if (this->matrice.size() == 0) {
        return true;
    }
    for (size_t i = 0; i < this->matrice.size(); ++i) {
        if (this->matrice.at(i).size() != 0) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool Matrice<T>::estReguliere() const noexcept {
    if (this->estVide()) {
        return true;
    }
    size_t firstLineSize = this->matrice.at(0).size();
    for (size_t i = 1; i < this->matrice.size(); ++i) {
        if (this->matrice.at(i).size() != firstLineSize) {
            return false;
        }
    }
    return true;
}

template<typename T>
Vecteur<T> Matrice<T>::sommeLigne() const {
    Vecteur<T> resultat(this->matrice.size());
    for (size_t i = 0; i < this->matrice.size(); ++i) {
        for (size_t j = 0; j < this->matrice.at(i).size(); ++j) {
            resultat.at(i) += this->matrice.at(i).at(j);
        }
    }
    return resultat;
}


template<typename T>
Vecteur<T> Matrice<T>::sommeColonne() const {
    Vecteur<T> resultat(this->matrice.at(1).size());
    for (size_t i = 0; i < this->matrice.size(); ++i) {
        for (size_t j = 0; j < this->matrice.at(i).size(); ++j) {
            resultat.at(j) += this->matrice.at(i).at(j);
        }
    }
    return resultat;
}


template<typename T>
T Matrice<T>::sommeDiagonaleGD() const {
    try {
        if (!this->estReguliere()) {
            throw std::out_of_range("Matrice n'est pas reguliere");
        }
        T res = 0;
        for (size_t i = 0; i < this->matrice.size(); ++i) {
            res += this->matrice.at(i).at(i);
        }
        return res;
    } catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
}

template<typename T>
T Matrice<T>::sommeDiagonaleDG() const {
    try {
        if (!this->estReguliere()) {
            throw std::out_of_range("Matrice n'est pas reguliere");
        }
        T res = 0;
        for (size_t i = 0; i < this->matrice.size(); ++i) {
            res += this->matrice.at(i).at(this->matrice.size() - 1 - i);
        }
        return res;
    } catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
}

template<typename T>
Matrice<T> Matrice<T>::operator*(const T& val) const{
    Matrice<T> temp(this->matrice.size());
    for (size_t i = 0; i < this->matrice.size(); ++i) {
        temp.at(i) = this->matrice.at(i) * val;
    }
    return temp;
}

template<typename T>
Matrice<T> Matrice<T>::operator*(const Matrice<T>& matrice) const{
    try {

        if (this->size() != matrice.size()) {
            throw std::out_of_range("les colonnes ne sont pas compatible");
        }
        Matrice<T> temp(this->size());
        for (size_t i = 0; i < this->size(); ++i) {
            if (this->at(i).size() != matrice.at(i).size()) {
                throw std::out_of_range("les colonnes ne sont pas compatible");
            }
            temp.at(i).resize(this->at(i).size());
            for (size_t j = 0; j < this->at(i).size(); ++j) {
                temp.at(i).at(j) = this->at(i).at(j) * matrice.at(i).at(j);
            }
        }
        return temp;
    }
    catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
}

template<typename T>
Matrice<T> Matrice<T>::operator+(const Matrice<T>& matrice) const {
    try {

        if (this->size() != matrice.size()) {
            throw std::out_of_range("les colonnes ne sont pas compatible");
        }
        Matrice<T> temp(this->size());
        for (size_t i = 0; i < this->size(); ++i) {
            if (this->at(i).size() != matrice.at(i).size()) {
                throw std::out_of_range("les colonnes ne sont pas compatible");
            }
            temp.at(i).resize(this->at(i).size());
            for (size_t j = 0; j < this->at(i).size(); ++j) {
                temp.at(i).at(j) = this->at(i).at(j) + matrice.at(i).at(j);
            }
        }
        return temp;
    }
    catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
}


#endif /* MatriceImpl_h */
