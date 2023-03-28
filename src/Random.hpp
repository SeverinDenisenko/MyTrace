//
// Created by Severin on 28.03.2023.
//

#ifndef MYTRACE_RANDOM_HPP
#define MYTRACE_RANDOM_HPP

#include <random>

class Random {
public:
    Random();

    double Get();
private:
    std::uniform_real_distribution<double> distribution;
    std::mt19937 generator;
};


#endif //MYTRACE_RANDOM_HPP
