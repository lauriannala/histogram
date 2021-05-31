#include <iostream>
#include <memory>
#include <cassert>
#include <ctime>
#include "Histogram.h"
#include "RandomEintegerGenerator.h"

int main() {
    /** START Testing */
    auto histogram_test1 = new Histogram(std::make_unique<Logger>());
    histogram_test1->add(Hist::Zero);
    histogram_test1->add(Hist::One);
    histogram_test1->add(Hist::Two);
    histogram_test1->add(Hist::Two);
    histogram_test1->add(Hist::Two);
    histogram_test1->add(Hist::Two);
    histogram_test1->add(Hist::Three);
    histogram_test1->add(Hist::Three);
    histogram_test1->add(Hist::Four);

    assert(histogram_test1->getMinValue() == Hist::Zero);
    assert(histogram_test1->getMaxValue() == Hist::Four);
    assert(histogram_test1->getMode() == Hist::Two);

    auto histogram_test2 = new Histogram(std::make_unique<Logger>());
    histogram_test2->add(Hist::One);
    histogram_test2->add(Hist::Two);
    histogram_test2->add(Hist::Zero);
    histogram_test2->add(Hist::One);
    histogram_test2->add(Hist::Three);
    histogram_test2->add(Hist::Zero);
    assert(histogram_test2->getMode() == Hist::One);

    /** END Testing */

    /** START run using random generator */
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    auto histogram = new Histogram(std::make_unique<Logger>());
    auto gen_rand = RandomEintegerGenerator();

    for (int i = 0; i < 6; i++) {
        auto value = gen_rand();
        std::cout << "Add number: " << value << std::endl;
        histogram->add(value);
    }

    std::cout << "Min: " << histogram->getMinValue() << std::endl;
    std::cout << "Max: " << histogram->getMaxValue() << std::endl;
    std::cout << "Mode: " << histogram->getMode() << std::endl;
    /** END run using random generator */

    return 0;
}
