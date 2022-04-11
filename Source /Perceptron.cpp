#include <iostream>
#include "../Header/Perceptron.h"
#include "../Header/Algorithm.h"

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
    std::vector<double> input = ai::getVectorChar(path);
    input = ai::normalizeVector(std::move(input));
    this->_weights = ai::normalizeVector(std::move(_weights));

    double dotProduct = ai::dotProduct( this->_weights, input);

    int y = dotProduct >= this->_threshold ? 1 : 0;

    if((language.compare(this->_class)!=0 && y == 1) || (language.compare(this->_class)==0 && y == 0))
    {
        int d = y == 1? 0 : 1;
        ai::deltaAlgorithm(this, input, d, y, dotProduct, this->_alpha);
    }
}

std::string Perceptron::getClass()
{
    return this->_class;
}