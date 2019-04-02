//
//  VecteurImpl.h
//  LABO04_INF2
//
//  Created by Johann Werkle on 02.04.19.
//  Copyright © 2019 Johann Werkle. All rights reserved.
//

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



#endif /* VecteurImpl_h */
