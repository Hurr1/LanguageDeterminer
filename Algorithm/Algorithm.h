#include <vector>

namespace algs
{
    double dotProduct(std::vector<double> weights, std::vector<double> inputs);

    std::vector<double> multiply(std::vector<double> &&vector, double factor);

    std::vector<double> sumVectors(std::vector<double> &&first, std::vector<double> &&second);

    std::vector<double> normalizeVector(std::vector<double> &&toNormalize);

    std::vector<double> getVectorChar(std::string path);

    void removeWordFromLine(std::string &line, const std::string &word);
}