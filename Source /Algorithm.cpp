#include <algorithm>
#include <complex>
#include <map>
#include <fstream>
#include <iostream>
#include "../Header/Algorithm.h"

double ai::dotProduct(std::vector<double> weights, std::vector<double> inputs)
{
    double dotProduct = 0;
    for(int i =0;i<weights.size();i++)
        dotProduct = dotProduct + (weights.at(i) * inputs.at(i));
    return dotProduct;
}

void ai::deltaAlgorithm(Perceptron* prc, std::vector<double>input,int d, int y, double dotProduct,double alpha)
{
    std::vector<double> res = {};
    std::vector<double> weights = prc->getVector();

    input.push_back(-1);
    weights.push_back(prc->getThreshold());

    input = ai::multiply(std::move(input),(d-y)*alpha);

    res = ai::sumVectors(std::move(weights), std::move(input));

    prc->setThreshold(res.at(res.size()-1));
    res.pop_back();

    prc->setVector(std::move(res));
}

std::vector<double> ai::normalizeVector(std::vector<double> &&toNormalize)
{
    double length;
    std::for_each(toNormalize.begin(),toNormalize.end(),[&length](double element){length += std::pow(element,2);});
    length = std::sqrt(length);

    std::for_each(toNormalize.begin(),toNormalize.end(),[length](double &element ){element /= length;});

    return toNormalize;
}

std::vector<double> ai::multiply(std::vector<double> &&vector,double factor)
{
    std::for_each(vector.begin(),vector.end(),[factor](double &value){value *= factor;});
    return vector;
}

std::vector<double> ai::sumVectors(std::vector<double>&& first,std::vector<double>&& second)
{
    std::transform (first.begin(), first.end(), second.begin(), first.begin(), std::plus<double>());
    return first;
}

std::vector<double> ai::getVectorChar(std::string path)
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

void ai::testLanguage(std::vector<Perceptron *> &net, std::string path)
{
    std::vector<double> text = ai::getVectorChar(path);
    text = ai::normalizeVector(std::move(text));
    std::vector<std::pair<double,std::string>> answers;


    for(const auto& prcp : net)
    {
        std::vector<double> weights = ai::normalizeVector(std::move(prcp->getVector()));
        double dot = ai::dotProduct(weights, text);
        std::cout<<prcp->getClass()<<"------"<<dot<<"--------"<<prcp->getThreshold()<<'\n';
        if(dot>prcp->getThreshold())
        {
            answers.emplace_back(std::pair<double, std::string>(dot, prcp->getClass()));
        }
    }

    if(!answers.empty())
    {
        std::sort(answers.begin(), answers.end(),
                  [](std::pair<double, std::string> _1, std::pair<double, std::string> _2) {
                      return _1.first > _2.first;
                  });
        std::cout << '\n' << "----------------------------------------------------------"
                  << '\n' << "Languge for text in file on path " << path << " is: " << answers.at(0).second
                  << '\n' << "----------------------------------------------------------" << '\n';
    }
    else
    {
        for(const auto& prcp : net)
        {
            std::vector<double> weights = ai::normalizeVector(std::move(prcp->getVector()));
            double dot = ai::dotProduct(weights, text);
            answers.emplace_back(std::pair<double, std::string>(dot, prcp->getClass()));
        }

        std::sort(answers.begin(), answers.end(),
                  [](std::pair<double, std::string> _1, std::pair<double, std::string> _2) {
                      return _1.first > _2.first;
                  });
        std::cout << '\n' << "----------------------------------------------------------"
                  << '\n' << "Languge for text in file on path " << path << " is probably: " << answers.at(0).second
                  << '\n' << "Please, give more information about this sentence"
                  << '\n' << "----------------------------------------------------------" << '\n';
    }
}

void ai::userInput(std::vector<Perceptron*> neuralNetwork)
{
    volatile bool mainLoop = true;
    volatile bool isListening = true;

    std::ofstream myfile;
    std::string text;

    while(mainLoop) {
        myfile.open ("ToTest/Input");
        std::cout << '\n' << "If you want to STOP input write down <STOPINPUT> <----(UpperCase)"
                  << '\n' << "If you want to define language for input, write down <DEFINE> <----(UpperCase)"
                  << '\n';

        while (isListening) {
            std::cin >> text;
            if (text.compare("STOPINPUT") == 0)
            {
                myfile.close();
                mainLoop = false;
                break;
            }
            else if (text.compare("DEFINE") == 0)
            {
                myfile.close();
                ai::testLanguage(neuralNetwork, "ToTest/Input");
                break;
            }
            else
                myfile << text;
        }
        myfile.close();
    }


}

void ai::removeWordFromLine(std::string &line, const std::string &word)
{
    auto n = line.find(word);
    if (n != std::string::npos)
    {
        line.erase(n, word.length());
    }
}