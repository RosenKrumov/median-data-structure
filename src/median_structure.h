#ifndef MEDIAN_MEDIAN_H
#define MEDIAN_MEDIAN_H

#include <queue>

class MedianStructure {
private:
    std::priority_queue<double> lower_numbers;
    std::priority_queue<double> higher_numbers;

public:
    MedianStructure();
    MedianStructure(std::priority_queue<double> lower,
            std::priority_queue<double> higher);
    MedianStructure(const MedianStructure& other);
    MedianStructure& operator=(const MedianStructure& other);
    MedianStructure(const MedianStructure&& other);
    MedianStructure& operator=(const MedianStructure&& other);
    ~MedianStructure();

    void addNumber(double num);
    double getMedian();

private:
    void synchronizeQueues();
};

#endif //MEDIAN_MEDIAN_H
