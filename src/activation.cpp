#include "../include/activation.h"

Activation::Activation(const std::string& type) : activation_type(type) {
    if (type != "relu" && type != "sigmoid") {
        throw std::invalid_argument("Invalid activation name");
    }
}

Matrix Activation::forward(const Matrix& input) {
    if (activation_type == "relu") {
        return input.relu();
    } else if (activation_type == "sigmoid") {
        return input.sigmoid();
    } else {
        throw std::invalid_argument("Invalid activation name");
    }
}