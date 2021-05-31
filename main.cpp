#include <iostream>
#include <memory>
#include <cassert>
#include "Histogram.h"

int main() {
    auto histogram = new Histogram(std::make_unique<Logger>());
    histogram->add(Hist::Zero);
    histogram->add(Hist::One);
    histogram->add(Hist::Two);
    histogram->add(Hist::Two);
    histogram->add(Hist::Two);
    histogram->add(Hist::Two);
    histogram->add(Hist::Three);
    histogram->add(Hist::Three);
    histogram->add(Hist::Four);

    assert(histogram->getMinValue() == Hist::Zero);
    assert(histogram->getMaxValue() == Hist::Four);
    assert(histogram->getMode() == Hist::Two);

    return 0;
}
