//
// Created by hurr1cane on 4/2/22.
//

#include <iostream>
#include "../Header/Perceptron.h"

double Perceptron::getThreshold() const
{
    return this->_threshold;
}

double Perceptron::at(std::size_t index) const
{
    return this->_weights.at(index);
}

Perceptron::Perceptron(std::string prcpClass)
{
    this->_class = prcpClass;
    this->_weights = std::vector<double>(26,1);
    this->_threshold = 1;
}

std::vector<double> Perceptron::getVector() const {
    return this->_weights;
}
