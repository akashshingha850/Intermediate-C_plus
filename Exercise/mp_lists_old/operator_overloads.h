#ifndef OPERATOR_OVERLOADS_H
#define OPERATOR_OVERLOADS_H

#include "cpp/rgbapixel.h"

template <typename T>
bool operator<=(const T& lhs, const T& rhs) {
    const RGBAPixel& left = static_cast<const RGBAPixel&>(lhs);
    const RGBAPixel& right = static_cast<const RGBAPixel&>(rhs);
    return !(right < left); 
}

#endif // OPERATOR_OVERLOADS_H
