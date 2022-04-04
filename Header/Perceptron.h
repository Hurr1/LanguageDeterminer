#pragma once

#include <vector>
#include <string>

class Perceptron
{
public:
    explicit Perceptron(std::string prcpClass);
    ~Perceptron() = default;

    [[nodiscard]] double getThreshold() const;
    [[nodiscard]] double at(std::size_t index) const;
    [[nodiscard]] std::vector<double> getVector() const;

    void setThreshold(double threshold);
    void setVector(std::vector<double> &&vector);
    void teach(std::string path,const std::string &language);

    std::string getClass();

private:
    double                          _threshold;
    std::string                     _class;
    std::vector<double>             _weights;
    double                          _alpha;
};