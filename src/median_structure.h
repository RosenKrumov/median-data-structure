#ifndef MEDIAN_MEDIAN_H
#define MEDIAN_MEDIAN_H

#include <queue>

class MedianStructure {
private:
    std::priority_queue<double> lower_numbers;
    std::priority_queue<double, std::vector<double>, std::greater<double>> higher_numbers;

public:
    MedianStructure() = default;
    MedianStructure(std::priority_queue<double> lower,
            std::priority_queue<double, std::vector<double>, std::greater<double>> higher);

    void addNumber(double num);
    auto getMedian() -> double;

private:
    void synchronizeQueues();
};

#endif //MEDIAN_MEDIAN_H
