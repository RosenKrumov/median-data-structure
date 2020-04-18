#include "median_structure.h"

MedianStructure::MedianStructure() : current_median(0) {}

MedianStructure::MedianStructure(std::priority_queue<double> lower, std::priority_queue<double> higher) :
        lower_numbers(lower), higher_numbers(higher), current_median(0) {
    SynchronizeQueues():
}

MedianStructure::MedianStructure(const MedianStructure& other) {

}

MedianStructure& MedianStructure::operator=(const MedianStructure& other) {

}

MedianStructure::MedianStructure(const MedianStructure&& other) {

}

MedianStructure& MedianStructure::operator=(const MedianStructure&& other) {

}

MedianStructure::~MedianStructure() {

}

void MedianStructure::addNumber(double num) {
    if (lower_numbers.empty() && higher_numbers.empty()) {
        // first time, push in lower
        lower_numbers.push(num);
    } else if (num < getMedian()) {
        // push lower-than-median numbers in lower container
        lower_numbers.push(num);
        // keep sizes consistent
        synchronizeQueues();
    } else if (num > getMedian()) {
        // push higher-than-median numbers in higher container
        higher_numbers.push(num);
        // keep sizes consistent
        synchronizeQueues();
    } else if (num == getMedian()) {
        // if num is equal to median, push to smaller container, otherwise lower
        if (lower_numbers.size() <= higher_numbers.size()) {
            lower_numbers.push(num);
        } else if (lower_numbers.size() > higher_numbers.size()) {
            higher_numbers.push(num);
        }
    }
}

double MedianStructure::getMedian() {
    // median is the top of the bigger container, otherwise the mean of both
    if (lower_numbers.size() > higher_numbers.size()) {
        return lower_numbers.top();
    } else if (lower_numbers.size() < higher_numbers.size()) {
        return higher_numbers.top();
    } else {
        return (lower_numbers.top() + higher_numbers.top()) / 2;
    }
}

void MedianStructure::synchronizeQueues() {
    if (lower_numbers.size() > higher_numbers.size() + 1) {
        // when the queues are passed to the constructor,
        // they can be totally inconsistent in terms of sizes
        while(lower_numbers.size() > higher_numbers.size() + 1) {
            higher_numbers.push(lower_numbers.top());
            lower_numbers.pop();
        }
    } else if (higher_numbers.size() > lower_numbers.size() + 1) {
        while(higher_numbers.size() > lower_numbers.size() + 1) {
            lower_numbers.push(higher_numbers.top());
            higher_numbers.pop();
        }
    }
}