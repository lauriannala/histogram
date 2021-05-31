//
// Created by lauri on 31/05/2021.
//

#include <iostream>
#include "Histogram.h"

Hist::EInteger Histogram::getMode() const {
    return Hist::Two;
}

Hist::EInteger Histogram::getMinValue() const {
    return Hist::Two;
}

Hist::EInteger Histogram::getMaxValue() const {
    return Hist::Two;
}

void Histogram::add(Hist::EInteger) {

}

Histogram::Histogram(Hist::HistogramBase && base) : HistogramBase(base) {}

Histogram::Histogram(const Hist::HistogramBase & base) : HistogramBase(base) {}

Histogram::Histogram(std::unique_ptr<Logger> logger) : HistogramBase(std::move(logger)) {}

Hist::HistogramBase::~HistogramBase() = default;

Hist::HistogramBase::HistogramBase(Hist::HistogramBase &&) {}

Hist::HistogramBase::HistogramBase(const Hist::HistogramBase &) {}

Hist::HistogramBase::HistogramBase(std::unique_ptr<Logger>) {}
