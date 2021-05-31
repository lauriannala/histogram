//
// Created by lauri on 31/05/2021.
//

#ifndef HISTOGRAM_HISTOGRAM_H
#define HISTOGRAM_HISTOGRAM_H


#include <vector>
#include "HistogramBase.h"

class Histogram : Hist::HistogramBase {
public:
    explicit Histogram(std::unique_ptr<Logger>);
    explicit Histogram(const HistogramBase &);
    explicit Histogram(HistogramBase &&);
    void add(Hist::EInteger) override;
    [[nodiscard]] Hist::EInteger getMode() const override;
    [[nodiscard]] Hist::EInteger getMinValue() const override;
    [[nodiscard]] Hist::EInteger getMaxValue() const override;

private:
    std::vector<int> m_values;
};


#endif //HISTOGRAM_HISTOGRAM_H
