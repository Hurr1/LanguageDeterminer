#include <algorithm>
#include <complex>
#include <map>
#include <fstream>
#include <iostream>
#include "Algorithm.h"

double algs::dotProduct(std::vector<double> weights, std::vector<double> inputs)
{
    double dotProduct = 0;
    for(int i =0;i<weights.size();i++)
        dotProduct = dotProduct + (weights.at(i) * inputs.at(i));
    return dotProduct;
}

std::vector<double> algs::normalizeVector(std::vector<double> &&toNormalize)
{
    double length;
    std::for_each(toNormalize.begin(),toNormalize.end(),[&length](double element){length += std::pow(element,2);});
    length = std::sqrt(length);

    std::for_each(toNormalize.begin(),toNormalize.end(),[length](double &element ){element /= length;});

    return toNormalize;
}

std::vector<double> algs::multiply(std::vector<double> &&vector,double factor)
{
    std::for_each(vector.begin(),vector.end(),[factor](double &value){value *= factor;});
    return vector;
}

std::vector<double> algs::sumVectors(std::vector<double>&& first,std::vector<double>&& second)
{
    std::transform (first.begin(), first.end(), second.begin(), first.begin(), std::plus<double>());
    return first;
}

std::vector<double> algs::getVectorChar(std::string path)
{
    char ch;
    std::map<int,int> map;
    std::fstream fin(path, std::fstream::in);
    while (fin >> std::noskipws >> ch)
    {
        ch = static_cast<char>(tolower(ch));
        if(96 < ch && ch < 123)
            map[tolower(ch)]++;
    }
    std::vector<double> list(26,0);
    for(auto it = map.begin(); it != map.end(); ++it)
        list.at(it->first-1-96) += it->second;

    return list;
}

void algs::removeWordFromLine(std::string &line, const std::string &word)
{
    auto n = line.find(word);
    if (n != std::string::npos)
    {
        line.erase(n, word.length());
    }
}