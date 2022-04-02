#pragma once

#include <vector>
#include <string>

class Perceptron
{
public:
    Perceptron(std::string prcpClass);
    ~Perceptron() = default;

    [[nodiscard]] double getThreshold() const;
    [[nodiscard]] double at(std::size_t index) const;
    [[nodiscard]] std::vector<double> getVector() const;

private:
    double                          _threshold;
    std::vector<double>             _weights;
    std::string                     _class;
};