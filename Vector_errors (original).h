//
// Created by chauying on 04.04.19.
//


#ifndef LABO04_INF2_VECTOR_ERRORS_H
#define LABO04_INF2_VECTOR_ERRORS_H

#include <stdexcept>

// out_of_range
// overflow_error
// length_error
// invalid_argument
// bad_alloc

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
                     const std::string& what_arg = "le resultat de l'operation depasse la taille d'un vector") noexcept
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
                     const std::string& what_arg = "Le(s) paramètre(s) de la fonction n'est/ne sont pas valide(s)") noexcept
    :  currentClass(classe), invalid_argument(what_arg) {}
    
    std::string where() const noexcept {
        return currentClass;
    }
    
private:
    const std::string currentClass = "";
};

#endif //LABO04_INF2_VECTOR_ERROR_H
