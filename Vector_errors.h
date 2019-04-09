//
// Created by chauying on 04.04.19.
//


#ifndef LABO04_INF2_VECTOR_ERROR_H
#define LABO04_INF2_VECTOR_ERRORS_H

#include <stdexcept>


class DepacementCapacite : public std::out_of_range {
public:
    DepacementCapacite(const std::string& classe,
                       const std::string& what_arg = ": le resultat de l'operation depasse la capcite du type") noexcept
            : out_of_range(what_arg), currentClass(classe) {}

    DepacementCapacite(const std::string& classe, const char* what_arg) noexcept
            : out_of_range(what_arg), currentClass(classe) {}

    std::string where() const noexcept {
        return currentClass;
    }

private:
    const std::string currentClass;
};


#endif //LABO04_INF2_VECTOR_ERROR_H
