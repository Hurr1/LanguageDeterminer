#include "Nalgorithm.h"
#include <algorithm>
#include <vector>
#include "../Algorithm/Algorithm.h"
#include <iostream>
#include <iomanip>
#include <fstream>

void nalgs::testLanguage(std::vector<Perceptron *> &net, std::string path)
{
    std::vector<double> text = algs::getVectorChar(path);
    text = algs::normalizeVector(std::move(text));
    std::vector<std::pair<double,std::string>> answers;

    std::cout<<'\n'<<std::left<<std::setw(30)<<"Language"<<std::left<<std::setw(20)<<"DotProduct"<<"Threshold"<<'\n';
    for(const auto& prcp : net)
    {
        std::vector<double> weights = algs::normalizeVector(std::move(prcp->getVector()));
        double dot = algs::dotProduct(weights, text);
        std::cout<<std::setw(30)<< std::left << prcp->getClass()<<std::setw(20)<<dot<<prcp->getThreshold()<<'\n';
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
            std::vector<double> weights = algs::normalizeVector(std::move(prcp->getVector()));
            double dot = algs::dotProduct(weights, text);
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

void nalgs::userInput(std::vector<Perceptron*> neuralNetwork)
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
                nalgs::testLanguage(neuralNetwork, "ToTest/Input");
                break;
            }
            else
                myfile << text;
        }
        myfile.close();
    }


}
