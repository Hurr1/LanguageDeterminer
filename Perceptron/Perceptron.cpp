#include <iostream>
#include "Perceptron.h"
#include "../Algorithm/Algorithm.h"

double Perceptron::getThreshold() const
{
    return this->_threshold;
}

double Perceptron::at(std::size_t index) const
{
    return this->_weights.at(index);
}

Perceptron::Perceptron(std::string prcpClass,double threshold, double alpha)
{
    this->_class = prcpClass;
    this->_weights = std::vector<double>(26,(std::rand()%10)+1);
    this->_threshold = threshold;
    this->_alpha = alpha;
}

std::vector<double> Perceptron::getVector() const
{
    return this->_weights;
}

std::string Perceptron::getClass() const
{
    return this->_class;
}

void Perceptron::setThreshold(double threshold)
{
    this->_threshold = threshold;
}

void Perceptron::setVector(std::vector<double> &&vector)
{
    this->_weights = std::move(vector);
}

void Perceptron::teach(std::string path,const std::string &language)
{
    std::vector<double> input = algs::getVectorChar(path);
    input = algs::normalizeVector(std::move(input));
    this->_weights = algs::normalizeVector(std::move(_weights));

    double dotProduct = algs::dotProduct( this->_weights, input);

    int y = dotProduct >= this->_threshold ? 1 : 0;

    if((language.compare(this->_class)!=0 && y == 1) || (language.compare(this->_class)==0 && y == 0))
    {
        int d = y == 1? 0 : 1;
        this->_teach(input, d, y, dotProduct, this->_alpha);
    }
}

void Perceptron::_teach(std::vector<double> input, int d, int y, double dotProduct, double alpha)
{
    std::vector<double> res = {};
    std::vector<double> weights = this->getVector();

    input.push_back(-1);
    weights.push_back(this->getThreshold());

    input = algs::multiply(std::move(input),(d-y)*alpha);

    res = algs::sumVectors(std::move(weights), std::move(input));

    this->setThreshold(res.at(res.size()-1));
    res.pop_back();

    this->setVector(std::move(res));
}