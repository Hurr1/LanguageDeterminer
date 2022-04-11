#include <iostream>
#include <fstream>
#include "../Header/Perceptron.h"
#include <map>
#include "../Header/Algorithm.h"
#include "filesystem"
#define ARGS_NUMBER argc-1


int main(int argc, char* argv[])
{
    double threshold,alpha;
    if(ARGS_NUMBER == 2)
    {
        threshold = std::stod(argv[1]) > 0.1 ? std::stod(argv[1]) : 5;
        alpha = std::stod(argv[2]) > 0.1 && std::stod(argv[2]) < 1.01 ? std::stod(argv[2]) : 0.3;
    }
    else
    {
        threshold = 5;
        alpha = 0.3;
    }

    std::string path = "Resources/";
    std::vector<Perceptron*> neuralNetwork;

    for (const auto &entry: std::filesystem::directory_iterator(path))
    {
        std::string prcpclass = entry.path();
        ai::removeWordFromLine(prcpclass, path);
        neuralNetwork.emplace_back(new Perceptron(prcpclass,threshold,alpha));

    }
    for(int i = 0;i<10;i++)
    {
        for (const auto &entry: std::filesystem::directory_iterator(path))
        {
            std::string language = entry.path();
            ai::removeWordFromLine(language, path);
            for (auto *perceptron: neuralNetwork)
            {
                for (const auto &entry: std::filesystem::directory_iterator(entry.path()))
                    perceptron->teach(entry.path(), language);
            }
        }
    }
    ai::testLanguage(neuralNetwork,"ToTest/Text");

    ai::userInput(neuralNetwork);


    for(Perceptron* perceptron : neuralNetwork)
        delete perceptron;
    neuralNetwork.clear();

}
