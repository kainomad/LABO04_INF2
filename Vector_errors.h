/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Vector_errors.h
Groupe      : Labo_04
Auteur(s)   : Chau Ying Kot, Johann Werkle
Date        : 02.04.2019

But         : Erreurs

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/
#ifndef LABO04_INF2_VECTOR_ERRORS_H
#define LABO04_INF2_VECTOR_ERRORS_H

#include <stdexcept>
// out_of_range
// overflow_error
// length_error
// invalid_argument

class DepacementCapacite : public std::overflow_error {
public:
    DepacementCapacite(const std::string& classe,
                       const std::string& what_arg = "le resultat de l'operation depasse la capacite du type") noexcept
    :  currentClass(classe), overflow_error(what_arg) {}
    
    std::string where() const noexcept {
        return currentClass;
    }
    
private:
    const std::string currentClass = "";
};

class DepacementTaille : public std::out_of_range {
public:
    DepacementTaille(const std::string& classe,
                     const std::string& what_arg = "le resultat de l'operation depasse la taille du tableau") noexcept
    :  currentClass(classe), out_of_range(what_arg) {}
    
    std::string where() const noexcept {
        return currentClass;
    }
    
private:
    const std::string currentClass = "";
};

class DepacementVector : public std::length_error {
public:
    DepacementVector(const std::string& classe,
                     const std::string& what_arg = "le resultat de l'operation depasse la taille maximale d'un vector") noexcept
    :  currentClass(classe), length_error(what_arg) {}
    
    std::string where() const noexcept {
        return currentClass;
    }
    
private:
    const std::string currentClass = "";
};
class ArgumentInvalide : public std::invalid_argument {
public:
    ArgumentInvalide(const std::string& classe,
                     const std::string& what_arg = "le resultat de l'operation depasse la taille maximale d'un vector") noexcept
    :  currentClass(classe), std::invalid_argument(what_arg) {}
    
    std::string where() const noexcept {
        return currentClass;
    }
    
private:
    const std::string currentClass = "";
};


#endif //LABO04_INF2_VECTOR_ERROR_H
