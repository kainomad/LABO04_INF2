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
size_t Matrice<T>::size() const noexcept {
    return matrice.size();
}

template<typename T>
const Ligne<T>& Matrice<T>::at(size_t i) const {
    return matrice.at(i);
}

template<typename T>
Ligne<T>& Matrice<T>::at(size_t i) {
    return matrice.at(i);
}

//TODO Resize ajout de 0 ?
template<typename T>
void Matrice<T>::resize(size_t ligne) {
    matrice.resize(ligne);
}

template<typename T>
void Matrice<T>::resize(size_t ligne, size_t colonne) {
    matrice.resize(ligne);
    for (size_t i = 0; i < matrice.size(); ++i) {
        matrice.at(i).resize(colonne);
    }
}

//TODO vide aucun elem sur tout la matrice ou uniquement sur les lignes ou les
// colonne ?
template<typename T>
bool Matrice<T>::estVide() const noexcept {
    if (matrice.size() == 0) {
        return true;
    }
    for (size_t i = 0; i < matrice.size(); ++i) {
        if (matrice.at(i).size() != 0) {
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
    size_t firstLineSize = matrice.at(0).size();
    for (size_t i = 1; i < matrice.size(); ++i) {
        if (matrice.at(i).size() != firstLineSize) {
            return false;
        }
    }
    return true;
}

template<typename T>
Vecteur<T> Matrice<T>::sommeLigne() const {
    Vecteur<T> resultat(matrice.size());
    for (size_t i = 0; i < matrice.size(); ++i) {
        for (size_t j = 0; j < matrice.at(i).size(); ++j) {
            resultat.at(i) += matrice.at(i).at(j);
        }
    }
    return resultat;
}


template<typename T>
Vecteur<T> Matrice<T>::sommeColonne() const {
    Vecteur<T> resultat(matrice.at(1).size());
    for (size_t i = 0; i < matrice.size(); ++i) {
        for (size_t j = 0; j < matrice.at(i).size(); ++j) {
            resultat.at(j) += matrice.at(i).at(j);
        }
    }
    return resultat;
}


template<typename T>
T Matrice<T>::sommeDiagonaleGD() const {
    try {
        if(!this->estReguliere()){
            throw std::out_of_range("Matrice n'est pas reguliere");
        }
        T res = 0;
        for (size_t i = 0; i <  matrice.size(); ++i) {
            res += matrice.at(i).at(i);
        }
        return res;
    } catch (std::out_of_range& e){
        std::cout << e.what() << std::endl;
    }
}

template<typename T>
T Matrice<T>::sommeDiagonaleDG() const {
    try {
        if(!this->estReguliere()){
            throw std::out_of_range("Matrice n'est pas reguliere");
        }
        T res = 0;
        for (size_t i = 0; i <  matrice.size(); ++i) {
            res += matrice.at(i).at(matrice.size()-1-i);
        }
        return res;
    } catch (std::out_of_range& e){
        std::cout << e.what() << std::endl;
    }}

#endif /* MatriceImpl_h */
