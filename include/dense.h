#pragma once
#include "layer.h"

class Dense : public Layer {
private:
    Matrix weights;
    Matrix biases;

public:
    Dense(size_t input_size, size_t output_size);

    Matrix forward(const Matrix& input) override;
};