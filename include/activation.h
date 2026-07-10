#pragma once
#include "layer.h"
#include <string>
#include <stdexcept>

class Activation : public Layer {
private:
    std::string activation_type;

public:
    Activation(const std::string& type);

    Matrix forward(const Matrix& input) override;
};