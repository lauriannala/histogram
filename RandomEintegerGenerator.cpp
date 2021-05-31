//
// Created by lauri on 31/05/2021.
//

#include "RandomEintegerGenerator.h"

Hist::EInteger RandomEintegerGenerator::operator()() {
    int min = 0;
    int max = 4;
    int value = min + rand() % static_cast<int>(max - min + 1);
    return static_cast<Hist::EInteger>(value);
}
