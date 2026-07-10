#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

class Matrix {
private:
    size_t rows;
    size_t cols;
    // The flat 1D array holding 2D data
    std::vector<float> data; 

public:
    // Constructor: Initializes a matrix of size r x c with zeros
    Matrix(size_t r, size_t c);

    // Getters
    size_t get_rows() const { return rows; }
    size_t get_cols() const { return cols; }

    // Operator overloading to easily access elements like mat(0, 1)
    float& operator()(size_t r, size_t c);
    const float& operator()(size_t r, size_t c) const;

    // Element-wise addition (for adding biases)
    Matrix operator+(const Matrix& other) const;

    // Matrix multiplication (the core of the forward pass)
    Matrix operator*(const Matrix& other) const;

    // Scalar multiplication (scaling values)
    Matrix operator*(float scalar) const;

    void print() const;

    // Activation functions
    Matrix relu() const;
    Matrix sigmoid() const;
};