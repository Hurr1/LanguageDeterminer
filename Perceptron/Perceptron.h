#pragma once
#include <vector>
#include <string>

class Perceptron
{
private:
    void _teach(std::vector<double> input, int d, int y, double dotProduct, double alpha);
public:
    Perceptron(std::string prcpClass,double threshold, double alpha);
    ~Perceptron() = default;

    [[nodiscard]] double getThreshold() const;
    [[nodiscard]] double at(std::size_t index) const;
    [[nodiscard]] std::vector<double> getVector() const;
    [[nodiscard]] std::string getClass() const;

    void setThreshold(double threshold);
    void setVector(std::vector<double> &&vector);
    void teach(std::string path,const std::string &language);

private:
    double                          _threshold;
    std::string                     _class;
    std::vector<double>             _weights;
    double                          _alpha;
};
