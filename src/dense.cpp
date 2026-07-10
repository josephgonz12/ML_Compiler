#include "../include/dense.h"
#include <cstdlib> 

Dense::Dense(size_t input_size, size_t output_size) 
    : weights(input_size, output_size), biases(1, output_size) 
{
    size_t r = weights.get_rows();
    size_t c = weights.get_cols();

    for (size_t i = 0; i < r; i++) {
        for (size_t j = 0; j < c; j++) {
            weights(i, j) = ((float)std::rand() / RAND_MAX) * 0.1f;
        }
    }
}

Matrix Dense::forward(const Matrix& input) {
    return (input * weights) + biases;
}