
#include <vector>
#include "Perceptron.h"

namespace ai
{
    double dotProduct(std::vector<double> &weights, std::vector<double> &inputs);

    void deltaAlgorithm(Perceptron *prc, std::vector<double> input, int d, int y, double dotProduct, double alpha);

    std::vector<double> multiply(std::vector<double> &&vector, double factor);

    std::vector<double> sumVectors(std::vector<double> &&first, std::vector<double> &&second);

    std::vector<double> normalizeVector(std::vector<double> &&toNormalize);

    std::vector<double> getVectorChar(std::string path);

    void testLanguage(std::vector<Perceptron*> &net, std::string path);

    void userInput(std::vector<Perceptron*> neuralNetwork);

    void removeWordFromLine(std::string &line, const std::string &word);
}