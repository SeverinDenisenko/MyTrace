//
// Created by Severin on 28.03.2023.
//

#include "Random.hpp"

Random::Random() : distribution(0.0, 1.0), generator(){

}

double Random::Get() {
    return distribution(generator);
}
