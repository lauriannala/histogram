//
// Created by lauri on 31/05/2021.
//

#include <iostream>
#include <algorithm>
#include "Histogram.h"

Hist::EInteger Histogram::getMode() const {
    auto values_clone = m_values;
    std::sort(values_clone.begin(), values_clone.end());

    auto mode = values_clone[0];
    int occurrence = 1;
    int max_occurrence = 1;

    for(int i = 1; i < values_clone.size(); i++)
    {
        if (m_values[i] > m_values[i-1]) {
            occurrence = 1;
        } else {
            occurrence++;
        }

        if(occurrence >= max_occurrence)
        {
            max_occurrence = occurrence;
            mode = values_clone[i];
        }
    }

    return static_cast<Hist::EInteger>(mode);
}

Hist::EInteger Histogram::getMinValue() const {
    auto min = std::min_element(m_values.begin(), m_values.end());
    return (Hist::EInteger) *min;
}

Hist::EInteger Histogram::getMaxValue() const {
    auto max = std::max_element(m_values.begin(), m_values.end());
    return (Hist::EInteger) *max;
}

void Histogram::add(Hist::EInteger value) {
    m_values.push_back(value);
}

Histogram::Histogram(Hist::HistogramBase && base) : HistogramBase(base) {}

Histogram::Histogram(const Hist::HistogramBase & base) : HistogramBase(base) {}

Histogram::Histogram(std::unique_ptr<Logger> logger) : HistogramBase(std::move(logger)) {}

Hist::HistogramBase::~HistogramBase() = default;

Hist::HistogramBase::HistogramBase(Hist::HistogramBase &&) {}

Hist::HistogramBase::HistogramBase(const Hist::HistogramBase &) {}

Hist::HistogramBase::HistogramBase(std::unique_ptr<Logger>) {}
