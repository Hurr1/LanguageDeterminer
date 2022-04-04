#include <iostream>
#include <fstream>
#include "../Header/Perceptron.h"
#include <map>
#include "../Header/Algorithm.h"
#include "filesystem"



int main()
{
    std::string path = "Resources/";
    std::vector<Perceptron*> neuralNetwork;

    for (const auto &entry: std::filesystem::directory_iterator(path))
    {
        std::string prcpclass = entry.path();
        ai::removeWordFromLine(prcpclass, path);
        neuralNetwork.emplace_back(new Perceptron(prcpclass));

    }
    for (const auto &entry: std::filesystem::directory_iterator(path))
    {
        std::string language = entry.path();
        ai::removeWordFromLine(language,path);
        for(int i = 0; i<5;i++)
        {
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
