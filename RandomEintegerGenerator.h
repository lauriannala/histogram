//
// Created by lauri on 31/05/2021.
//

#ifndef HISTOGRAM_RANDOMEINTEGERGENERATOR_H
#define HISTOGRAM_RANDOMEINTEGERGENERATOR_H


#include "HistogramBase.h"

class RandomEintegerGenerator : Hist::RandomEintegerGeneratorBase  {
public:
    Hist::EInteger operator()() override;
};


#endif //HISTOGRAM_RANDOMEINTEGERGENERATOR_H
