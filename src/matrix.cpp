#include "matrix.h"
#include <cmath>
#include <algorithm>

Matrix::Matrix(size_t r, size_t c) : rows(r), cols(c) {
    data.resize(rows * cols, 0.0f);
}

float& Matrix::operator()(size_t r, size_t c) {
    if (r >= rows || c >= cols) {
        throw std::out_of_range("Matrix index out of bounds");
    }
    return data[r * cols + c];
}

const float& Matrix::operator()(size_t r, size_t c) const {
    if (r >= rows || c >= cols) {
        throw std::out_of_range("Matrix index out of bounds");
    }
    return data[r * cols + c];
}

Matrix Matrix::operator+(const Matrix& other) const {
    size_t r = other.rows();
    size_t c = other.cols();

    if (rows != r || cols != c) {
        throw std::invalid_argument("Rows or Cols do not match");
    }

    Matrix newMat(rows, cols);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            newMat(i, j) = (*this)(i,j) + other(i,j);
        }
    }

    return newMat;
}

Matrix Matrix::operator*(const Matrix& other) const {
    // TODO: 1. Check if inner dimensions match for dot product (cols == other.rows)
    // TODO: 2. If they don't match, throw a std::invalid_argument exception
    // TODO: 3. Create a new Matrix object of size (this->rows, other.cols)
    // TODO: 4. Implement the standard matrix multiplication algorithm (triple nested loop)
    // TODO: 5. Return the resulting Matrix
    size_t r = other.rows();
    size_t c = other.cols();

    if (cols != r) {
        throw std::invalid_argument("Rows or Cols do not match");
    }

    Matrix newMat(rows, c);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < c; j++) {
            for (size_t k = 0; k < cols; k++) {
                newMat(i, j) = newMat(i, j) + ((*this)(i, k) + other(k, j));
            }
        }
    }

    return newMat;
}

Matrix Matrix::operator*(float scalar) const {
    Matrix newMat(rows, cols);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            newMat(i, j) = (*this)(i,j) * scalar;
        }
    }

    return newMat;
}

void Matrix::print() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << (*this)(i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

Matrix Matrix::relu() const {
    Matrix newMat(rows, cols);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            newMat(i, j) = std::max(0.0f, (*this)(i, j));
        }
    }

    return newMat;
}

Matrix Matrix::sigmoid() const {
    Matrix newMat(rows, cols);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            float val = (*this)(i, j);
            
            newMat(i, j) = 1.0f / (1.0f + std::exp(-val));
        }
    }

    return newMat;
}