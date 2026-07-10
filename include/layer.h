#pragma once
#include "matrix.h"

class Layer {
public:
    virtual ~Layer() = default;
    
    virtual Matrix forward(const Matrix& input) = 0;
};