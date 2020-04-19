#ifndef MEDIAN_MEDIAN_H
#define MEDIAN_MEDIAN_H

#include <queue>

class MedianStructure {
private:
    std::priority_queue<double> lower_numbers;
    std::priority_queue<double, std::vector<double>, std::greater<double>> higher_numbers;

public:
    MedianStructure() = default;

    void addNumber(double num);
    auto lowerContainerSize() -> int;
    auto higherContainerSize() -> int;
    auto getMedian() -> double;
};

#endif //MEDIAN_MEDIAN_H
