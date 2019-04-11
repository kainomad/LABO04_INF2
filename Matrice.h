/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Matrice.h
 Groupe      : Labo_04
 Auteur(s)   : Chau Ying Kot, Johann Werkle
 Date        : 02.04.2019
 
 But         : Cette classe represente un matrice et utilise la classe
               Vecteur pour l'implementer
 
 Remarque(s) : -
 
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef Matrice_h
#define Matrice_h

#include "Vecteur.h"

template<typename T> using Ligne = Vecteur<T>;


template<typename T>
class Matrice;

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrice<T>& matrice) {
    os << "[";
    for (size_t i = 0; i < matrice.size(); ++i) {
        os << matrice.at(i);
    }
    os << "]";
    return os;
}

template<typename T>
Matrice<T> operator*(const Matrice<T>& matrice, const T& val) {
    Matrice<T> temp(matrice.size());
    for (size_t i = 0; i < matrice.size(); ++i) {
        temp.at(i) = matrice.at(i) * val;
    }
    return temp;
}

template<typename T>
Matrice<T> operator*(const T& val, const Matrice<T>& matrice) {
    return matrice * val;
}


template<typename T>
class Matrice {
    friend std::ostream&
    operator<<<T>(std::ostream& os, const Matrice<T>& vecteur);

public:
    Matrice() {}

    Matrice(size_t ligne) : matrice(Vecteur<Vecteur<T>>(ligne)) {};

    Matrice(size_t ligne, size_t colonne) : matrice(
            Vecteur<Vecteur<T>>(ligne)) {
        for (size_t i = 0; i < ligne; ++i) {
            this->at(i).resize(colonne);
        }
    };

    /**
     *
     * @return Retourne le nombre de lignes de la matrice
     */
    size_t size() const noexcept;

    /**
     * @param i
     * @return retourne une reference le Vecteur de la ligne i de la matrice
     * @throw Si i depasse la taille de Vecteur, throw 
     */
    Ligne<T>& at(size_t i);

    /**
    * @param i
    * @return retourne une réference constant le Vecteur de la ligne i de la
     *        matrice
    * @throw Si i depasse la taille de Vecteur, throw
    */
    const Ligne<T>& at(size_t i) const;

    /**
     * redefinit le nombre de ligne de la matrice
     * @param ligne
     */
    void resize(size_t ligne);

    /**
     * redefinit le nombre de ligne et le nombre de colonne de la matrice
     * @param ligne
     * @param colonne
     */
    void resize(size_t ligne, size_t colonne);

    /**
     *
     * @return Indique si la matrice contient aucun element
     */
    bool estVide() const noexcept;

    /**
     * Indique que toutes les lignes ont la même longueur. Par convention une
     * matrice vide est régulière
     * @return
     */
    bool estReguliere() const noexcept;

    /**
     *
     * @return Retorune un vecteur contant la somme de chaque lignes
     */
    Vecteur<T> sommeLigne() const;

    /**
     *
     * @return Retorune un vecteur contant la somme de chaque colonne
     */
    Vecteur<T> sommeColonne() const;

    /**
     *
     * @return Retourne la somme de la diagonale Gauche-Droite
     * @throw DepacementCapacite si la somme depasse la capacite du type
     */
    T sommeDiagonaleGD() const;

    /**
     *
     * @return Retourne la somme de la diagonale Droite-Gauche
     * @throw DepacementCapacite si la somme depasse la capacite du type
     */
    T sommeDiagonaleDG() const;

    Matrice<T> operator*(const T& val) const;

    Matrice<T> operator*(const Matrice<T>& matrice) const;

    /**
     * @throw DepacementCapacite si la somme depasse la capacite du type
     */
    Matrice<T> operator+(const Matrice<T>& matrice) const;


private:
    //Donne de la matrice
    Vecteur<Ligne<T>> matrice;
};

#include "MatriceImpl.h"

#endif /* Matrice_h */
