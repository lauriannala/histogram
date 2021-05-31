#include <iostream>
#include <memory>
#include "Histogram.h"

int main() {
    auto histogram = new Histogram(std::make_unique<Logger>());
    std::cout << histogram->getMode() << std::endl;
    return 0;
}
