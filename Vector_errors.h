//
// Created by chauying on 04.04.19.
//

#include <stdexcept>

#ifndef LABO04_INF2_VECTOR_ERROR_H
#define LABO04_INF2_VECTOR_ERRORS_H


class OutOfRange : public std::logic_error{
public:
    OutOfRange(const std::string& what_arg) noexcept : logic_error(what_arg){}
    OutOfRange(const char* what_arg) noexcept : logic_error(what_arg) {}
    std::string where() const noexcept {
        return currentClass;
    }

private:
    const std::string currentClass = "Vecteur";
};


#endif //LABO04_INF2_VECTOR_ERROR_H
