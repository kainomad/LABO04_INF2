//
// Created by chauying on 04.04.19.
//


#ifndef LABO04_INF2_VECTOR_ERRORS_H
#define LABO04_INF2_VECTOR_ERRORS_H

#include <stdexcept>


class DepacementCapacite : public std::overflow_error {
public:
    DepacementCapacite(const std::string& classe,
                       const std::string& what_arg = "le resultat de l'operation depasse la capcite du type") noexcept
            : currentClass(classe), overflow_error(what_arg) {}

    std::string where() const noexcept {
        return currentClass;
    }

private:
    const std::string currentClass = "";
};


#endif //LABO04_INF2_VECTOR_ERROR_H
